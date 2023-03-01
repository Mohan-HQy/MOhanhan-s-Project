#include <REGX52.H>
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

//unsigned char a;
//unsigned char b;
//unsigned char c;
//unsigned char d;
//unsigned char e;

//void Track()
//{							
//							if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1)          //退出循迹模式       全亮都为11111
//								{		
//									ENA_compare=50;                        //左电机初始转速
//									ENB_compare=50;									//右电机初始转速
//									Go_move();
//								}
//							if(AL==0&&BL==0&&CL==0&&DL==0&&EL==0)          //悬空       全灭都为00000
//							{
//									
//									ENA_compare=50;                        			//左电机初始转速
//									ENB_compare=50;									//右电机初始转速
//									Stop_move();
//							}
//							else
//							{
//								
//								a=AL;
//								b=BL;
//								c=CL;
//								d=DL;
//								e=EL;	
//									if(a+b>d+e)//黑线在左边
//                                       {
//												ENA_compare=40;                        			//左电机初始转速
//												ENB_compare=40;									//右电机初始转速										
//												Left_move();               //左转
//				
//											
//										}
//									if(a+b<d+e)//黑线在右边
//										{
//											    ENA_compare=40;                        			//左电机初始转速
//											    ENB_compare=40;									//右电机初始转速
//											    Right_move();												//右转
//										}
//									if((a&&b&&d&&e)&&!c)
//									{
//											    ENA_compare=25;                        			//左电机初始转速
//											    ENB_compare=25;									//右电机初始转速
//											    Go_move();               //直行										
//									
//									}
//							}	
//}

void Track()   
{	

	if(AL==1&&BL==1&&CL==0&&DL==1&&EL==1)      //小车两边都接收到红外线黑线在中间小车直行       00100
		{
			Go_move();			
		}
	else if(AL==1&&BL==0&&DL==1&&EL==1)          //小车右边扫描到黑线（轻微偏左）  小车应该向右移动  10111
		{                                           
			ENA_compare=60;			                        //左电机初始转速
			ENB_compare=25;          			              //右电机初始转速
			Go_move();
		}				
	else if(AL==1&&BL==1&&DL==0&&EL==1)          //小车左边扫描到黑线（轻微偏右） 小车应该向左移动     11101
		{			
			ENA_compare=25;                        //左电机初始转速
			ENB_compare=60;                        //右电机初始转速
			Go_move();
		}
	else if(AL==0&&BL==1&&DL==1&&EL==1)  		   //小车右边扫描到黑线（转小圈）  小车应该向右移动  01111
		{							
			ENA_compare=35;                        //左电机初始转速
			ENB_compare=35;                        //右电机初始转速
			Right_move();
			while(BL==1);
		}
	else if(AL==0&&BL==0&&EL==1)  		   //小车右边扫描到黑线（转小圈）  小车应该向右移动  00111
		{				
			ENA_compare=40;                        //左电机初始转速
			ENB_compare=40;                        //右电机初始转速
			Right_move();
			while(CL==1);
		}					
	else if(AL==1&&BL==1&&DL==1&&EL==0)      //小车左边扫描到黑线（转小圈）  小车应该向左移动  11110
		{			
			ENA_compare=35;                        //左电机初始转速
			ENB_compare=35;                        //右电机初始转速
			Left_move();
			while(DL==1);
		}
	else if(AL==1&&DL==0&&EL==0)      //小车左边扫描到黑线（转小圈）  小车应该向左移动  11100
		{			
			ENA_compare=40;                        //左电机初始转速
			ENB_compare=40;                        //右电机初始转速
			Left_move();
			while(CL==1);
		}
	else
	{
			if(AL==0&&BL==0&&CL==0&&DL==0&&EL==0)          //退出循迹模式       全灭都为11111
			{
				
				ENA_compare=50;                        //左电机初始转速
				ENB_compare=50;                        //右电机初始转速
				Stop_move();
			}
			if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1)          //退出循迹模式       全灭都为11111
			{
				
				ENA_compare=50;                        //左电机初始转速
				ENB_compare=50;                        //右电机初始转速
				Go_move();
			}
	}
	
	
}

