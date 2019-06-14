#include<reg52.h>
#define uchar unsigned char
#define uiint unsigned int
sbit led1=P2^0;
uchar num;
void main()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	while(1)
	{
		if(num==40)
		{
			num=0;
			led1=~led1;
		}
	}
}

void T0_time() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	num++;
}
