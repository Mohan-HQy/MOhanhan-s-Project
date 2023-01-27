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
unsigned int  lenth,Lr,Ll;
unsigned int  L=10;//小车与障碍物的预定距离---->10cm

void main(void)
{		
	Timer1Init();
	Timer2Init();
	ultra_init();
	
	while(1)
	{	
		lenth=get_distance();
		if(lenth>=L)
		{
				if(LLED==RLED)
				{
					Track();
				}
				else
				{
					if(RLED==0)
					{
					 Left_move_half();
					}
					else
					{
					Right_move_half();
					}
				}
		}
		else
		{
			//停止
			Stop_move();
			
			Delay10us(25000);
			compare=1;					//右边
			Delay10us(15000);
			Lr=get_distance();
			Delay10us(15000);
			compare=5;					//左边
			Delay10us(15000);
			Ll=get_distance();
			Delay10us(15000);
			compare=3;					//复位向前
					
			        if(Lr>Ll||Lr<0)
					{
						Right_move();
					}
					else
					{
						Left_move();
					}
					Delay10us(13500);//差速转向
		}		
	}
}
