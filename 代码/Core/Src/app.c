#include "app.h"
#define AD9910_GAIN (1)

static uint16_t adc_buff_[100];

lv_ui guider_ui;

static uint32_t capture_Buf[2] = {0};   //存放计数值
static uint8_t capture_flag = 0;    //状态标志位

void clear_capture_flag()
{
	capture_flag=0;
}

void add_capture_flag()
{
	capture_flag+=1;
}

uint8_t get_capture_flag()
{
	return capture_flag;
}

void set_capture_buff1(uint32_t value_)
{
	capture_Buf[0]= value_;
}

void set_capture_buff2(uint32_t value_)
{
	capture_Buf[1]= value_;
}


uint32_t get_capture_cycle()
{
	clear_capture_flag();
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_4);
	while (get_capture_flag()!=2){delay_us(1);}
	
	
	return (capture_Buf[1]-capture_Buf[0]);
}

float32_t measure_freq()
{
	uint32_t max=0;
	uint32_t temp=0;
	for (int j=0;j<10;j++)
	{
		temp=0;
	for (int i=0;i<10;i++)
	{
		temp+=get_capture_cycle();
	}
	if (temp>max)
	{
		max=temp;
	}
	}
	float32_t freq=84.0*MHz/(max/10.0);
	freq=floorf(freq+1);
	//printf("freq:%f\n",freq);
	return freq;
}

void set_dac_ch1(uint16_t value)
{
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, value);
		HAL_DAC_Start(&hdac,DAC_CHANNEL_1);
}

void set_dac_ch2(uint16_t value)
{
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, value);
		HAL_DAC_Start(&hdac,DAC_CHANNEL_2);
}

uint16_t set_gain(float32_t gain)//dB -20 +20
{
	if(gain>20 ||gain<-20)
	{
		return -1;
	}
	uint16_t dac_value=(gain+20.0)*4096.0/20.0/3.3;
	set_dac_ch1(dac_value);
	return 0;
}

uint16_t set_phase(uint16_t phase)//0~2048相移
{
	phase=phase%2048;
	fpga_write_data(phase);
	return 0;
}

void init_relay()//继电器初始化
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	GPIO_InitStruct.Pin = RELAY1_PIN;
	HAL_GPIO_Init(RELAY1_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = RELAY1_EN_PIN;
	HAL_GPIO_Init(RELAY1_EN_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = RELAY2_PIN;
	HAL_GPIO_Init(RELAY2_PORT, &GPIO_InitStruct);
	
	RELAY2_CH1
	RELAY1_CH1
}

uint16_t get_adc_value_sig()
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion (&hadc1 ,100);
	return HAL_ADC_GetValue(&hadc1 );
}

float32_t get_adc_value(uint8_t ch)
{
	set_DMA_flag();
	if (ch==1)
	{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buff_,100);
	}
	while(get_DMA_flag()){delay_us(1);}
	
	uint32_t temp=0;
	for(int i=0;i<100;i++)
	{
		temp+=adc_buff_[i];
	}
	return temp/100.0;
}



uint16_t tune_zero_9959(uint8_t ch1,uint8_t ch2,uint8_t adc_ch)
{
Write_frequence(ch1,30*MHz);
Write_Amplitude(ch1, 1023);
Write_Phase(ch1,0);
	
float32_t max=0;
uint16_t z_phase_0=0;
	
for(int i=0;i<=16383;i+=100)
	{
		Write_frequence(ch2,30*MHz);
		Write_Amplitude(ch2, 1023);
		Write_Phase(ch2,i);
		//HAL_Delay(1);
		float32_t temp_val=get_adc_value(adc_ch);
		//printf("adc,i:%f,%d\n",temp_val,i);
		if (temp_val>max)
		{
			max=temp_val;
			z_phase_0=i;
		}
	}
	
	max=0;
	uint16_t z_phase_1=0;
	for(int i=z_phase_0-1000;i<=z_phase_0+1000;i+=10)
	{
		Write_frequence(ch2,30*MHz);
		Write_Amplitude(ch2, 1023);
		Write_Phase(ch2,i);
		//HAL_Delay(1);
		float32_t temp_val=get_adc_value(adc_ch);
		//printf("adc,i:%f,%d\n",temp_val,i);
		if (temp_val>max)
		{
			max=temp_val;
			z_phase_1=i;
		}
	}
	
		max=0;
	uint16_t z_phase=0;
	for(int i=z_phase_1-100;i<=z_phase_1+100;i+=1)
	{
		Write_frequence(ch2,30*MHz);
		Write_Amplitude(ch2, 1023);
		Write_Phase(ch2,i);
		//HAL_Delay(1);
		float32_t temp_val=get_adc_value(adc_ch);
		//printf("adc,i:%f,%d\n",temp_val,i);
		if (temp_val>max)
		{
			max=temp_val;
			z_phase=i;
		}
	}
	
	for(int i=0;i<5;i++)
	{
	Write_frequence(ch2,30*MHz);
	Write_Amplitude(ch2, 1023);
	Write_Phase(ch2,z_phase);
	}
	
	return z_phase;
}

