#ifndef FPGA_SPI_H
#define FPGA_SPI_H
/**
  ******************************************************************************
  * @file           : fpga_spi.h
  * @brief          : 和fpga进行私有协议（类似spi）通信
	* @author					: wjx 2219
	* @date						: 2024_7_23	
  ******************************************************************************
*/
#include "gpio.h"
#include "main.h"
#include "delay.h"

#define CLK_PIN 	GPIO_PIN_13
#define CLK_PORT	GPIOF

#define SPI_PIN		GPIO_PIN_14
#define SPI_PORT	GPIOF

#define FLAG_PIN	GPIO_PIN_15
#define FLAG_PORT	GPIOF

#define CLK_0		{HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_RESET);}
#define CLK_1		{HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_SET);}

#define SPI_0		{HAL_GPIO_WritePin(SPI_PORT, SPI_PIN, GPIO_PIN_RESET);}
#define SPI_1		{HAL_GPIO_WritePin(SPI_PORT, SPI_PIN, GPIO_PIN_SET);}

#define FLAG_0	{HAL_GPIO_WritePin(FLAG_PORT, FLAG_PIN, GPIO_PIN_RESET);}
#define FLAG_1	{HAL_GPIO_WritePin(FLAG_PORT, FLAG_PIN, GPIO_PIN_SET);}


void fpga_spi_init();
void fpga_write_data(uint16_t data);
void fpga_set_phase(uint16_t phase);

#endif