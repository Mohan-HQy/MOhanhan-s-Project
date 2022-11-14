#include <REGX52.H>
#include "delay.h"

unsigned int matrixkey(void)
{  
	unsigned int keynumber=0;
	P1=0xF7;//第1列	
	if(P1_7==0){Delay10us(1500);while(P1_7==0);keynumber=1;}
	if(P1_6==0){Delay10us(1500);while(P1_6==0);keynumber=5;}
	if(P1_5==0){Delay10us(1500);while(P1_5==0);keynumber=9;}
	if(P1_4==0){Delay10us(1500);while(P1_4==0);keynumber=13;}
    P1=0xFB;//第2列	
	if(P1_7==0){Delay10us(1500);while(P1_7==0);keynumber=2;}
	if(P1_6==0){Delay10us(1500);while(P1_6==0);keynumber=6;}
	if(P1_5==0){Delay10us(1500);while(P1_5==0);keynumber=10;}
	if(P1_4==0){Delay10us(1500);while(P1_4==0);keynumber=14;}	
    P1=0xFD;//第3列	
	if(P1_7==0){Delay10us(1500);while(P1_7==0);keynumber=3;}
	if(P1_6==0){Delay10us(1500);while(P1_6==0);keynumber=7;}
	if(P1_5==0){Delay10us(1500);while(P1_5==0);keynumber=11;}
	if(P1_4==0){Delay10us(1500);while(P1_4==0);keynumber=15;}	
    P1=0xFE;//第4列	
	if(P1_7==0){Delay10us(1500);while(P1_7==0);keynumber=4;}
	if(P1_6==0){Delay10us(1500);while(P1_6==0);keynumber=8;}
	if(P1_5==0){Delay10us(1500);while(P1_5==0);keynumber=12;}
	if(P1_4==0){Delay10us(1500);while(P1_4==0);keynumber=16;}		
	return keynumber;
}