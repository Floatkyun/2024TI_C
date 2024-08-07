#include "fpga_spi.h"



void fpga_spi_init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;	
	
	GPIO_InitStruct.Pin = CLK_PIN;
  HAL_GPIO_Init(CLK_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = SPI_PIN;
  HAL_GPIO_Init(SPI_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = FLAG_PIN;
  HAL_GPIO_Init(FLAG_PORT, &GPIO_InitStruct);
	
	CLK_0	
	SPI_0
	FLAG_0
}


void fpga_write_data(uint16_t data)
{
	FLAG_1
	//delay_us(1);
	uint16_t mask=1;
	
	for (int i=0;i<16;i++)
	{
		
		CLK_0	
		//delay_us(5);
		if (data&mask){	SPI_1}
		else{	SPI_0 }
		//delay_us(5);
		CLK_1		
		
		mask<<=1;
	}
	
	
//	for (mask=0x8000;mask;mask>>=1)
//	{
//		CLK_0	
//		//delay_us(5);
//		if (data&mask){	SPI_1}
//		else{	SPI_0 }
//		//delay_us(5);
//		CLK_1		
//		//delay_us(5);
//	}
	
	CLK_0	
	SPI_0
	FLAG_0
	
}

void fpga_set_phase(uint16_t phase)
{
	fpga_write_data(phase);
}