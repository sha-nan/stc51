#include<reg52.h> 
#define uchar unsigned char
sbit LED=P2^0;
void main()
{
	uchar counter=0;
	LED=1;
	TMOD=0x01;
	TH0=0XB8;
	TL0=0X00;
	TR0=1;
	while(1)
	{	
		if(1==TF0)
		{
			TF0=0;
			TH0=0XB8;
			TL0=0X00;
			counter++;
			if(50==counter)
			{
				counter=0;
				LED=!LED;
			}
		}
	}
	
}