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
  * @brief          : DDS ʵ��FMAM�źŵ���
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	ʹ��ʾ����
	ֱ�ӵ���am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_)����
	���������
	carrier_freq���ز�Ƶ��
	modu_freq_��	���Ʋ�Ƶ��
	gain_��				���� 0~1֮��
	depth_��			�������
	
	ʹ��ʾ����
	ֱ�ӵ���fm_gen_start_dds(float32_t fm_carrier_freq_,float32_t fm_modu_freq_,float32_t fm_gain_,float32_t fm_offset_freq_)����
	���������
	carrier_freq���ز�Ƶ��
	modu_freq_��	���Ʋ�Ƶ��
	gain_��				���� 0~1֮��
	offset_freq_�����Ƶƫ
*/
void am_gen_start_dds(float32_t am_carrier_freq_,float32_t am_modu_freq_,float32_t am_gain_,float32_t am_depth_);
void fm_gen_start_dds(float32_t fm_carrier_freq_,float32_t fm_modu_freq_,float32_t fm_gain_,float32_t fm_offset_freq_);
/**
  ******************************************************************************
  * @brief          : DAC ʵ��FMAM�źŵ��� �����ź��ز�������50KHz �����ź�Ϊ1000������KHz
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	ʹ��ʾ����
	����am_dac_init()��fm_dac_init()���в��δ��
	����fmam_dac_start()��ʼ���ɲ���
	����fmam_dac_stop()ֹͣ���ɲ���
	����check_chart()��鲨�δ������
	���������ͬ��
*/
void am_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t depth_);
void fm_dac_init(float32_t carrier_freq_,float32_t modu_freq_,float32_t gain_,float32_t offset_freq_);
void fmam_dac_start();
void fmam_dac_stop();
void check_chart();
#endif