static uint16_t cw_am;//调制类型
static uint16_t amp;//增益
static uint16_t fc;//载波频率
static uint16_t ma;//调制深度

static uint16_t db;//衰减
static uint16_t delay_t;//时移
static uint16_t sita;//初相

static float32_t debug_CW_ZD_AMP=1.0;
static float32_t debug_CW_DELAY_AMP=1.0;
static float32_t debug_CW_PHASE=0.0;
static float32_t debug_AM_PHASE=0.0;
static float32_t debug_AM_AMP=1.0;
static float32_t debug_AM_MODU_AMP=1.0;

#define DELAY_CARR_CH 0
#define DELAY_MODU_CH 1
#define ORI_CARR_CH 3
#define ORI_MODU_CH 2

void set_chart_0()
{
 CW_ZD_AMP_Freq_Chart=CW_ZD_AMP_Freq_Chart_0;
 CW_DELAY_AMP_Freq_Chart=CW_DELAY_AMP_Freq_Chart_0;

 AM_AMP_Chart=AM_AMP_Chart_0;
 AM_AMP_AMP_Chart=AM_AMP_AMP_Chart_0;

 CW_PHASE=CW_PHASE_0;
	
	lv_label_set_text(guider_ui.screen_label_chart_chose,"Chart0");
}

void set_chart_1()
{
	CW_ZD_AMP_Freq_Chart=CW_ZD_AMP_Freq_Chart_1;
 CW_DELAY_AMP_Freq_Chart=CW_DELAY_AMP_Freq_Chart_1;

 AM_AMP_Chart=AM_AMP_Chart_1;
 AM_AMP_AMP_Chart=AM_AMP_AMP_Chart_1;

 CW_PHASE=CW_PHASE_1;
lv_label_set_text(guider_ui.screen_label_chart_chose,"Chart1");
}

