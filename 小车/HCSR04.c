#include <REGX52.H>
#include <delay.h>

#define C 15           //环境温度
#define MHZ  11.0592   //单片机晶振频率

sbit Trig=P0^0;
sbit Echo=P3^2;

void Timer0Init(void)		//计数器
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x09;		//设置定时器模式
	TL1 = 0x00;		//设置定时初始值
	TH1 = 0x00;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;        //定时器不会即开始
}

void ultra_init(void)//超声波
{
	Trig=0;
	Echo=0;
	Timer0Init();
}

int get_distance(void)
{
	unsigned char timeH,timeL;
	unsigned int distance,time;
	unsigned int time_counter=0;
	Trig=1;
	Delay10us(1);
	Trig=0;
	Echo=1;
	 while(!Echo)//等待
	 {
		time_counter++;
		 Delay10us(1);
		 if(time_counter>10000)
		 {
			return -1;//出错
		 }
	 }
	 time_counter=0;
     while(Echo)//等待
	 {
		time_counter++;
		Delay10us(1);
		 if(time_counter>10000)
		 {
			return -2;//出错
		 }
	 }
     timeH =TH0;
	 timeL =TL0;
	 TH0=0;//重置计数器
	 TL0=0;
     time=timeH*256+timeL;
	 if(time>70000)return -3;//出错
	 distance=time*(MHZ/12)/10000*170;//距离：CM
	 return distance;

}