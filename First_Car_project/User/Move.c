#include <REGX52.H>
/*
µç»ú
*/
sbit IN1 = P1^3;
sbit IN2 = P1^4;         
sbit IN3 = P1^5;
sbit IN4 = P1^6;

void Right_move()
{
	IN1=1;
	IN2=0;
	IN3=0;
	IN4=1;
}
void Right_move_half()
{
	IN1=0;
	IN2=1;
	IN3=1;
	IN4=1;
}

void Left_move()
{
	IN1=0;
	IN2=1;
	IN3=1;
	IN4=0;
}
void Left_move_half()
{
	IN1=1;
	IN2=1;
	IN3=1;
	IN4=0;
}

void Go_move()
{
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
}

void Stop_move()
{
	IN1=1;
	IN2=1;
	IN3=1;
	IN4=1;
} 

//void back_move()
//{
//	IN1=0;
//	IN2=1;
//	IN3=0;
//	IN4=1;
//}