void show_temp_labal()
{
	float32_t temp_phase=0.0;
	float32_t temp_amp=0.0;
	float32_t val_100=lv_slider_get_value(guider_ui.screen_slider_debug100);
	float32_t val_10000=lv_slider_get_value(guider_ui.screen_slider_debug_10000);
	
	temp_amp=val_100/100.0+val_10000*2.0/10000.0;
	temp_phase=temp_amp*90;
	temp_amp=temp_amp+1.0;
	
	char label_temp_phase[8];
	sprintf(label_temp_phase, "%.4f",temp_phase);
	lv_label_set_text(guider_ui.screen_label_PHASE_TEMP, label_temp_phase);
	
	char label_temp_amp[8];
	sprintf(label_temp_amp, "%.5f",temp_amp);
	lv_label_set_text(guider_ui.screen_label_AMP_TEMP, label_temp_amp);
	
}
void set_debug()
{
	float32_t temp_phase=0.0;
	float32_t temp_amp=0.0;
	float32_t val_100=lv_slider_get_value(guider_ui.screen_slider_debug100);
	float32_t val_10000=lv_slider_get_value(guider_ui.screen_slider_debug_10000);
	
	temp_amp=val_100/100.0+val_10000*2.0/10000.0;
	temp_phase=temp_amp*90;
	temp_amp=temp_amp+1.0;
	
	uint16_t debug_choose=lv_dropdown_get_selected(guider_ui.screen_ddlist_debug);
	if (debug_choose==0)//CW_ZD_AMP
	{
		debug_CW_ZD_AMP=temp_amp;
		
	char label_CW_ZD_AMP[8];
	sprintf(label_CW_ZD_AMP, "%.5f",temp_amp);
	lv_label_set_text(guider_ui.screen_label_CW_ZD_AMP, label_CW_ZD_AMP);
		
	}
	else if (debug_choose==1)//CW_DELAY_AMP
	{
		debug_CW_DELAY_AMP=temp_amp;
		
	char label_CW_DELAY_AMP[8];
	sprintf(label_CW_DELAY_AMP, "%.5f",temp_amp);
	lv_label_set_text(guider_ui.screen_label_CW_DELAY_AMP, label_CW_DELAY_AMP);
		
	}
	else if(debug_choose==2)//CW_PHASE
	{
		debug_CW_PHASE=temp_phase;
		
	char label_CW_PHASE[8];
	sprintf(label_CW_PHASE, "%.4f",temp_phase);
	lv_label_set_text(guider_ui.screen_label_21, label_CW_PHASE);
		
	}
	else if (debug_choose==3)//AM_PHASE
	{
		debug_AM_PHASE=temp_phase;
		
	char label_AM_PHASE[8];
	sprintf(label_AM_PHASE, "%.4f",temp_phase);
	lv_label_set_text(guider_ui.screen_label_AM_PHASE, label_AM_PHASE);
	}
	else if (debug_choose==4)//AM_AMP
	{
	debug_AM_AMP=temp_amp;
		
	char label_AM_AMP[8];
	sprintf(label_AM_AMP, "%.5f",temp_amp);
	lv_label_set_text(guider_ui.screen_label_AM_AMP, label_AM_AMP);
		
	}
	else if (debug_choose==5)//AM_MODU_AMP
	{
	debug_AM_MODU_AMP=temp_amp;
		
	char label_AM_MODU_AMP[8];
	sprintf(label_AM_MODU_AMP, "%.5f",temp_amp);
	lv_label_set_text(guider_ui.screen_label_AM_MODU_AMP, label_AM_MODU_AMP);
		
	}
}


void get_settings()
{
	cw_am=lv_dropdown_get_selected(guider_ui.screen_ddlist_wave_form);
	if (cw_am==0)//cw信号
	{
		amp = lv_roller_get_selected(guider_ui.screen_roller_cw_amp);
		fc = lv_roller_get_selected(guider_ui.screen_roller_cw_fc);
		ma = 0;
	}
	else//am信号
	{
		amp = lv_roller_get_selected(guider_ui.screen_roller_am_amp);
		fc = lv_roller_get_selected(guider_ui.screen_roller_am_fc);
		ma = lv_roller_get_selected(guider_ui.screen_roller_am_ma);
	}
	db=lv_roller_get_selected(guider_ui.screen_roller_dB);
	delay_t=lv_roller_get_selected(guider_ui.screen_roller_t);
	sita=lv_roller_get_selected(guider_ui.screen_roller_sita);
	
	amp=(amp+1)*100;//增益mVrms
	fc=30+fc;//载波频率MHz
	ma=10+10*ma;//调制度%
	
	db=2*db;//衰减dB
	if (delay_t!=0)
	{
			delay_t=50+15*(delay_t-1);//时延ns
	}

	sita=30*sita;//初相°
}

float32_t db_2_V(uint16_t db_value)
{
	float32_t F_db_value=db_value;
	F_db_value= -F_db_value/20.0;
	return powf(10,F_db_value);
}

float32_t cal_Phase(uint16_t t_,uint16_t freq)//t_:ns ;freq:MHz
{
	float32_t F_delay_t_=t_/1000.0;
	float32_t Freq=freq;
	float32_t T_=1.0/Freq;
	
	float32_t t_eq = fmodf(F_delay_t_,T_);
	return t_eq*360.0/T_;
}

