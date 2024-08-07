/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x00ffd2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen, lv_color_hex(0xa3d3fb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_wave
	ui->screen_cont_wave = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_wave, 10, 100);
	lv_obj_set_size(ui->screen_cont_wave, 385, 370);
	lv_obj_set_scrollbar_mode(ui->screen_cont_wave, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_wave, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_wave, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_wave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_wave, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_wave, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_wave, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_wave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_wave, lv_color_hex(0x00FFD2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_wave, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_cont_wave, lv_color_hex(0xA3D3FB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_cont_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_cont_wave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_wave, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_cont_wave, lv_color_hex(0x64686b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_cont_wave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_cont_wave, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_cont_wave, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_cont_wave, 3, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen_cont_wave);
	lv_label_set_text(ui->screen_label_2, "波形发生设置");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_2, 110, 10);
	lv_obj_set_size(ui->screen_label_2, 165, 32);

	//Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_2, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ddlist_wave_form
	ui->screen_ddlist_wave_form = lv_dropdown_create(ui->screen_cont_wave);
	lv_dropdown_set_options(ui->screen_ddlist_wave_form, "CW信号\nAM信号");
	lv_obj_set_pos(ui->screen_ddlist_wave_form, 191, 58);
	lv_obj_set_size(ui->screen_ddlist_wave_form, 130, 32);

	//Write style for screen_ddlist_wave_form, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ddlist_wave_form, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ddlist_wave_form, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_ddlist_wave_form, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ddlist_wave_form, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ddlist_wave_form, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ddlist_wave_form, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ddlist_wave_form, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ddlist_wave_form, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ddlist_wave_form, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ddlist_wave_form, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ddlist_wave_form, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_wave_form, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ddlist_wave_form, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_wave_form, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_wave_form, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_ddlist_wave_form_extra_list_selected_checked
	static lv_style_t style_screen_ddlist_wave_form_extra_list_selected_checked;
	ui_init_style(&style_screen_ddlist_wave_form_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_ddlist_wave_form_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_ddlist_wave_form_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_ddlist_wave_form_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_ddlist_wave_form_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_wave_form_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_wave_form_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_ddlist_wave_form_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_wave_form_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_wave_form), &style_screen_ddlist_wave_form_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_wave_form_extra_list_main_default
	static lv_style_t style_screen_ddlist_wave_form_extra_list_main_default;
	ui_init_style(&style_screen_ddlist_wave_form_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_ddlist_wave_form_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_ddlist_wave_form_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_ddlist_wave_form_extra_list_main_default, &lv_font_MI_LanTing_Regular_12);
	lv_style_set_text_opa(&style_screen_ddlist_wave_form_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_ddlist_wave_form_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_ddlist_wave_form_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_wave_form_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_ddlist_wave_form_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_wave_form_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_wave_form_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_ddlist_wave_form_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_wave_form_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_wave_form), &style_screen_ddlist_wave_form_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_wave_form_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist_wave_form_extra_list_scrollbar_default;
	ui_init_style(&style_screen_ddlist_wave_form_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_ddlist_wave_form_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_wave_form_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_ddlist_wave_form_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_wave_form_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_wave_form), &style_screen_ddlist_wave_form_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen_cont_wave);
	lv_label_set_text(ui->screen_label_3, "调制");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_3, 52, 60);
	lv_obj_set_size(ui->screen_label_3, 100, 32);

	//Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_3, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_roller_am_amp
	ui->screen_roller_am_amp = lv_roller_create(ui->screen_cont_wave);
	lv_roller_set_options(ui->screen_roller_am_amp, "100mVrms\n200mVrms\n300mVrms\n400mVrms\n500mVrms\n600mVrms\n700mVrms\n800mVrms\n900mVrms\n1Vrms", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_am_amp, 10, 160);
	lv_obj_set_width(ui->screen_roller_am_amp, 120);

	//Write style for screen_roller_am_amp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_am_amp, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_am_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_amp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_amp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_amp, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_amp, &lv_font_MI_LanTing_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_amp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_am_amp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_am_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_am_amp, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_am_amp, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_am_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_am_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_am_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_am_amp, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_am_amp, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_amp, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_amp, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_amp, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_amp, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_amp, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_amp, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_am_amp, 5);
	//Write codes screen_label_4
	ui->screen_label_4 = lv_label_create(ui->screen_cont_wave);
	lv_label_set_text(ui->screen_label_4, "幅度");
	lv_label_set_long_mode(ui->screen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_4, 10, 115);
	lv_obj_set_size(ui->screen_label_4, 120, 32);

	//Write style for screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_4, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_4, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_5
	ui->screen_label_5 = lv_label_create(ui->screen_cont_wave);
	lv_label_set_text(ui->screen_label_5, "调制度");
	lv_label_set_long_mode(ui->screen_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_5, 137, 115);
	lv_obj_set_size(ui->screen_label_5, 110, 32);

	//Write style for screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_5, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_5, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_6
	ui->screen_label_6 = lv_label_create(ui->screen_cont_wave);
	lv_label_set_text(ui->screen_label_6, "载波频率");
	lv_label_set_long_mode(ui->screen_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_6, 255, 115);
	lv_obj_set_size(ui->screen_label_6, 120, 32);

	//Write style for screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_6, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_6, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_roller_am_ma
	ui->screen_roller_am_ma = lv_roller_create(ui->screen_cont_wave);
	lv_roller_set_options(ui->screen_roller_am_ma, "10%\n20%\n30%\n40%\n50%\n60%\n70%\n80%\n90%", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_am_ma, 137, 159);
	lv_obj_set_width(ui->screen_roller_am_ma, 110);

	//Write style for screen_roller_am_ma, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_am_ma, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_am_ma, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_ma, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_ma, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_ma, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_ma, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_ma, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_ma, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_am_ma, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_am_ma, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_am_ma, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_am_ma, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_am_ma, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_am_ma, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_am_ma, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_am_ma, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_am_ma, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_ma, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_ma, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_ma, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_ma, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_ma, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_ma, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_am_ma, 5);
	//Write codes screen_roller_am_fc
	ui->screen_roller_am_fc = lv_roller_create(ui->screen_cont_wave);
	lv_roller_set_options(ui->screen_roller_am_fc, "30MHz\n31MHz\n32MHz\n33MHz\n34MHz\n35MHz\n36MHz\n37MHz\n38MHz\n39MHz\n40MHz", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_am_fc, 255, 160);
	lv_obj_set_width(ui->screen_roller_am_fc, 120);

	//Write style for screen_roller_am_fc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_am_fc, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_am_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_fc, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_fc, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_fc, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_fc, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_fc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_am_fc, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_am_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_am_fc, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_am_fc, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_am_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_am_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_am_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_am_fc, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_am_fc, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_am_fc, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_am_fc, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_am_fc, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_am_fc, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_am_fc, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_am_fc, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_am_fc, 5);
	//Write codes screen_cont_cw
	ui->screen_cont_cw = lv_obj_create(ui->screen_cont_wave);
	lv_obj_set_pos(ui->screen_cont_cw, 2, 105);
	lv_obj_set_size(ui->screen_cont_cw, 379, 225);
	lv_obj_set_scrollbar_mode(ui->screen_cont_cw, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_cw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_cw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_cw, lv_color_hex(0x00FFD2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_cw, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_cont_cw, lv_color_hex(0xA3D3FB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_cont_cw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_cw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_roller_cw_amp
	ui->screen_roller_cw_amp = lv_roller_create(ui->screen_cont_cw);
	lv_roller_set_options(ui->screen_roller_cw_amp, "100mVrms\n200mVrms\n300mVrms\n400mVrms\n500mVrms\n600mVrms\n700mVrms\n800mVrms\n900mVrms\n1Vrms", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_cw_amp, 57, 60);
	lv_obj_set_width(ui->screen_roller_cw_amp, 120);

	//Write style for screen_roller_cw_amp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_cw_amp, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_cw_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_cw_amp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_cw_amp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_cw_amp, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_cw_amp, &lv_font_MI_LanTing_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_cw_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_cw_amp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_cw_amp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_cw_amp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_cw_amp, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_cw_amp, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_cw_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_cw_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_cw_amp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_cw_amp, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_cw_amp, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_cw_amp, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_cw_amp, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_cw_amp, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_cw_amp, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_cw_amp, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_cw_amp, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_cw_amp, 5);
	//Write codes screen_roller_cw_fc
	ui->screen_roller_cw_fc = lv_roller_create(ui->screen_cont_cw);
	lv_roller_set_options(ui->screen_roller_cw_fc, "30MHz\n31MHz\n32MHz\n33MHz\n34MHz\n35MHz\n36MHz\n37MHz\n38MHz\n39MHz\n40MHz", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_cw_fc, 206, 60);
	lv_obj_set_width(ui->screen_roller_cw_fc, 120);

	//Write style for screen_roller_cw_fc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_cw_fc, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_cw_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_cw_fc, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_cw_fc, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_cw_fc, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_cw_fc, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_cw_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_cw_fc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_cw_fc, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_cw_fc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_cw_fc, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_cw_fc, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_cw_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_cw_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_cw_fc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_cw_fc, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_cw_fc, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_cw_fc, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_cw_fc, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_cw_fc, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_cw_fc, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_cw_fc, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_cw_fc, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_cw_fc, 5);
	//Write codes screen_label_9
	ui->screen_label_9 = lv_label_create(ui->screen_cont_cw);
	lv_label_set_text(ui->screen_label_9, "频率");
	lv_label_set_long_mode(ui->screen_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_9, 207, 10);
	lv_obj_set_size(ui->screen_label_9, 120, 32);

	//Write style for screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_9, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_9, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_7
	ui->screen_label_7 = lv_label_create(ui->screen_cont_cw);
	lv_label_set_text(ui->screen_label_7, "幅度");
	lv_label_set_long_mode(ui->screen_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_7, 57, 10);
	lv_obj_set_size(ui->screen_label_7, 120, 32);

	//Write style for screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_7, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_7, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_delay
	ui->screen_cont_delay = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_delay, 405, 100);
	lv_obj_set_size(ui->screen_cont_delay, 385, 370);
	lv_obj_set_scrollbar_mode(ui->screen_cont_delay, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_delay, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_delay, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_delay, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_delay, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_delay, lv_color_hex(0x00FFD2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_delay, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_cont_delay, lv_color_hex(0xA3D3FB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_cont_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_cont_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_delay, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_cont_delay, lv_color_hex(0x64686b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_cont_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_cont_delay, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_cont_delay, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_cont_delay, 3, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_delay);
	lv_label_set_text(ui->screen_label_1, "多径传输模拟设置");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 85, 10);
	lv_obj_set_size(ui->screen_label_1, 215, 32);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_12
	ui->screen_label_12 = lv_label_create(ui->screen_cont_delay);
	lv_label_set_text(ui->screen_label_12, "时延");
	lv_label_set_long_mode(ui->screen_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_12, 136, 70);
	lv_obj_set_size(ui->screen_label_12, 110, 32);

	//Write style for screen_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_12, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_12, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_11
	ui->screen_label_11 = lv_label_create(ui->screen_cont_delay);
	lv_label_set_text(ui->screen_label_11, "初相");
	lv_label_set_long_mode(ui->screen_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_11, 265, 70);
	lv_obj_set_size(ui->screen_label_11, 110, 32);

	//Write style for screen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_11, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_11, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_11, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_11, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_roller_sita
	ui->screen_roller_sita = lv_roller_create(ui->screen_cont_delay);
	lv_roller_set_options(ui->screen_roller_sita, "0°\n30°\n60°\n90°\n120°\n150°\n180°\n-150°\n-120°\n-90°\n-60°\n-30°", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_sita, 265, 119);
	lv_obj_set_width(ui->screen_roller_sita, 110);

	//Write style for screen_roller_sita, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_sita, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_sita, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_sita, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_sita, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_sita, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_sita, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_sita, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_sita, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_sita, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_sita, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_sita, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_sita, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_sita, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_sita, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_sita, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_sita, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_sita, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_sita, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_sita, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_sita, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_sita, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_sita, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_sita, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_sita, 5);
	//Write codes screen_roller_t
	ui->screen_roller_t = lv_roller_create(ui->screen_cont_delay);
	lv_roller_set_options(ui->screen_roller_t, "0ns\n50ns\n65ns\n80ns\n95ns\n110ns\n125ns\n140ns\n155ns\n170ns\n185ns\n200ns", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_t, 136, 118);
	lv_obj_set_width(ui->screen_roller_t, 110);

	//Write style for screen_roller_t, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_t, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_t, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_t, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_t, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_t, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_t, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_t, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_t, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_t, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_t, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_t, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_t, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_t, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_t, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_t, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_t, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_t, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_t, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_t, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_t, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_t, 5);
	//Write codes screen_roller_dB
	ui->screen_roller_dB = lv_roller_create(ui->screen_cont_delay);
	lv_roller_set_options(ui->screen_roller_dB, "0dB\n2dB\n4dB\n6dB\n8dB\n10dB\n12dB\n14dB\n16dB\n18dB\n20dB", LV_ROLLER_MODE_INFINITE);
	lv_obj_set_pos(ui->screen_roller_dB, 10, 120);
	lv_obj_set_width(ui->screen_roller_dB, 110);

	//Write style for screen_roller_dB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_roller_dB, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_roller_dB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_dB, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_dB, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_dB, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_dB, &lv_font_MI_LanTing_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_dB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_dB, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_roller_dB, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_roller_dB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_roller_dB, lv_color_hex(0xcbcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_roller_dB, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_roller_dB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_roller_dB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_roller_dB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_roller_dB, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_roller_dB, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_roller_dB, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_roller_dB, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_roller_dB, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller_dB, &lv_font_montserratMedium_20, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_roller_dB, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_roller_dB, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	lv_roller_set_visible_row_count(ui->screen_roller_dB, 5);
	//Write codes screen_label_10
	ui->screen_label_10 = lv_label_create(ui->screen_cont_delay);
	lv_label_set_text(ui->screen_label_10, "衰减");
	lv_label_set_long_mode(ui->screen_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_10, 10, 70);
	lv_obj_set_size(ui->screen_label_10, 110, 32);

	//Write style for screen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_10, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_10, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_start
	ui->screen_btn_start = lv_btn_create(ui->screen_cont_delay);
	ui->screen_btn_start_label = lv_label_create(ui->screen_btn_start);
	lv_label_set_text(ui->screen_btn_start_label, "开始模拟");
	lv_label_set_long_mode(ui->screen_btn_start_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_start_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_start, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_start_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_start, 15, 300);
	lv_obj_set_size(ui->screen_btn_start, 355, 40);

	//Write style for screen_btn_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_start, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_start, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_btn_start, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_btn_start, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_start, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_start, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_btn_start, lv_color_hex(0x64686B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_btn_start, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_btn_start, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_btn_start, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_start, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_start, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_TI
	ui->screen_img_TI = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_TI, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_TI, &_TI_alpha_159x100);
	lv_img_set_pivot(ui->screen_img_TI, 50,50);
	lv_img_set_angle(ui->screen_img_TI, 0);
	lv_obj_set_pos(ui->screen_img_TI, 321, 0);
	lv_obj_set_size(ui->screen_img_TI, 159, 100);

	//Write style for screen_img_TI, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_TI, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spinner_1
	ui->screen_spinner_1 = lv_spinner_create(ui->screen, 1000, 60);
	lv_obj_set_pos(ui->screen_spinner_1, 700, 0);
	lv_obj_set_size(ui->screen_spinner_1, 100, 100);

	//Write style for screen_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0xf583ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0x884a8b), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_btn_debug
	ui->screen_btn_debug = lv_btn_create(ui->screen);
	ui->screen_btn_debug_label = lv_label_create(ui->screen_btn_debug);
	lv_label_set_text(ui->screen_btn_debug_label, "DEBUG");
	lv_label_set_long_mode(ui->screen_btn_debug_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_debug_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_debug, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_debug_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_debug, 20, 20);
	lv_obj_set_size(ui->screen_btn_debug, 100, 29);

	//Write style for screen_btn_debug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_debug, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_btn_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_btn_debug, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_btn_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_debug, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_debug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_debug, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_debug, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_chart0
	ui->screen_btn_chart0 = lv_btn_create(ui->screen);
	ui->screen_btn_chart0_label = lv_label_create(ui->screen_btn_chart0);
	lv_label_set_text(ui->screen_btn_chart0_label, "CHART0");
	lv_label_set_long_mode(ui->screen_btn_chart0_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_chart0_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_chart0, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_chart0_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_chart0, 180, 20);
	lv_obj_set_size(ui->screen_btn_chart0, 110, 50);

	//Write style for screen_btn_chart0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_chart0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_chart0, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_chart0, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_chart0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_chart0, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_chart0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_chart0, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_chart0, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_chart0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_chart0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_chart1
	ui->screen_btn_chart1 = lv_btn_create(ui->screen);
	ui->screen_btn_chart1_label = lv_label_create(ui->screen_btn_chart1);
	lv_label_set_text(ui->screen_btn_chart1_label, "CHART1");
	lv_label_set_long_mode(ui->screen_btn_chart1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_chart1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_chart1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_chart1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_chart1, 521, 20);
	lv_obj_set_size(ui->screen_btn_chart1, 110, 50);

	//Write style for screen_btn_chart1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_chart1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_chart1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_chart1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_chart1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_chart1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_chart1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_chart1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_chart1, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_chart1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_chart1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_chart_chose
	ui->screen_label_chart_chose = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_chart_chose, "Chart0");
	lv_label_set_long_mode(ui->screen_label_chart_chose, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_chart_chose, 24, 62);
	lv_obj_set_size(ui->screen_label_chart_chose, 92, 19);

	//Write style for screen_label_chart_chose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_chart_chose, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_chart_chose, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_chart_chose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_chart_chose, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_chart_chose, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_chart_chose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_debug
	ui->screen_cont_debug = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_debug, 10, 8);
	lv_obj_set_size(ui->screen_cont_debug, 780, 460);
	lv_obj_set_scrollbar_mode(ui->screen_cont_debug, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_cont_debug, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_cont_debug, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_debug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_debug, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_debug, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_debug, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_debug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_debug_apply
	ui->screen_btn_debug_apply = lv_btn_create(ui->screen_cont_debug);
	ui->screen_btn_debug_apply_label = lv_label_create(ui->screen_btn_debug_apply);
	lv_label_set_text(ui->screen_btn_debug_apply_label, "APPLY");
	lv_label_set_long_mode(ui->screen_btn_debug_apply_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_debug_apply_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_debug_apply, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_debug_apply_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_debug_apply, 350, 392);
	lv_obj_set_size(ui->screen_btn_debug_apply, 100, 50);

	//Write style for screen_btn_debug_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_debug_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_debug_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_debug_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_debug_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_debug_apply, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_debug_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_debug_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_debug_apply, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_debug_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_debug_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ddlist_debug
	ui->screen_ddlist_debug = lv_dropdown_create(ui->screen_cont_debug);
	lv_dropdown_set_options(ui->screen_ddlist_debug, "CW_ZD_AMP\nCW_DELAY_AMP\nCW_PHASE\nAM_PHASE\nAM_AMP\nAM_MODU_AMP");
	lv_obj_set_pos(ui->screen_ddlist_debug, 10, 49);
	lv_obj_set_size(ui->screen_ddlist_debug, 310, 40);

	//Write style for screen_ddlist_debug, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ddlist_debug, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ddlist_debug, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ddlist_debug, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ddlist_debug, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ddlist_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ddlist_debug, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ddlist_debug, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ddlist_debug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_debug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_debug, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ddlist_debug, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_ddlist_debug, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_ddlist_debug, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_ddlist_debug, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_ddlist_debug, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_ddlist_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_debug, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_ddlist_debug, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_debug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_debug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_debug, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_ddlist_debug, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_ddlist_debug, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_ddlist_debug, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_ddlist_debug, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_ddlist_debug, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_ddlist_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_debug, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_ddlist_debug, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_debug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_debug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_debug, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for screen_ddlist_debug, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
	lv_obj_set_style_text_color(ui->screen_ddlist_debug, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_font(ui->screen_ddlist_debug, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_width(ui->screen_ddlist_debug, 1, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_color(ui->screen_ddlist_debug, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_side(ui->screen_ddlist_debug, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_debug, 8, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_debug, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_radius(ui->screen_ddlist_debug, 3, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_debug, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_debug, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_debug, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_debug, 0, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_CHECKED for &style_screen_ddlist_debug_extra_list_selected_checked
	static lv_style_t style_screen_ddlist_debug_extra_list_selected_checked;
	ui_init_style(&style_screen_ddlist_debug_extra_list_selected_checked);
	
	lv_style_set_text_color(&style_screen_ddlist_debug_extra_list_selected_checked, lv_color_hex(0x000000));
	lv_style_set_text_font(&style_screen_ddlist_debug_extra_list_selected_checked, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_ddlist_debug_extra_list_selected_checked, 255);
	lv_style_set_border_width(&style_screen_ddlist_debug_extra_list_selected_checked, 2);
	lv_style_set_border_opa(&style_screen_ddlist_debug_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_ddlist_debug_extra_list_selected_checked, lv_color_hex(0x654f4f));
	lv_style_set_border_side(&style_screen_ddlist_debug_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_debug_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_debug_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_ddlist_debug_extra_list_selected_checked, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_debug_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_debug), &style_screen_ddlist_debug_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_debug_extra_list_main_default
	static lv_style_t style_screen_ddlist_debug_extra_list_main_default;
	ui_init_style(&style_screen_ddlist_debug_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_ddlist_debug_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_ddlist_debug_extra_list_main_default, lv_color_hex(0x000000));
	lv_style_set_text_font(&style_screen_ddlist_debug_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_ddlist_debug_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_ddlist_debug_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_ddlist_debug_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_debug_extra_list_main_default, lv_color_hex(0x654f4f));
	lv_style_set_border_side(&style_screen_ddlist_debug_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_debug_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_debug_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_ddlist_debug_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_debug_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_debug), &style_screen_ddlist_debug_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_debug_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist_debug_extra_list_scrollbar_default;
	ui_init_style(&style_screen_ddlist_debug_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_ddlist_debug_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_debug_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_ddlist_debug_extra_list_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_debug_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_debug), &style_screen_ddlist_debug_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_slider_debug100
	ui->screen_slider_debug100 = lv_slider_create(ui->screen_cont_debug);
	lv_slider_set_range(ui->screen_slider_debug100, -100, 100);
	lv_slider_set_mode(ui->screen_slider_debug100, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_slider_debug100, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_slider_debug100, 9, 19);
	lv_obj_set_size(ui->screen_slider_debug100, 760, 19);

	//Write style for screen_slider_debug100, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug100, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug100, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug100, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug100, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_slider_debug100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_slider_debug100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_slider_debug100, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug100, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug100, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug100, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug100, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_slider_debug100, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug100, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug100, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug100, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug100, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_label_AMP_TEMP
	ui->screen_label_AMP_TEMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_AMP_TEMP, "1.00000");
	lv_label_set_long_mode(ui->screen_label_AMP_TEMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_AMP_TEMP, 649, 90);
	lv_obj_set_size(ui->screen_label_AMP_TEMP, 115, 27);

	//Write style for screen_label_AMP_TEMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_AMP_TEMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_AMP_TEMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_AMP_TEMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_AMP_TEMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_AMP_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_14
	ui->screen_label_14 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_14, "CW_ZD_AMP:");
	lv_label_set_long_mode(ui->screen_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_14, 13, 328);
	lv_obj_set_size(ui->screen_label_14, 195, 32);

	//Write style for screen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_14, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_14, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_CW_ZD_AMP
	ui->screen_label_CW_ZD_AMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_CW_ZD_AMP, "1.00000");
	lv_label_set_long_mode(ui->screen_label_CW_ZD_AMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_CW_ZD_AMP, 202, 328);
	lv_obj_set_size(ui->screen_label_CW_ZD_AMP, 123, 32);

	//Write style for screen_label_CW_ZD_AMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_CW_ZD_AMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_CW_ZD_AMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_CW_ZD_AMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_CW_ZD_AMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_CW_ZD_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_16
	ui->screen_label_16 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_16, "CW_DELAY_AMP:");
	lv_label_set_long_mode(ui->screen_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_16, 364, 335);
	lv_obj_set_size(ui->screen_label_16, 256, 32);

	//Write style for screen_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_16, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_16, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_CW_DELAY_AMP
	ui->screen_label_CW_DELAY_AMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_CW_DELAY_AMP, "1.00000");
	lv_label_set_long_mode(ui->screen_label_CW_DELAY_AMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_CW_DELAY_AMP, 620, 333);
	lv_obj_set_size(ui->screen_label_CW_DELAY_AMP, 123, 32);

	//Write style for screen_label_CW_DELAY_AMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_CW_DELAY_AMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_CW_DELAY_AMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_CW_DELAY_AMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_CW_DELAY_AMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_CW_DELAY_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_PHASE_TEMP
	ui->screen_label_PHASE_TEMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_PHASE_TEMP, "0.00000");
	lv_label_set_long_mode(ui->screen_label_PHASE_TEMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_PHASE_TEMP, 532, 89);
	lv_obj_set_size(ui->screen_label_PHASE_TEMP, 115, 27);

	//Write style for screen_label_PHASE_TEMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_PHASE_TEMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_PHASE_TEMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_PHASE_TEMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_PHASE_TEMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_PHASE_TEMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_18
	ui->screen_label_18 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_18, "PHASE\n");
	lv_label_set_long_mode(ui->screen_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_18, 536, 52);
	lv_obj_set_size(ui->screen_label_18, 106, 27);

	//Write style for screen_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_18, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_18, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_19
	ui->screen_label_19 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_19, "AMP\n");
	lv_label_set_long_mode(ui->screen_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_19, 654, 52);
	lv_obj_set_size(ui->screen_label_19, 106, 27);

	//Write style for screen_label_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_19, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_19, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_19, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_20
	ui->screen_label_20 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_20, "CW_PHASE:");
	lv_label_set_long_mode(ui->screen_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_20, 8, 267);
	lv_obj_set_size(ui->screen_label_20, 186, 32);

	//Write style for screen_label_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_20, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_20, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_20, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_21
	ui->screen_label_21 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_21, "0.00000");
	lv_label_set_long_mode(ui->screen_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_21, 202, 269);
	lv_obj_set_size(ui->screen_label_21, 124, 32);

	//Write style for screen_label_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_21, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_21, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_slider_debug_10000
	ui->screen_slider_debug_10000 = lv_slider_create(ui->screen_cont_debug);
	lv_slider_set_range(ui->screen_slider_debug_10000, -100, 100);
	lv_slider_set_mode(ui->screen_slider_debug_10000, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_slider_debug_10000, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_slider_debug_10000, 9, 127);
	lv_obj_set_size(ui->screen_slider_debug_10000, 760, 19);

	//Write style for screen_slider_debug_10000, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug_10000, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug_10000, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug_10000, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug_10000, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_slider_debug_10000, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_slider_debug_10000, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_slider_debug_10000, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug_10000, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug_10000, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug_10000, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug_10000, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_slider_debug_10000, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_slider_debug_10000, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_slider_debug_10000, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_slider_debug_10000, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_slider_debug_10000, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_label_22
	ui->screen_label_22 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_22, "AM_PHASE:");
	lv_label_set_long_mode(ui->screen_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_22, 359, 272);
	lv_obj_set_size(ui->screen_label_22, 186, 32);

	//Write style for screen_label_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_22, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_22, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_22, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_AM_PHASE
	ui->screen_label_AM_PHASE = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_AM_PHASE, "0.00000");
	lv_label_set_long_mode(ui->screen_label_AM_PHASE, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_AM_PHASE, 555, 272);
	lv_obj_set_size(ui->screen_label_AM_PHASE, 132, 32);

	//Write style for screen_label_AM_PHASE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_AM_PHASE, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_AM_PHASE, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_AM_PHASE, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_AM_PHASE, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_AM_PHASE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_23
	ui->screen_label_23 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_23, "AM_AMP:");
	lv_label_set_long_mode(ui->screen_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_23, 392, 210);
	lv_obj_set_size(ui->screen_label_23, 135, 29);

	//Write style for screen_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_23, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_23, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_23, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_AM_AMP
	ui->screen_label_AM_AMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_AM_AMP, "1.00000");
	lv_label_set_long_mode(ui->screen_label_AM_AMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_AM_AMP, 521, 209);
	lv_obj_set_size(ui->screen_label_AM_AMP, 140, 32);

	//Write style for screen_label_AM_AMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_AM_AMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_AM_AMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_AM_AMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_AM_AMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_AM_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_24
	ui->screen_label_24 = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_24, "AM_MODU_AMP:");
	lv_label_set_long_mode(ui->screen_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_24, 17, 212);
	lv_obj_set_size(ui->screen_label_24, 242, 32);

	//Write style for screen_label_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_24, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_24, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_24, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_AM_MODU_AMP
	ui->screen_label_AM_MODU_AMP = lv_label_create(ui->screen_cont_debug);
	lv_label_set_text(ui->screen_label_AM_MODU_AMP, "1.00000");
	lv_label_set_long_mode(ui->screen_label_AM_MODU_AMP, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_AM_MODU_AMP, 264, 212);
	lv_obj_set_size(ui->screen_label_AM_MODU_AMP, 108, 32);

	//Write style for screen_label_AM_MODU_AMP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_AM_MODU_AMP, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_AM_MODU_AMP, &lv_font_MI_LanTing_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_AM_MODU_AMP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_AM_MODU_AMP, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_AM_MODU_AMP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	//Init events for screen.
	events_init_screen(ui);
}
