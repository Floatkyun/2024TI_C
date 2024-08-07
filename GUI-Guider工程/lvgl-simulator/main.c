/*
 * SPDX-License-Identifier: MIT
 * Copyright 2023 NXP
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED        /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lv_drivers/indev/keyboard.h"
#include "gui_guider.h"
#include "custom.h"
#include "widgets_init.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

#if LV_USE_FREEMASTER
#include "external_data_init.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void * data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

lv_ui guider_ui;

#if LV_USE_FREEMASTER
pthread_t thread[2];
pthread_mutex_t jsonrpc_mutex;
pthread_mutex_t lvgl_mutex;
pthread_mutex_t gg_edata_ll_mutex;
pthread_cond_t gg_edata_ll_cond;
#endif

int main(int argc, char ** argv)
{
    (void) argc;    /*Unused*/
    (void) argv;    /*Unused*/

    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LittlevGL*/
    hal_init();

#if LV_USE_FREEMASTER
    pthread_mutex_init(&gg_edata_ll_mutex, NULL);
    pthread_cond_init(&gg_edata_ll_cond, NULL);
    /*Initialize the external data */
    external_task_init(&guider_ui);
#endif

    /*Create a GUI-Guider app */
    setup_ui(&guider_ui);
	custom_init(&guider_ui);
#if LV_USE_FREEMASTER
    pthread_mutex_init(&jsonrpc_mutex, NULL);
    pthread_mutex_init(&lvgl_mutex, NULL);
    memset(&thread, 0, sizeof(thread));
    /*Create a separate thread to loop the linked list*/
    pthread_create(&thread[0], NULL, gg_edata_task_exec, &jsonrpc_mutex);
#endif

    while(1) {
#if LV_USE_FREEMASTER
        pthread_mutex_lock(&lvgl_mutex);
#endif
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
#if LV_USE_VIDEO
        video_play(&guider_ui);
#endif
#if LV_USE_FREEMASTER
        pthread_mutex_unlock(&lvgl_mutex);
#endif
        usleep(5 * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{
    /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();

    /*Create a display buffer*/
    static lv_disp_draw_buf_t disp_buf1;
    static lv_color_t buf1_1[MONITOR_HOR_RES * MONITOR_VER_RES];
    lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, MONITOR_HOR_RES * MONITOR_VER_RES);

    /*Create a display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    disp_drv.hor_res = MONITOR_HOR_RES;
    disp_drv.ver_res = MONITOR_VER_RES;
    lv_disp_drv_register(&disp_drv);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_t * mouse_indev = lv_indev_drv_register(&indev_drv);

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
     * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);
}

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void * data)
{
    (void)data;

    while(1) {
        SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}