void set_wave_config()
{
	if(cw_am==0)//CW
	{
		Write_frequence(ORI_CARR_CH,fc*MHz);
		Write_Amplitude(ORI_CARR_CH, (1023)*powf(amp*debug_CW_ZD_AMP/CW_ZD_AMP_Freq_Chart[fc-30]/1.77/1000.0,0.3));
		//Write_Amplitude(ORI_CARR_CH, (1023)*powf(amp*debug_CW_ZD_AMP/1.77/1000.0,0.3));
		Write_Phase(ORI_CARR_CH,0);
		
		Write_frequence(ORI_MODU_CH,2*MHz);
		Write_Amplitude(ORI_MODU_CH, 0);
		Write_Phase(ORI_MODU_CH,0);	
		
		set_dac_ch2(1200*powf(amp*debug_CW_ZD_AMP/CW_ZD_AMP_Freq_Chart[fc-30]/1.77/1000.0,0.7));
		//set_dac_ch2(1200*powf(amp*debug_CW_ZD_AMP/1.77/1000.0,0.7));
		//(/CW_AMP_Freq_Chart[fc-30])频率表
		//(*debug_CW_ZD_AMP) debug
		
		//////////////////////////////////////////////////////////
		PE43xx_changelevel(db);
		PE43xx_changelevel(db);
		
		Write_frequence(DELAY_CARR_CH,fc*MHz);
		Write_Amplitude(DELAY_CARR_CH, (1023)*powf(amp*debug_CW_DELAY_AMP/CW_DELAY_AMP_Freq_Chart[fc-30]/2/1000.0,0.3));
		//Write_Amplitude(DELAY_CARR_CH, (1023)*powf(amp*debug_CW_DELAY_AMP/2/1000.0,0.3));
		Write_Phase(DELAY_CARR_CH,Phase_2_AD9959(29.0+CW_PHASE[fc-30]+debug_CW_PHASE-cal_Phase(delay_t,fc)+sita) );
		//(+debug_CW_PHASE) debug
		
		Write_frequence(DELAY_MODU_CH,2*MHz);
		Write_Amplitude(DELAY_MODU_CH, 0);
		Write_Phase(DELAY_MODU_CH,Phase_2_AD9959(-cal_Phase(delay_t,2)));	
		
		set_dac_ch1(1609.65*powf(amp*debug_CW_DELAY_AMP/CW_DELAY_AMP_Freq_Chart[fc-30]/2/1000.0,0.7));
		//set_dac_ch1(1609.65*powf(amp*debug_CW_DELAY_AMP/2/1000.0,0.7));
		//(/CW_DELAY_AMP_Freq_Chart[fc-30])频率表
		//(*debug_CW_DELAY_AMP) debug
	}
	else //AM
	{
		Write_frequence(ORI_CARR_CH,fc*MHz);
		//Write_Amplitude(ORI_CARR_CH, 512*1.199757*debug_AM_AMP/AM_AMP_AMP_Chart[10-amp/100]/AM_AMP_Chart[fc-30]*powf(amp/1000.0,0.3));//3.2
		Write_Amplitude(ORI_CARR_CH, 512*1.199757*debug_AM_AMP/AM_AMP_Chart[fc-30]*powf(amp/1000.0,0.3));//3.2
		Write_Phase(ORI_CARR_CH,0);
		
		Write_frequence(ORI_MODU_CH,2*MHz);
		Write_Amplitude(ORI_MODU_CH, 1023*0.92*debug_AM_MODU_AMP*(ma/90.0)*powf(amp/1000.0,0.7));//3.2
		Write_Phase(ORI_MODU_CH,0);	
		
		set_dac_ch2(1120*0.88*powf(amp/1000.0,0.7));
		//////////////////////////////////////////////////////////////
		PE43xx_changelevel(db);
		PE43xx_changelevel(db);
		
		Write_frequence(DELAY_CARR_CH,fc*MHz);
		//Write_Amplitude(DELAY_CARR_CH, 512*1.395*debug_AM_AMP/AM_AMP_AMP_Chart[10-amp/100]/AM_AMP_Chart[fc-30]*powf(amp/1000.0,0.3));
		Write_Amplitude(DELAY_CARR_CH, 512*1.395*debug_AM_AMP/AM_AMP_Chart[fc-30]*powf(amp/1000.0,0.3));
		Write_Phase(DELAY_CARR_CH,Phase_2_AD9959(25.0+debug_AM_PHASE-cal_Phase(delay_t,fc)+sita));
		
		Write_frequence(DELAY_MODU_CH,2*MHz);
		Write_Amplitude(DELAY_MODU_CH, 1023*0.92*debug_AM_MODU_AMP*(ma/90.0)*powf(amp/1000.0,0.7));
		Write_Phase(DELAY_MODU_CH,Phase_2_AD9959(-cal_Phase(delay_t,2)));	
		
		set_dac_ch1(1120*0.88*powf(amp/1000.0,0.7));		
	}
	
}
void app_start()
{
	get_settings();
	printf("cw_am amp fc ma db t sita:%d %d %d %d %d %d %d\n",cw_am, amp, fc ,ma ,db, delay_t, sita);
	set_wave_config();
	set_wave_config();
}

