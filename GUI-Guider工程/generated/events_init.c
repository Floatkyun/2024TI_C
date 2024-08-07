/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_ddlist_wave_form_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		uint16_t id = lv_dropdown_get_selected(guider_ui.screen_ddlist_wave_form);
		switch(id) {
		case 0:
		{
			lv_obj_clear_flag(guider_ui.screen_cont_cw, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		case 1:
		{
			lv_obj_add_flag(guider_ui.screen_cont_cw, LV_OBJ_FLAG_HIDDEN);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
static void screen_btn_start_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_img_TI, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_debug_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_LONG_PRESSED:
	{
		lv_obj_clear_flag(guider_ui.screen_cont_debug, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_chart0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_btn_chart0, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_chart1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_btn_chart1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_debug_apply_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_cont_debug, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_slider_debug100_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_label_PHASE_TEMP, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_slider_debug_10000_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_label_PHASE_TEMP, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_ddlist_wave_form, screen_ddlist_wave_form_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_start, screen_btn_start_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_debug, screen_btn_debug_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_chart0, screen_btn_chart0_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_chart1, screen_btn_chart1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_debug_apply, screen_btn_debug_apply_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_slider_debug100, screen_slider_debug100_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_slider_debug_10000, screen_slider_debug_10000_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
