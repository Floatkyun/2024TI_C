/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "connect_utils.h"
#include "freemaster_client.h"

#define BUFFER_SIZE 128*1024
#define RECV_RETRY_COUNT 40
#define RECV_RETRY_INTERVAL 25 /*ns*/

#if LV_USE_FREEMASTER
extern pthread_mutex_t jsonrpc_mutex;

/*define the result struct.*/
struct write_result {
  char *data;
  int pos;
};

/* show websocket error message*/
void websocket_error(CURLcode res, char *message)
{
  size_t len = 0;
  if (message != NULL) len = strlen(message);
  fprintf(stderr, "FreeMASTER: (%d) ", res);
  if(len) {
    fprintf(stderr, "%s%s", message,
            ((message[len - 1] != '\n') ? "\n" : ""));
  } else {
    fprintf(stderr, "%s\n", curl_easy_strerror(res));
  }
}

/* init and connect the websocket instance*/
CURL * websocket_connect(const char *ws_url)
{
  CURL *ws_curl;
  CURLcode res;
  #ifdef DEBUG
  fprintf(stdout, "\nInit curl connection to %s\n", ws_url);
  #endif
  ws_curl = curl_easy_init();
  if (ws_curl == NULL)
  {
    fprintf(stderr, "ERROR: Failed to start a curl session.\n");
    message_display("ERROR: Failed to start a curl session.\n");
    return NULL;
  }
  /*set the ws link address`*/
  curl_easy_setopt(ws_curl, CURLOPT_URL, ws_url);
  /*set the websocket option: stop when connected to target server*/
  curl_easy_setopt(ws_curl, CURLOPT_CONNECT_ONLY, 2L);
  /* Perform the request, res will get the return code */
  res = curl_easy_perform(ws_curl);
  if (res != CURLE_OK)
  {
    websocket_error(res, NULL);
    curl_easy_cleanup(ws_curl);
    return NULL;
  }
  return ws_curl;
}


/* close the connection */
void websocket_close(CURL *ws_curl)
{
  size_t sent;
  (void)curl_ws_send(ws_curl, "", 0, &sent, 0, CURLWS_CLOSE);
  /* always cleanup */
  curl_easy_cleanup(ws_curl);
  return;
}

/*send and got the receive*/
char *websocket_request(CURL *ws_curl, char *params)
{
  static uint32_t id = 1;
  const struct curl_ws_frame *meta;
  size_t send, rlen;
  char recv_buffer[BUFFER_SIZE];
  CURLcode res;
  if (ws_curl == NULL)
  {
    websocket_error(CURLE_COULDNT_CONNECT, NULL);
    connect_init();
    return NULL;
  }
  pthread_mutex_lock(&jsonrpc_mutex);
  char request_head[50];
  snprintf(request_head, 50, "\"jsonrpc\":\"2.0\",\"id\":\"%d\"", id);
  char request_data[500];
  snprintf(request_data, 500, "{%s, %s}", request_head, params);
  id++;
  if (id == UINT_MAX) {
    id = 1;
  }
  pthread_mutex_unlock(&jsonrpc_mutex);
  #ifdef DEBUG
  fprintf(stdout, "Sending request: %s\n", request_data);
  #endif
  res = curl_ws_send(ws_curl, request_data, strlen(request_data), &send, 0, CURLWS_TEXT);
  if (res != CURLE_OK)
  {
    websocket_error(res, NULL);
    curl_easy_cleanup(ws_curl);
    connect_init();
    return NULL;
  }
  /* retry until ws server is ready*/
  bool timeout = false;
  int count = 1;
  while (count < RECV_RETRY_COUNT) {
    #ifdef DEBUG
    fprintf(stdout, "Receiving response, try %d times.\n", count);
    #endif
    res = curl_ws_recv(ws_curl, recv_buffer, sizeof(recv_buffer), &rlen, &meta);
    if (res == CURLE_OK) {
      /*receive successfully*/
      if (strstr(recv_buffer, request_head) != NULL) {
        /*jsonrpc response has correct head*/
        break;
      }
    } else if (res != CURLE_AGAIN) {
      /*an error occurred, but no signal to retry again*/
      break;
    }
    gg_nanosleep(RECV_RETRY_INTERVAL);
    count++;
    if (count == RECV_RETRY_COUNT) timeout = true;
  };
  /*an error occurred, no data*/
  if (res != CURLE_OK)
  {
    websocket_error(res, NULL);
    if (res != CURLE_AGAIN)
    {
      curl_easy_cleanup(ws_curl);
      connect_init();
    }
    return NULL;
  }
  /*timeout, no data*/
  if (timeout) return NULL;

  char *data = malloc(BUFFER_SIZE);
  if (data == NULL)
  {
    fprintf(stderr, "\nERROR: Failed to alloc memory.\n");
    return NULL;
  }
  //memset(data, 0, BUFFER_SIZE);
  strncpy(data, recv_buffer, rlen);
  data[rlen] = '\0';
  return data;
}

/* Define the function how to write http response.*/
static size_t write_response(void *ptr, size_t size, size_t nmemb, void *stream) {
    struct write_result *result = (struct write_result *)stream;
    if (result->pos + size * nmemb >= BUFFER_SIZE - 1) {
        fprintf(stderr, "error: too small buffer\n");
        return 0;
    }
    memcpy(result->data + result->pos, ptr, size * nmemb);
    result->pos += size * nmemb;
    return size * nmemb;
}

char *http_request(const char *url, const char *params)
{
  long code;
  char *data = NULL;
  struct curl_slist *headers = NULL;
  CURL *http_curl = NULL;
  CURLcode res_code;
  /*init the curl request instance.*/
  curl_global_init(CURL_GLOBAL_ALL);
  http_curl = curl_easy_init();
  if(http_curl){
    data = malloc(BUFFER_SIZE);
    struct write_result write_result = {.data = data, .pos = 0};
    /* define the http request headers */
    headers = curl_slist_append(headers, "content-type: application/json;");
    /*define the type of the http request.*/
    curl_easy_setopt(http_curl, CURLOPT_POST, 1);
    /*define the URL to visit.*/
    curl_easy_setopt(http_curl, CURLOPT_URL, url);
    /*define the request header.*/
    curl_easy_setopt(http_curl, CURLOPT_HTTPHEADER, headers);
    /*set the http post data.*/
    curl_easy_setopt(http_curl, CURLOPT_POSTFIELDS, params);
    curl_easy_setopt(http_curl, CURLOPT_POSTFIELDSIZE, (long)strlen(params));
    /*use the defined function to save the return data.*/
    curl_easy_setopt(http_curl, CURLOPT_WRITEFUNCTION, write_response);
    /*define the write result data.*/
    curl_easy_setopt(http_curl, CURLOPT_WRITEDATA, &write_result);

    /* Perform the request, res will get the return code */
    res_code = curl_easy_perform(http_curl);
    if(res_code) {
      fprintf(stderr, "error: unable to request data from %s:\n", url);
    }

    /* check the http response status code. */
    curl_easy_getinfo(http_curl, CURLINFO_RESPONSE_CODE, &code);
    if(res_code != 200){
      fprintf(stderr, "error: server responded with code %ld\n", code);
    }

    /* close the http request and free the http_curl.*/
    curl_easy_cleanup(http_curl);
    curl_slist_free_all(headers);
    curl_global_cleanup();

    /* zero-terminate the result */
    data[write_result.pos] = '\0';
    return data;
  }
  return 0;
}
#endif
