#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit led1=P2^0;
uchar code table[]={0x3f,0x06,0x5b,0x4f,
					0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,
					0x39,0x5e,0x79,0x71};
void delayms(uint);
void display(uchar,uchar);
uchar num,num1,num2,shi,ge;
void main()
{
	TMOD=0X11;
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	TH1=(65536-45872)/256;
	TL1=(65536-45872)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
	while(1)
	{
		display(shi,ge);
	}
}

void display(uchar shi,uchar ge)
{
	uchar i;
	for(i=0;i<2;i++)
	{
		switch(i)
		{
			case(0):LSA=0;LSB=0;LSC=0;break;
			case(1):LSA=1;LSB=0;LSC=0;break;
		}
		P0=table[i];
		delayms(5);
		P0=0x00;
	}
	
}

void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void T0_time()interrupt 1
{
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	num1++;
	if(num1==20)
	{
		num1=0;
		led1=~led1;
	}
	
}

void T1_time()interrupt 3
{
	TH1=(65536-45872)/256;
	TL1=(65536-45872)%256;
	num2++;
	if(num2==20)
		{
			num=0;
			num++;
			if(num==60)
				{
					num=0;
					shi=num/10;
					ge=num%10;
				}
		}
}