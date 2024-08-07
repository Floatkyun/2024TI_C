#ifndef __VARIR_H__
#define __VARIR_H__
#include "main.h"
#include "delay.h"

#define VARIR_GND_GPIO_Port GPIOE
#define VARIR_UD_GPIO_Port 	GPIOC
#define VARIR_INC_GPIO_Port GPIOE
#define VARIR_CS_GPIO_Port 	GPIOB
#define VARIR_VCC_GPIO_Port GPIOG

#define VARIR_GND_GPIO_Pin GPIO_PIN_5
#define VARIR_UD_GPIO_Pin GPIO_PIN_0
#define VARIR_INC_GPIO_Pin GPIO_PIN_1
#define VARIR_CS_GPIO_Pin GPIO_PIN_7
#define VARIR_VCC_GPIO_Pin GPIO_PIN_9

#define VARIR_GND_0 {HAL_GPIO_WritePin(VARIR_GND_GPIO_Port, VARIR_GND_GPIO_Pin, GPIO_PIN_RESET);}

#define VARIR_VCC_1 {HAL_GPIO_WritePin(VARIR_VCC_GPIO_Port, VARIR_VCC_GPIO_Pin, GPIO_PIN_SET);}

#define VARIR_UD_0 {HAL_GPIO_WritePin(VARIR_UD_GPIO_Port, VARIR_UD_GPIO_Pin, GPIO_PIN_RESET);}
#define VARIR_UD_1 {HAL_GPIO_WritePin(VARIR_UD_GPIO_Port, VARIR_UD_GPIO_Pin, GPIO_PIN_SET);}

#define VARIR_INC_0 {HAL_GPIO_WritePin(VARIR_INC_GPIO_Port, VARIR_INC_GPIO_Pin, GPIO_PIN_RESET);}
#define VARIR_INC_1 {HAL_GPIO_WritePin(VARIR_INC_GPIO_Port, VARIR_INC_GPIO_Pin, GPIO_PIN_SET);}

#define VARIR_CS_0 {HAL_GPIO_WritePin(VARIR_CS_GPIO_Port, VARIR_CS_GPIO_Pin, GPIO_PIN_RESET);}
#define VARIR_CS_1 {HAL_GPIO_WritePin(VARIR_CS_GPIO_Port, VARIR_CS_GPIO_Pin, GPIO_PIN_SET);}


void variR_init();
void variR_test();
void variR_down();
void variR_up();
void variR_set_value(uint16_t R);

#endif
