#include <REGX52.H>
#include <HCSR04.h>
#include <delay.h>

/*
电机
*/
sbit IN1 = P3^4;
sbit IN2 = P3^5;
sbit IN3 = P3^6;
sbit IN4 = P3^7;

/*
循迹红外
*/
sbit AL =P2^0;
sbit BL =P2^1;
sbit CL =P2^2;
sbit DL =P2^3;
sbit EL =P2^4;

/*
左右红外
*/
sbit LLED =P0^6;
sbit RLED =P0^7;

/*
SG90舵机
*/
sbit PWM=P1^0;//舵机信号


void Timer1Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0xAE;		//设置定时初始值
	TH1 = 0xFB;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1;
	EA=1;
}



/*
		//前进
		IN1=1;//左边
		IN2=0;
		
		IN3=1;//右边
		IN4=0;
*/
/*
		//左转
		IN1=0;//左边
		IN2=1;
		
		IN3=1;//右边
		IN4=0;
*/
/*
		//右转
		IN1=1;//左边
		IN2=0;
		
		IN3=0;//右边
		IN4=1;
*/

unsigned int  lenth,Lr,Ll;
unsigned int  L=10;//10cm
unsigned int counter=0,compare=10;


void main(void)
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	ultra_init();
	Timer1Init();
	while(1)
	{	
		a=AL;
		b=BL;
		c=CL;
		d=DL;
		e=EL;
		lenth=get_distance();
		if(lenth>L)
		{
				if(LLED==RLED)
				{
								IN1=1;//左边//前进
								IN2=0;
								IN3=1;//右边
								IN4=0;
								if(a+b>d+e)//黑线在左边
								{
									//左转
									IN1=0;//左边
									IN2=1;
									IN3=1;//右边
									IN4=0;
								}
								else if(a+b<d+e)//黑线在右边
								{
									//右转
									IN1=1;//左边
									IN2=0;
									IN3=0;//右边
									IN4=1;
								}
								else//黑线偏中
								{
									//前进
									IN1=1;//左边
									IN2=0;
									IN3=1;//右边
									IN4=0;	
								}
				}
				else
				{
					if(RLED==0)
					{
						//左转
						IN1=1;//左边
						IN2=1;
						
						IN3=1;//右边
						IN4=0;
					}
					else
					{
						//右转
						IN1=1;//左边
						IN2=0;
						
						IN3=1;//右边
						IN4=1;
					}
				}
		}
		else
		{
			//停止
			IN1=1;//左边
			IN2=1;			
			IN3=1;//右边
			IN4=1;
			
			Delay10us(15000);
			compare=4;//右边
			Delay10us(25000);
			Lr=get_distance();
			Delay10us(25000);
			compare=15;//左边
			Delay10us(25000);
			Ll=get_distance();
			Delay10us(25000);
			compare=10;//复位向前
					if(Lr>Ll||Lr<0)
					{
						//右转
						IN1=1;//左边
						IN2=0;	
						IN3=0;//右边
						IN4=1;
					}
					else
					{
						//左转
						IN1=0;//左边
						IN2=1;
						IN3=1;//右边
						IN4=0;
					}
					Delay10us(33500);
		}  
	}
}

void Timer_T1(void) interrupt 3
{
	TL1 = 0xAE;		//设置定时初始值
	TH1 = 0xFB;		//设置定时初始值
	if(counter<compare)
	{
		PWM=1;
	}
	else
	{
		PWM=0;
	}
	counter++;
	if(counter>200)
	{
		counter=0;
	}

}