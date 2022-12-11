#include <REGX52.H>
/*
串口初始化
*/
void UartInit(void)		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;		//设置定时初始值
	TH1 = 0xF4;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时
	EA  =1;         //定时器打开
	ES  =1;        //中断使能
}
/*
发送一字节
byte：被发送的内容

*/
void Uart_sendbyte(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}
//中断服务函数
/*
	void int0() interrupt 4
	{
		if(RI==1)
		{
		 P2=SBUF;					//判断SBUF中的数据为单片机接收的数据
		 Uart_sendbyte(SBUF);		//向电脑发送收到的数据
		 TI=0;
		 RI=0;
			
		}
	}
*/