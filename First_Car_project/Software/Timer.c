#include <REGX52.H>

/*
电机使能
*/
sbit ENA = P1^2;
sbit ENB = P1^7;

/*
SG90舵机
*/
sbit PWM=P2^5;//舵机信号

unsigned int  counter=0;
unsigned int  compare=3;
unsigned int  EN_counter=0;
unsigned int  ENA_compare=60;
unsigned int  ENB_compare=60;

void Timer1Init(void)		//500微秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x33;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	EA=1;
	ET1=1;
	PT1=1;
}

void Timer2Init(void)		//100微秒@11.0592MHz
{
	T2MOD = 0;		//初始化模式寄存器
	T2CON = 0;		//初始化控制寄存器
	TL2 = 0xA4;		//设置定时初始值
	TH2 = 0xFF;		//设置定时初始值
	RCAP2L = 0xA4;		//设置定时重载值
	RCAP2H = 0xFF;		//设置定时重载值
	TR2 = 1;		//定时器2开始计时
	ET2=1;
	EA=1;
	PT2=0;
}

void Timer_T1(void) interrupt 3
{
	TL1 = 0x33;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值
	
	counter++;
	
	if(counter>40)
	{
		counter=0;
	}
	
	if(counter<compare)
	{
		PWM=1;
	}
	else
	{
		PWM=0;
	}
	
}

void EN_PWM() interrupt 5
{
	RCAP2L = 0xA4;		//设置定时重载值
	RCAP2H = 0xFF;		//设置定时重载值
	TF2=0;              //置位清零
	
	EN_counter++;
				
				if(EN_counter>100)
				{
					EN_counter=0;
				}
				
	if(EN_counter<ENA_compare)
	{
		ENA=1;
	}
	else
	{
		ENA=0;
	}
		if(EN_counter<ENB_compare)
		{
			ENB=1;
		}
		else
		{
			ENB=0;
		}
}

