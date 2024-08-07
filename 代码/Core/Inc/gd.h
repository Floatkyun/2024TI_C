#ifndef GD_H
#define GD_H
/**
  ******************************************************************************
  * @file           : gd.h
  * @brief          : һά���������˻��ݶ��½���ʵ��
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	* @attention
  *ʹ��ǰ�벹ȫgd.c�е������� ��������Ҫ����ؽ����� �����ʺϵ��½�����
  *
  ******************************************************************************
ʹ��ʾ����
	uint16_t app_run_adaptive_GD()
{
	GD_init();//��ʼ���ݶ��½���
	for(int i=0;i<200;i++)//�Ż�200��
	{
		GD_step();
	}
}
*/
#include "main.h"
#include "rng.h"
#include "usart.h"

#include <math.h>
#include "arm_math.h"
#include "arm_const_structs.h"

void GD_init();
void GD_step();



#endif