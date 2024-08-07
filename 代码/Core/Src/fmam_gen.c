#include "fmam_gen.h"

#define M_PI (3.14159265358979323846)

/**
  ******************************************************************************
  * @brief          : DDS 实现FMAM信号调制
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	使用示例：
	直接调用am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_)即可
*/

static float32_t am_carrier_w;
static float32_t am_carrier_freq;
static float32_t am_modu_w;
static float32_t am_depth;
static float32_t am_gain;

static float32_t fm_carrier_w;
static float32_t fm_carrier_freq;
static float32_t fm_modu_w;
static float32_t fm_offset_w;
static float32_t fm_gain;

static int am_fm_flag;//am:0 fm:1

static float32_t current_gain;
static float32_t current_freq;
static float32_t t;

void am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_)
{
	am_carrier_w=2.0*M_PI*am_carrier_freq_;
	am_carrier_freq=am_carrier_freq_;
	am_modu_w=2.0*M_PI*am_modu_freq_;
	am_gain=am_gain_;
	am_depth=am_depth_;
	t=0.0;
	
	am_fm_flag=0;
	AD9910_Init();
	HAL_TIM_Base_Start_IT(&htim4); 
}

void am_gen_run_dds()
{
	current_gain=am_gain*(1.0+am_depth*cosf(t*am_modu_w))/2.0;
	t+=0.00001;//10ns
	AD9910_Amp_Pha_Freq_Set(current_gain, 0.0,am_carrier_freq , 0);
}

void fm_gen_start_dds(float32_t fm_carrier_freq_,float32_t fm_modu_freq_,float32_t fm_gain_,float32_t fm_offset_freq_)
{
	fm_carrier_w=2.0*M_PI*fm_carrier_freq_;
	fm_carrier_freq=fm_carrier_freq_;
	fm_modu_w=2.0*M_PI*fm_modu_freq_;
	fm_gain=fm_gain_;
	fm_offset_w=2.0*M_PI*fm_offset_freq_;
	t=0.0;
	
	am_fm_flag=1;
	AD9910_Init();
	HAL_TIM_Base_Start_IT(&htim4); 
}

void fm_gen_run_dds()
{
	//current_freq=fm_carrier_w+fm_offset_w*cosf(fm_modu_w*t);
	t+=0.00001;//10ns
	AD9910_Amp_Pha_Freq_Set(fm_gain, 0.0,fm_carrier_w+fm_offset_w*cosf(fm_modu_w*t) , 0);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	
		if (am_fm_flag)
		{
			fm_gen_run_dds();
		}
		else 
		{
			am_gen_run_dds();
		}
		
}

/**
  ******************************************************************************
  * @brief          : DAC 实现FMAM信号调制 调制信号载波不超过50KHz 调制信号为1000的因数KHz
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	使用示例：
	调用am_dac_init()和fm_dac_init()进行波形打表
	再用fmam_dac_start()开始生成波形
	调用fmam_dac_stop()停止生成波形
	调用check_chart()检查波形打表内容
*/
static uint16_t chart[1000];
static uint32_t chart_length;


void am_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t depth_)
{
	float32_t carrier_w=2*M_PI*carrier_freq_;
	float32_t modu_w=2*M_PI*modu_freq_;
	float32_t T=1.0/modu_freq_;
	chart_length=1000000.0/modu_freq_;
	
	float32_t t_temp=0;
	float32_t index=0;
	for (int i=0;i<chart_length;i+=1)
	{
		t_temp=index*0.001/1000.0;
		chart[i]=4096.0*gain_*((1.0+depth_*cosf(t_temp*modu_w))*cosf(t_temp*carrier_w)+2.0)/4.0;
		index+=1;
	}
	
	//printf("chart_length:%d\n",chart_length);
}


void fm_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t offset_freq_)
{
	float32_t carrier_w=2*M_PI*carrier_freq_;
	float32_t modu_w=2*M_PI*modu_freq_;
	float32_t offset_w=2*M_PI*offset_freq_;
	
	float32_t beta = offset_w/modu_w;
	float32_t T=1.0/modu_freq_;
	chart_length=1000000.0/modu_freq_;
	
	float32_t t_temp=0;
	float32_t index=0;
	for (int i=0;i<chart_length;i+=1)
	{
		t_temp=index*0.001/1000.0;
		chart[i] = 4096.0*(cosf(t_temp*carrier_w+beta*sinf(t_temp*modu_w))+1.0)/2.0;
		index+=1;
	}
	printf("chart_length:%d\n",chart_length);
}

void fmam_dac_start()
{
	HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
	HAL_Delay(3);
	HAL_TIM_Base_Start(&htim5); 
	HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)&chart, chart_length, DAC_ALIGN_12B_R);
}


void fmam_dac_stop()
{
	HAL_TIM_Base_Stop(&htim5); 
	HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
}

void check_chart()
{
	for(int i=0;i<chart_length;i++)
	{
		printf("fmam:%d\n",chart[i]);
	}
}


