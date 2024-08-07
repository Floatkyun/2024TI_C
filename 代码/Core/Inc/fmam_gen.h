#ifndef __FMAM_GEN_H__
#define __FMAM_GEN_H__

#include "main.h"
#include "usart.h"
#include "tim.h"

#include <math.h>
#include "arm_math.h"
#include "arm_const_structs.h"

#include "dac.h"
#include "AD9910.H"
/**
  ******************************************************************************
  * @brief          : DDS 实现FMAM信号调制
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	使用示例：
	直接调用am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_)即可
	传入参数：
	carrier_freq：载波频率
	modu_freq_：	调制波频率
	gain_：				增益 0~1之间
	depth_：			调制深度
	
	使用示例：
	直接调用fm_gen_start_dds(float32_t fm_carrier_freq_,float32_t fm_modu_freq_,float32_t fm_gain_,float32_t fm_offset_freq_)即可
	传入参数：
	carrier_freq：载波频率
	modu_freq_：	调制波频率
	gain_：				增益 0~1之间
	offset_freq_：最大频偏
*/
void am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_);
void fm_gen_start_dds(float32_t fm_carrier_freq_,float32_t fm_modu_freq_,float32_t fm_gain_,float32_t fm_offset_freq_);
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
	传入参数：同上
*/
void am_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t depth_);
void fm_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t offset_freq_);
void fmam_dac_start();
void fmam_dac_stop();
void check_chart();
#endif