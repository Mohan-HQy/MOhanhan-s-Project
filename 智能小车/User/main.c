#include <REGX52.H>
#include <HCSR04.h>
#include <delay.h>
#include <Timer.h>
#include <track.h>
#include <Move.h>

/*
左右红外
*/
sbit LLED =P0^6;
sbit RLED =P0^7;

extern unsigned int compare;
unsigned int lenth;
unsigned int Lr;
unsigned int Ll;
unsigned int L=15;//小车与障碍物的预定距离---->15cm

void main(void)
{		
	Timer1Init();//定时器1
	Timer2Init();//定时器2
	ultra_init();//超声波模块初始化
	while(1)
	{
		lenth=get_distance();
		if(lenth>L||lenth<0)
		{
			if(LLED==RLED)
			{
				Track();
			}
			else
			{
				if(LLED==0)
				{
					Right_half_move();
				}
				else
				{
					Left_half_move();
				}
			}
		}
		else
		{
			Stop_move();
			Delay10us(4);
			Stop_move();
			Delay10us(10000);
			
			compare=1;
			Delay10us(20000);
			Lr=get_distance();
			Delay10us(10000);
			
			compare=5;
			Delay10us(40000);
			Ll=get_distance();
			Delay10us(10000);
			
			compare=3;
			
			if(Lr>Ll||Lr<0)
			{
				Right_move();
			}
			else
			{
				Left_move();
			}
			Delay10us(14000);
		}
	}
}

