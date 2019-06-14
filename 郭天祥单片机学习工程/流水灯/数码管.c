#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define led P2
void delayxms(uint);
void main()
{
	while(1)
	{
	uchar i;
	led=0xfe;
	for(i=0;i<7;i++)
		{
			led=_crol_(led,1);			//Ñ­»·×óÒÆ
			delayxms(300);
		}
	for(i=0;i<7;i++)
		{
			led=_cror_(led,1);
			delayxms(300);
		}
	}
}

void delayxms(uint xms)
{	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}