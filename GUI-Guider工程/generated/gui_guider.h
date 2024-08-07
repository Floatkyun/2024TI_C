/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_cont_wave;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_ddlist_wave_form;
	lv_obj_t *screen_label_3;
	lv_obj_t *screen_roller_am_amp;
	lv_obj_t *screen_label_4;
	lv_obj_t *screen_label_5;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_roller_am_ma;
	lv_obj_t *screen_roller_am_fc;
	lv_obj_t *screen_cont_cw;
	lv_obj_t *screen_roller_cw_amp;
	lv_obj_t *screen_roller_cw_fc;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_cont_delay;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_12;
	lv_obj_t *screen_label_11;
	lv_obj_t *screen_roller_sita;
	lv_obj_t *screen_roller_t;
	lv_obj_t *screen_roller_dB;
	lv_obj_t *screen_label_10;
	lv_obj_t *screen_btn_start;
	lv_obj_t *screen_btn_start_label;
	lv_obj_t *screen_img_TI;
	lv_obj_t *screen_spinner_1;
	lv_obj_t *screen_btn_debug;
	lv_obj_t *screen_btn_debug_label;
	lv_obj_t *screen_btn_chart0;
	lv_obj_t *screen_btn_chart0_label;
	lv_obj_t *screen_btn_chart1;
	lv_obj_t *screen_btn_chart1_label;
	lv_obj_t *screen_label_chart_chose;
	lv_obj_t *screen_cont_debug;
	lv_obj_t *screen_btn_debug_apply;
	lv_obj_t *screen_btn_debug_apply_label;
	lv_obj_t *screen_ddlist_debug;
	lv_obj_t *screen_slider_debug100;
	lv_obj_t *screen_label_AMP_TEMP;
	lv_obj_t *screen_label_14;
	lv_obj_t *screen_label_CW_ZD_AMP;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_label_CW_DELAY_AMP;
	lv_obj_t *screen_label_PHASE_TEMP;
	lv_obj_t *screen_label_18;
	lv_obj_t *screen_label_19;
	lv_obj_t *screen_label_20;
	lv_obj_t *screen_label_21;
	lv_obj_t *screen_slider_debug_10000;
	lv_obj_t *screen_label_22;
	lv_obj_t *screen_label_AM_PHASE;
	lv_obj_t *screen_label_23;
	lv_obj_t *screen_label_AM_AMP;
	lv_obj_t *screen_label_24;
	lv_obj_t *screen_label_AM_MODU_AMP;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_TI_alpha_159x100);

LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_25)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_12)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_14)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_16)


#ifdef __cplusplus
}
#endif
#endif