void app_init()
{
	//init_relay();
	//AD9910_Init();
		//Init_AD9959();
	PE43xx_init();

	//AD9910_Amp_Pha_Freq_Set(1.0, 0.0, 100*KHz,0 );
//	si5351_Init();
//	si5351_setupPLL(SI5351_PLL_B, 31, 498915, 500035);
//	si5351_setupMultisynth(2, SI5351_PLL_B, 16, 0, 1);
//	si5351_setupRdiv(2, SI5351_R_DIV_1);
//	si5351_enableOutputs(0xFF);
	
	delay_init();
	Init_AD9959();
	PE43xx_changelevel(0);
	PE43xx_changelevel(0);
	//tune_zero_9959(0,1,1);
//	for (int i=0;i<10;i++)
//	{
//		Write_frequence(1,2*MHz);
//		Write_Amplitude(1, 1023);
//		Write_Phase(1,0);
//		
//		Write_frequence(0,30*MHz);
//		Write_Amplitude(0, 68);
//		Write_Phase(0,900);		
//	}
//	
//		for (int i=0;i<10;i++)
//	{
//		Write_frequence(3,30*MHz);
//		Write_Amplitude(3, 128+64-1);
//		Write_Phase(3,0);
//		
//		Write_frequence(2,2*MHz);
//		Write_Amplitude(2, 512-128-1);
//		//Write_Amplitude(2, 0);
//		Write_Phase(2,0);		
//	}
//	
//set_dac_ch2(1500);
	//variR_init();
	lv_init();                          // lvgl初始化
  lv_port_disp_init();                // 显示设备初始化
  lv_port_indev_init();               // 输入设备初始化
	
	setup_ui(&guider_ui);
	events_init(&guider_ui);

	printf("LCD ID:%x\r\n", lcddev.id);
	//AD9959_Sweep_Frequency(3, 1, 50000000, 1, 255, 0);
	//AD9959_SET_2FSK(3,10*KHz,20*KHz);
//	AD9959_Write_Frequence(2,50*MHz);
//	AD9959_Write_Amplitude(2,511);
//	AD9959_Write_Phase(2,0);
//	
//	AD9959_Write_Frequence(3,50*MHz);
//	AD9959_Write_Amplitude(3,511);
//	AD9959_Write_Phase(3,0);
//	AD9959_Set_Amplitude_Phase_Frequence(3,511, 0,10*KHz);
//	
//	AD9959_Write_Frequence(3,30*MHz);
//	AD9959_Write_Amplitude(3,256);
//	AD9959_Write_Phase(3,0);
//	
//	AD9959_Write_Frequence(1,30*MHz);
//	AD9959_Write_Amplitude(1,256);
//	AD9959_Write_Phase(1,180);

//	AD9959_Set_Amplitude_Phase_Frequence(3,511, 90,10*KHz);
//	AD9959_Set_Amplitude_Phase_Frequence(2,511, 60,10*KHz);

}

void app_main_loop()
{
	lv_task_handler();
}