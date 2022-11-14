#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "matrixkeyboard"
unsigned char key;
unsigned int input,count;
unsigned int i,b=1,c=2;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord");
		LCD_ShowString(2,1,"0000");
	while(1)
	{   key=matrixkey();
		if(key)
		{
			if(key<=10)//0~9
			{	
				if(count<4)
				{
				    input*=10;//Êý×Ö×óÒÆ
					input+=key%10;				
					count ++;
				}
					LCD_ShowNum(2,1,input,4);
				
			}
					if(key==11)
					{
					   if(input==4399)//ÃÜÂë/ÃÜÂëÕýÈ·
					   {
							LCD_ShowString(1,12,"right");
						    while(b)
							{
								i=1000;
								while(i--)
								{
										P2_5=0;
										Delay10us(15);
										P2_5=1;
										Delay10us(5);
								}
								P2_5=1;
									Delay10us(250);
								b--;
	                        }
					   }
					   else
					   {
					        LCD_ShowString(1,12,"Error");//ÃÜÂë´íÎó
						    input=0;
						    count=0;
						    LCD_ShowNum(2,1,input,4);
						    while(c)
							{
								i=100;
								while(i--)
								{
										P2_5=0;
										Delay10us(45);
										P2_5=1;
										Delay10us(5);
																			
								}
								P2_5=1;
								Delay10us(750);
								c--;
	                        }
					   }
					   }
					}		
		}
	}

