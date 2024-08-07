#include "variR.h"

void variR_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	GPIO_InitStruct.Pin = VARIR_GND_GPIO_Pin;
	HAL_GPIO_Init(VARIR_GND_GPIO_Port, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Pin = VARIR_UD_GPIO_Pin;
	HAL_GPIO_Init(VARIR_UD_GPIO_Port, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Pin = VARIR_INC_GPIO_Pin;
	HAL_GPIO_Init(VARIR_INC_GPIO_Port, &GPIO_InitStruct);		
	
	GPIO_InitStruct.Pin = VARIR_CS_GPIO_Pin;
	HAL_GPIO_Init(VARIR_CS_GPIO_Port, &GPIO_InitStruct);		
	
	GPIO_InitStruct.Pin = VARIR_VCC_GPIO_Pin;
	HAL_GPIO_Init(VARIR_VCC_GPIO_Port, &GPIO_InitStruct);
	
	VARIR_GND_0
	
	VARIR_VCC_1
	
	VARIR_UD_0
	
	VARIR_INC_0
	
	VARIR_CS_1
	
	for(int i=0;i<120;i++)
	{
		variR_down();
	}
	
}

void variR_up()
{
	VARIR_INC_0
	VARIR_UD_1
	VARIR_CS_0
	
	VARIR_INC_1
	//HAL_Delay(1);
	delay_us(1);
	VARIR_CS_1
	
	VARIR_INC_0
}

void variR_down()
{
	VARIR_INC_0
	VARIR_UD_0
	VARIR_CS_0
	
	VARIR_INC_1
	//HAL_Delay(1);
	delay_us(1);
	VARIR_CS_1
	
	VARIR_INC_0
}

void variR_set_value(uint16_t R)
{ if(R<0||R>100)
	{
		return ;
	}
	for(int i=0;i<105;i++)
	{
		variR_down();
	}
	
	for(int i=0;i<R;i++)
	{
		variR_up();
	}
}

void variR_test()
{
	for(int i=0;i<4;i++)
	{
		//HAL_Delay(100);
	variR_up();
	}
//		for(int i=0;i<100;i++)
//	{
//		HAL_Delay(100);
//	variR_down();
//	}
}
