#include<reg52.h>
#include<intras.h>
#define uint unsigned int
#define uchar unsigned char
sbit beep=P1^5;
void delayxms(uint);
void main()
{
	while(1)
	{
		beep=~beep;
		delayxms(1);
	}
}
void delayxms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=55;j>0;j--);
}