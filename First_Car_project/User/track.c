#include <REGX52.H>
#include <Timer.h>
#include <Move.h>

/*
循迹红外
*/
sbit AL =P2^0;
sbit BL =P2^1;
sbit CL =P2^2;
sbit DL =P2^3;
sbit EL =P2^4;

extern unsigned int ENA_compare;
extern unsigned int ENB_compare; 
extern unsigned int EN_counter;
extern unsigned int compare;

void Track()   //1为灭 0为亮   灭1   亮0     检测到黑线为灭1   
{
	
	if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1) 							//小车悬空      灯全灭都为11111
		{
			ENA_compare=75;                        //左电机初始转速
			ENB_compare=75;                       //右电机初始转速
			Stop_move();
		}	
		
		
	if(AL==1&&BL==0&&CL==1&&DL==1&&EL==1)  //小车右边扫描到黑线（轻微偏左）  小车应该向右移动  10111
		{
			ENA_compare=30;                           //左电机初始转速
			ENB_compare=15;                       //右电机初始转速
			Go_move();
		}
		
	if(AL==0&&BL==1&&CL==1&&DL==1&&EL==1)  //小车右边扫描到黑线（转小圈）  小车应该向右移动  01111
		{
			
			ENA_compare=25;                           //左电机初始转速
			ENB_compare=60;                       //右电机初始转速
			Go_move();
			
		}
		
	if(AL==1&&BL==1&&CL==1&&DL==0&&EL==1)  //小车左边扫描到黑线（轻微偏右） 小车应该向左移动     11101
		{
			
			ENA_compare=15;                           //左电机初始转速
			ENB_compare=30;                       //右电机初始转速
			Go_move();
		}		
		
		if(AL==1&&BL==1&&CL==1&&DL==1&&EL==0)  //小车左边扫描到黑线（转小圈）  小车应该向左移动  11110
		{
			
			ENA_compare=60;                           //左电机初始转速
			ENB_compare=25;                       //右电机初始转速
			Go_move();
			
		}	
		
		
	if(AL==1&&BL==1&&CL==0&&DL==1&&EL==1)  //小车两边都接收到红外线黑线在中间小车直行      全亮都为00100
		{
			
			ENA_compare=75;                        //左电机初始转速
			ENB_compare=75;                       //右电机初始转速
			Go_move();			
		}
}

