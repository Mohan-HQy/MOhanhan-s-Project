#include <REGX52.H>
#include <smg.h>

sbit MCN=P1^0;

unsigned int counter=0,compare=100,speed,key,a=0;

void UartInit(void)		//9600bps@11.0592MHz-----先
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;		//设置定时初始值
	TH1 = 0xFD;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时
	EA=1;           //打开总中断
	ES=1;           //中断使能
	PS=1;           //优先级
}

void Timer0Init(void)		//10微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x91;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
}


void main()
{
	UartInit();
	Timer0Init();
	while(1)
	{
		if(a==0) compare=0;
		else if(speed==0) compare=30;
		else if(speed==1) compare=65;
		else if(speed==2) compare=100;
		SMG_Location_number(1,speed+1);
	}
}

void motor_PWM(void) interrupt 1// PWM
{	
	TL0 = 0x91;		                        //设置定时初始值
	TH0 = 0xFF;		                        //设置定时初始值
		if(counter <compare)   MCN=1;	   //on	
		else                   MCN=0;      //off 
		counter++;	
	    if(counter>100)        counter=0; 
}

void blue_teeth(void) interrupt 4
{
	key=SBUF;
	if(RI==1)
	{
		if(key==0xff)
		{
			speed+=1;                        //换挡
		}
		if(key==0xee)
		{
			a = ~a;                         //电机开关
		}
		RI=0;
	}
	speed%=3;
	
}