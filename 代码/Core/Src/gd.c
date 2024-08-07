#include "gd.h"

#define M_PI (3.14159265358979323846)

#define LR_MIN_1 0.5//һ���˻���Сѧϰ��
#define LR_MAX_1 50.0//һ���˻����ѧϰ��

#define LR_MIN_2 0//�����˻���Сѧϰ��
#define LR_MAX_2 0.5//�����˻����ѧϰ��

#define EPOCHES 50//�˻��ִ�

#define X_MAX 2048.0//x��ȡֵ���ֵ�޷�

static float32_t last_y;
static float32_t now_y;
static float32_t now_x;

static float32_t step;//����

static uint32_t epoch;//ѧϰ�ִ�

static float32_t ave_buff;
static float32_t ave_val;

__weak float32_t GD_get_y()//��ȡ��ǰy��ֵ
{
	return 0;
}

__weak void GD_set_x(float32_t x_)//���õ�ǰx��ֵ
{
	x_=x_;
}

uint32_t rng_get_random_num(void)
{
    uint32_t random_num = 0; /* ��������� */
    HAL_RNG_GenerateRandomNumber(&hrng, &random_num); /* ��������� */
    return random_num; /* ��������� */
}

uint32_t rng_get_random_num_range(uint32_t start,uint32_t stop)
{
    uint32_t random_num = 0; /* ��������� */
    HAL_RNG_GenerateRandomNumber(&hrng, &random_num); /* ��������� */
		random_num=random_num%(stop-start)+start;
    return random_num; /* ��������� */
}

float32_t cosine_annealing()//�����˻���
{
	if(epoch>2*EPOCHES)
	{
		return LR_MIN_2;
	}
	else if(epoch>EPOCHES)
	{
		return LR_MIN_2+0.5*(LR_MAX_2-LR_MIN_2)*(1.0+cosf(M_PI*(epoch-EPOCHES)/(EPOCHES*1.0)));
	}
	else
	{
		return LR_MIN_1+0.5*(LR_MAX_1-LR_MIN_1)*(1.0+cosf(M_PI*epoch/(EPOCHES*1.0)));
	}
}

void GD_init()//�ݶ��½�����ʼ��
{
	epoch=0;
	
	step=rng_get_random_num_range(0,32);;
	now_x=rng_get_random_num_range(0,X_MAX);
	
	GD_set_x(now_x);
	HAL_Delay(1);
	last_y=GD_get_y();
	
	now_x+=step;
	GD_set_x(now_x);
	HAL_Delay(1);
	now_y=GD_get_y();
}


void GD_step()//�ݶ��½���ǰ��һ��
{
	float32_t gradient=now_y-last_y;
	
	if(epoch>=2*EPOCHES&&epoch<3*EPOCHES)
	{
		ave_buff+=now_y;
	}
	else if (epoch==3*EPOCHES)
	{
		ave_val=ave_buff/50.0;
		printf("ave_val:%f\n",ave_val);
		ave_buff=0;
	}
	
	/**����Ҫ����������ؽ�����
	if (gradient>=500 && epoch>4.5*EPOCHES)
		{GD_init();
		printf("first_rebuild\n");
		}
	else if(ave_val>=1400 && epoch>4*EPOCHES)
	{
	GD_init();
	printf("second_rebuild\n");
	}
	else if(gradient<500 &&gradient>300 && epoch>3.5*EPOCHES||(ave_val<1000&&ave_val>900 && epoch>3*EPOCHES))
	{
		epoch=EPOCHES;
	}
	*/
	
	int sig;
	if (gradient==0 || step==0)
	{
		sig=1;
	}
	else
	{
	sig=-(gradient/fabsf(gradient))*(step/fabsf(step));
	}
	
	step=sig*cosine_annealing();
	
	now_x=now_x+step;
	
	now_x=fmod(now_x,X_MAX);
	
	if (now_x<0)
	{
		now_x+=X_MAX;
	}
	
	epoch++;
	
	last_y=now_y;
	GD_set_x(now_x);
	HAL_Delay(1);//�ȴ���Ӧ�ȶ�
	now_y=GD_get_y();
  //printf("now_y__phase:%d,%f,%d\n",now_y,step,(uint16_t)now_x);
}


