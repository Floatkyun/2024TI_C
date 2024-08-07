/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include <time.h>
#include <errno.h>
#include "freemaster_client.h"

#if LV_USE_FREEMASTER
#include "external_data_init.h"
CURL *ws_connect;
lv_obj_t * gg_msgbox = NULL;
extern pthread_mutex_t lvgl_mutex;

void connect_init()
{
    ws_connect = websocket_connect(FREEMASTER_SERVER);
    return;
}

bool equal_to_double_max(double a)
{
    return abs(DBL_MAX - fabs(a)) < 0.000001;
}

void freeMasterParse(void *param)
{
    char result[20];
    if (strcmp(((readVariableParm *)param)->apiName, "ReadVariable") == 0)
    {
        readVariableParm *user_parm = param;
        double dataArray[user_parm->arrayLen];
        read_variable(user_parm->varArray, user_parm->arrayLen, dataArray);
        /* use timedlock to avoid dead loop when there is screen transition event*/
        struct timespec timeout = { 0, LV_DISP_DEF_REFR_PERIOD * 1000 * 1000 };
        int err = pthread_mutex_timedlock(&lvgl_mutex, &timeout);
        if (0 != err) return;
        /* display the extern data according to widget type. */
        switch (user_parm->widget_type)
        {
        case GG_LABEL:
        {
            if (equal_to_double_max(dataArray[0])) break;
            if (strcmp(user_parm->varArray[0].varType, "Fixed point number") == 0) {
                //itoa(dataArray[0], result, 10);
                sprintf(result, "%d", (int)dataArray[0]);
            } else if (strcmp(user_parm->varArray[0].varType, "IEEE floating point") == 0) {
                sprintf(result, "%.2lf", (double)dataArray[0]);
            } else {
                break;
            }
            lv_label_set_text(user_parm->parentObj, result);
            break;
        }
        case GG_CHART:
        {
            lv_chart_series_t *childObj = NULL;
            for (int i = 0; i < user_parm->arrayLen; i++) {
                if (equal_to_double_max(dataArray[i])) continue;
                childObj = (user_parm->childObjArray)[i];
                lv_chart_set_next_value(user_parm->parentObj, childObj, (int)dataArray[i]);
            }
            lv_chart_refresh(user_parm->parentObj);
            break;
        }
        case GG_BAR:
        {
            if (equal_to_double_max(dataArray[0])) break;
            lv_bar_set_value(user_parm->parentObj, (int)dataArray[0], LV_ANIM_OFF);
            break;
        }
        case GG_METER:
        {
            lv_meter_indicator_t *childObj = NULL;
            for (int i = 0; i < user_parm->arrayLen; i++) {
                if (equal_to_double_max(dataArray[i])) continue;
                childObj = (user_parm->childObjArray)[i];
                lv_meter_set_indicator_value(user_parm->parentObj, childObj, (int)dataArray[i]);
            }
            break;
        }
        case GG_ARC:
        {
            if (equal_to_double_max(dataArray[0])) break;
            lv_arc_set_value(user_parm->parentObj, (int)dataArray[0]);
            break;
        }
        case GG_SLIDER:
        {
            if (equal_to_double_max(dataArray[0])) break;
            lv_slider_set_value(user_parm->parentObj, (int)dataArray[0], LV_ANIM_OFF);
            break;
        }
        case GG_SWITCH:
        {
            if (equal_to_double_max(dataArray[0])) break;
            if((int)dataArray[0] == 0 && lv_obj_has_state(user_parm->parentObj, LV_STATE_CHECKED)) {
                lv_obj_clear_state(user_parm->parentObj, LV_STATE_CHECKED);
            }
            if((int)dataArray[0] == 1 && !lv_obj_has_state(user_parm->parentObj, LV_STATE_CHECKED)) {
                lv_obj_add_state(user_parm->parentObj, LV_STATE_CHECKED);
            }
            break;
        }
        default:
            break;
        }
        pthread_mutex_unlock(&lvgl_mutex);
    }
    return;
}

void message_display(char *message)
{
  if(gg_msgbox == NULL || !lv_obj_is_valid(gg_msgbox)) {
    static const char * btns[] = {""};
    gg_msgbox = lv_msgbox_create(lv_layer_top(), "Error", message, btns, true);
    lv_obj_center(gg_msgbox);
  }
}

json_t * callAPI(char *params, char* method_name)
{
    char request_data[500];
    json_error_t error;
    json_t *json_obj;

    /* try to connect*/
    if (ws_connect == NULL) {
        connect_init();
    }
    if (ws_connect == NULL) {
        message_display("websocket connect failed.");
        return NULL;
    }

    /* format the request data */
    snprintf(request_data, 500, "\"method\": \"%s\", \"params\": [%s]", method_name, params);
    /* get the json data from FreeMaster server JSONRPC with websocket.*/
    char * origin_response = websocket_request(ws_connect, request_data);
    if (origin_response == NULL)
    {
        fprintf(stderr, "No data returned from jsonrpc server.\n");
        message_display("No data returned from jsonrpc server.\n");
        return NULL;
    }

    #ifdef DEBUG
    fprintf(stdout, "Decoding json: %s\n", origin_response);
    #endif

    json_obj = json_loads(origin_response, 0, &error);
    free(origin_response);
    if (json_obj == NULL)
    {
        fprintf(stderr, "Failed to decode json: %s\n", error.text);
        return NULL;
    }
    return json_obj;
}

void read_variable(fm_var * varArray, int arrayLen, double* dataArray) {
    json_t *result_json;
    char rpcParams[50];
    for (int i = 0; i < arrayLen; i++)
    {
        char *variable_name = varArray[i].varName;
        snprintf(rpcParams, 50, "\"%s\"", variable_name);
        result_json = callAPI(rpcParams, "ReadVariable");
        if (result_json == NULL) {
            dataArray[i] = DBL_MAX;
            continue;
        }
        int success = 0, retval = 0, errorCode = 0;
        double data = DBL_MAX;
        char *id, *dataFormatted, *errorMessage;
        json_error_t error;
        int res = json_unpack_ex(result_json, &error, 0, "{s:s, s:{s:b, s?F, s:{s:b, s?:s}, s?{s:i, s:s}}}",
            "id", &id, "result", "success", &success, "data", &data,
            "xtra", "retval", &retval, "formatted", &dataFormatted,
            "error", "code", &errorCode, "msg", &errorMessage);
        if (res == -1) {
            fprintf(stderr, "Failed to parse json: %s\n", error.text);
        }

        if (!success) {
            fprintf(stderr, "%s\n", errorMessage);
            message_display(errorMessage);
            continue;
        }
        if (strcmp(varArray[i].varType, "Fixed point number") == 0) {
            dataArray[i] = (double)atoi(dataFormatted);
        } else if (strcmp(varArray[i].varType, "IEEE floating point") == 0) {
            dataArray[i] = (double)data;
        }
        json_decref(result_json);
    }
}

void write_variable(char *varName, int value) {
    json_t *result_json;
    char rpcParams[50];
    snprintf(rpcParams, 50, "\"%s\", %d", varName, value);
    callAPI(rpcParams, "WriteVariable");
    return;
}
#endif
