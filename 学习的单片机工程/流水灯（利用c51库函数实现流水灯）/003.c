#include<reg52.h>
#include<intrins.h>
#define unit unsigned int
#define uchar unsigned char
void delayms(unit);
uchar aa;
void main()
{
	aa=0x2fe;
	while(1)
	{
		P2=aa;
		delayms(500);
		aa=_crol_(aa,1);
	}
}
void delayms(unit xms)
{
	unit i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}