#include "gd.h"

#define M_PI (3.14159265358979323846)

#define LR_MIN_1 0.5//一阶退火最小学习率
#define LR_MAX_1 50.0//一阶退火最大学习率

#define LR_MIN_2 0//二阶退火最小学习率
#define LR_MAX_2 0.5//二阶退火最大学习率

#define EPOCHES 50//退火轮次

#define X_MAX 2048.0//x轴取值最大值限幅

static float32_t last_y;
static float32_t now_y;
static float32_t now_x;

static float32_t step;//步进

static uint32_t epoch;//学习轮次

static float32_t ave_buff;
static float32_t ave_val;

__weak float32_t GD_get_y()//获取当前y轴值
{
	return 0;
}

__weak void GD_set_x(float32_t x_)//设置当前x轴值
{
	x_=x_;
}

uint32_t rng_get_random_num(void)
{
    uint32_t random_num = 0; /* 随机数变量 */
    HAL_RNG_GenerateRandomNumber(&hrng, &random_num); /* 生成随机数 */
    return random_num; /* 返回随机数 */
}

uint32_t rng_get_random_num_range(uint32_t start,uint32_t stop)
{
    uint32_t random_num = 0; /* 随机数变量 */
    HAL_RNG_GenerateRandomNumber(&hrng, &random_num); /* 生成随机数 */
		random_num=random_num%(stop-start)+start;
    return random_num; /* 返回随机数 */
}

float32_t cosine_annealing()//余弦退火函数
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

void GD_init()//梯度下降法初始化
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


void GD_step()//梯度下降法前进一步
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
	
	/**有需要在这里添加重建条件
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
	HAL_Delay(1);//等待响应稳定
	now_y=GD_get_y();
  //printf("now_y__phase:%d,%f,%d\n",now_y,step,(uint16_t)now_x);
}


