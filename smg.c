#include <REGX52.H>

unsigned int L[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SMG_Location_number(unsigned char locate,unsigned int number)
{	
		switch(locate)
		{
			case 7 : P2_4=0; P2_3=0; P2_2=0; break;
			case 6 : P2_4=0; P2_3=0; P2_2=1; break;
			case 5 : P2_4=0; P2_3=1; P2_2=0; break;
			case 4 : P2_4=0; P2_3=1; P2_2=1; break;
			case 3 : P2_4=1; P2_3=0; P2_2=0; break;
			case 2 : P2_4=1; P2_3=0; P2_2=1; break;
			case 1 : P2_4=1; P2_3=1; P2_2=0; break;
			case 0 : P2_4=1; P2_3=1; P2_2=1; break;
		}
		P0=L[number];
}