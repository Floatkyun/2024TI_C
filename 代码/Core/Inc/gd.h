#ifndef GD_H
#define GD_H
/**
  ******************************************************************************
  * @file           : gd.h
  * @brief          : 一维二阶余弦退火梯度下降法实现
	* @author					: wjx 2219
	* @date						:	2024_7_23
  ******************************************************************************
	* @attention
  *使用前请补全gd.c中的弱函数 并根据需要添加重建条件 更换适合的下降参数
  *
  ******************************************************************************
使用示例：
	uint16_t app_run_adaptive_GD()
{
	GD_init();//初始化梯度下降法
	for(int i=0;i<200;i++)//优化200轮
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