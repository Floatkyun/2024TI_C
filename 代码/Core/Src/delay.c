#include "delay.h"

static uint8_t  fac_us=0;
static uint8_t temp=0;
void delay_init()
{
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	fac_us=SystemCoreClock/1000000;
}

void delay_us(uint32_t nus)
{
	uint32_t ticks;
	uint32_t t_old, t_now, t_cnt = 0;
	uint32_t reload = SysTick->LOAD;
	ticks = nus * fac_us;
	while(1)
	{
		t_now=SysTick->VAL;
		if(t_now != t_old)
		{
			if(t_now < t_old){t_cnt += t_old - t_now;}
			else{t_cnt += reload - t_now + t_old;}
			t_old = t_now;
			if(t_cnt >= ticks){break;}
		}
	}
}

void delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++)
	{
		delay_us(1000);
	}
} 

void delay_ns(uint16_t nms)
{
	for (int t=0;t<nms;t++)
	{
	 temp=0;
	for (int i=0;i<2;i++)
	{
		temp++;
	}
}
}


