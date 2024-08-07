#ifndef APP_H
#define APP_H
#include "lcd.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"
#include "tim.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "dac.h"
#include "AD9910.H"
#include "AD9959_NEW.h"
#include "fft.h"
#include "fpga_spi.h"
#include "gd.h"
#include "stdio.h"
#include "fmam_gen.h"
#include "PE43xx.H"
#include "variR.h"


#define M_PI (3.14159265358979323846)

#include <math.h>

#include "arm_math.h"
#include "arm_const_structs.h"

#define RELAY1_PORT 		GPIOB
#define RELAY1_PIN 			GPIO_PIN_13

#define RELAY1_EN_PORT 			GPIOB
#define RELAY1_EN_PIN 			GPIO_PIN_12

#define RELAY2_PORT 			GPIOG
#define RELAY2_PIN 			GPIO_PIN_1

static int relay1_state=0;
static int relay1_en_state=0;
static int relay2_state=0;

#define RELAY1_ENABLE {HAL_GPIO_WritePin(RELAY1_EN_PORT, RELAY1_EN_PIN, GPIO_PIN_RESET);relay1_en_state=1;}
#define RELAY1_DISABLE {HAL_GPIO_WritePin(RELAY1_EN_PORT, RELAY1_EN_PIN, GPIO_PIN_SET);relay1_en_state=0;}

#define RELAY2_CH1 {HAL_GPIO_WritePin(RELAY2_PORT, RELAY2_PIN, GPIO_PIN_RESET);relay2_state=1;}
#define RELAY2_CH2 {HAL_GPIO_WritePin(RELAY2_PORT, RELAY2_PIN, GPIO_PIN_SET);relay2_state=0;}


#define RELAY1_CH1 {HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_RESET);relay1_state=1;}
#define RELAY1_CH2 {HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_SET);relay1_state=0;}
#define RELAY1_TOGGL  {HAL_GPIO_TogglePin(RELAY1_PORT, RELAY1_PIN);relay1_state=1-relay1_state;}

#define MEASURE_LENGTH {RELAY1_CH1;}

static int chart_chose=1;


//chart0
static float32_t CW_ZD_AMP_Freq_Chart_0[11]={0.902,0.886,0.881,0.884,0.88,0.863,0.844,0.838,0.837,0.83,0.81};
static float32_t CW_DELAY_AMP_Freq_Chart_0[11]={0.939,0.918,0.913,0.916,0.907,0.888,0.867,0.859,0.856,0.846,0.824};

static float32_t AM_AMP_Chart_0[11]={0.82484006,0.822011633,0.816001226,0.795495129,0.792666702,0.783827867,0.780645887,0.772160605,0.76013979,0.748472528,0.736451713};
static float32_t AM_AMP_AMP_Chart_0[10]={1.03960396,1.032924721,1.006718529,1.009294807,1.018387553,1.005091938,1.023691655,1.021923621,1.050919378,0.967397454};

static float32_t CW_PHASE_0[11]={1.15,1.65,0.65,-0.75,-1.8,-2.15,-3.15,-3.3,-4.75,-5.6,-6.35};


//chart1
static float32_t CW_ZD_AMP_Freq_Chart_1[11]={1.04544,1.028,1.017,1.015,1.002,0.974,0.940 ,0.915,0.902,0.894,0.886};
static float32_t CW_DELAY_AMP_Freq_Chart_1[11]={1.088,1.067,1.054,1.027,0.995,0.977,0.968,0.951,0.927,0.909,0.904};

static float32_t AM_AMP_Chart_1[11]={0.945544554,0.945544554,0.900282885,0.900282885,0.881400283,0.867256011,0.843281471,0.834087694,0.814992928,0.800848656,0.781966054};
static float32_t AM_AMP_AMP_Chart_1[10]={1.03960396,1.032924721,1.006718529,1.009294807,1.018387553,1.005091938,1.023691655,1.021923621,1.050919378,0.967397454};

static float32_t CW_PHASE_1[11]={1.15,1.65,0.65,-0.75,-1.8,-2.15,-3.15,-3.3,-4.75,-5.6,-6.35};

static float32_t* CW_ZD_AMP_Freq_Chart=CW_ZD_AMP_Freq_Chart_0;
static float32_t* CW_DELAY_AMP_Freq_Chart=CW_DELAY_AMP_Freq_Chart_0;

static float32_t* AM_AMP_Chart=AM_AMP_Chart_0;
static float32_t* AM_AMP_AMP_Chart=AM_AMP_AMP_Chart_0;

static float32_t* CW_PHASE=CW_PHASE_0;


uint16_t* get_adc_buff();

uint8_t get_capture_flag();
void add_capture_flag();
void set_capture_buff1(uint32_t value_);
void set_capture_buff2(uint32_t value_);

void clear_DMA_flag();

void app_init();
void app_main_loop();

void app_start();
void show_temp_labal();
void set_debug();

void set_chart_0();
void set_chart_1();

#endif