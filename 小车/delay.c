
void Delay10us(unsigned int t)		//@11.0592MHz
{
	unsigned char i;
	while(t)
	{
		i = 2;
		while (--i);
		t--;
	}
	
}
