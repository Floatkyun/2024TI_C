#include "fft.h"

#define FFT_SIZE (4096)
#define FS (1000000.0)
#define MHz 1000000
#define KHz 1000

static uint16_t adc_buff[FFT_SIZE]={0};
static float32_t fft_output[FFT_SIZE]={0};
static float32_t fft_input[FFT_SIZE*2]={0};

static float32_t kernel_edge[3]={-1.0/2.0,1.0,-1.0/2.0};

static int DMA_flag=0;

void clear_DMA_flag()
{
	DMA_flag=0;
}

void set_DMA_flag()
{
	DMA_flag=1;
}

int get_DMA_flag()
{
	return DMA_flag;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	clear_DMA_flag();
}

void fft_set_fs(float32_t fs)//设置采样频率
{
	__HAL_TIM_SetAutoreload(&htim3,2-1);
	HAL_TIM_Base_Start(&htim3); 
	fs=2*fs;
	
	int fs_a=25*MHz/fs;
	int fs_b=(25*MHz-fs_a*fs);
	int fs_c=fs;
	
	si5351_Init();
	si5351_setupPLL(SI5351_PLL_A,31,498915, 500035);//校准外部时钟模块
	si5351_setupMultisynth(2,SI5351_PLL_A, fs_a,fs_b, fs_c);
	si5351_setupRdiv(2, SI5351_R_DIV_32);
	si5351_enableOutputs(0xFF);
		
	//printf("fsabc:%d,%d,%d,%d\n",(int)(fs/2),fs_a,fs_b,fs_c);
}

uint32_t fft_run_sig_measure()//单频检测
{
	
	fft_set_fs(1.024*MHz);
	set_DMA_flag();
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buff,FFT_SIZE);
	while(get_DMA_flag()){delay_us(1);}
	
	for (int i=0;i<FFT_SIZE;i++)
	{
		fft_input[2*i]=adc_buff[i];
		fft_input[2*i+1]=0;
	}
	//printf("begin\n");
	arm_cfft_f32(&arm_cfft_sR_f32_len4096,fft_input, 0, 1);
	arm_cmplx_mag_f32(fft_input, fft_output, FFT_SIZE);
	
	for (int i=0;i<FFT_SIZE;i++)
	{
	printf("ch:%d,%f,%d\n",adc_buff[i],fft_output[i],i);
	}

	uint32_t fund_freq =0;
	float32_t freq1_comp=0;
	
	arm_max_f32(&fft_output[1], FFT_SIZE-1, &freq1_comp, &fund_freq);
	fund_freq+=1;
	
	//arm_conv_f32(fft_output,FFT_SIZE,kernel_edge,3,fft_input);
	
//		for (int i=0;i<FFT_SIZE;i++)
//	{
//	printf("ch:%d,%f,%f,%d\n",adc_buff[i],fft_output[i],fft_input[i+1],i);
//	}
	
	if (fund_freq>FFT_SIZE/2)
	{
		fund_freq=FFT_SIZE-fund_freq;
	}

	//printf("fund_freq:%d,freq1_comp:%f\n",fund_freq,freq1_comp);

	//printf("fund_freqTHD:%d,%f,%f,%f,%f,%f,%f\n",fund_freq,freq1_comp,freq2_comp,freq3_comp,freq4_comp,freq5_comp,100.0*cal_THD(freq1_comp,freq2_comp,freq3_comp,freq4_comp,freq5_comp));
	return fund_freq;
}

void fft_measure()//只测FFT
	{
	fft_set_fs(1.024*MHz);
	set_DMA_flag();
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buff,FFT_SIZE);
	while(get_DMA_flag()){delay_us(1);}
	
	for (int i=0;i<FFT_SIZE;i++)
	{
		fft_input[2*i]=adc_buff[i];
		fft_input[2*i+1]=0;
	}
	//printf("begin\n");
		arm_cfft_f32(&arm_cfft_sR_f32_len4096,fft_input, 0, 1);
	arm_cmplx_mag_f32(fft_input, fft_output, FFT_SIZE);
}

float32_t fft_FM_decoder(uint32_t center_index,uint32_t peak_gap)//计算调频系数
{
	float32_t bessel_real[4]={fft_output[center_index],
	(fft_output[center_index+peak_gap]+fft_output[center_index-peak_gap])/2.0,
	(fft_output[center_index+2*peak_gap]+fft_output[center_index-2*peak_gap])/2.0,
	(fft_output[center_index+3*peak_gap]+fft_output[center_index-3*peak_gap])/2.0};
	
	float32_t bessel_loss[51]={0};
	
	for(int i=0;i<51;i++)
	{
		float32_t loss_temp=0;
		for(int j=0;j<4;j++)
		{
			loss_temp+=powf(bessel_real[j]/bessel_real[1]-bessel_chart[i][j],2);
		}
		bessel_loss[i]=loss_temp;
	}
	
	float32_t min_loss;
	uint32_t min_index;
	arm_min_f32(bessel_loss,51, &min_loss, &min_index);
	
	float32_t beta=min_index/10.0+1;
	return beta;
}

float32_t fft_AM_decoder(uint32_t center_index,uint32_t peak_gap)//计算调幅系数
{
	float32_t beta=(fft_output[center_index+peak_gap]+fft_output[center_index-peak_gap])/fft_output[center_index];
	return beta;
}