#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define led P2
uchar i,j;

void delayxms(uint);
void main()
{
	IT0=1;//跳变沿出发方式（下降沿）
	EX0=1;//打开INT0的中断允许。	
	EA=1;//打开总中断
	led=0x00;
	while(1)
	{
		if(1==j)
		{		
			for(i=0;i<7;i++)
			{			
				led=_crol_(led,1);	
				delayxms(300);
			}
		}
	}
}

void INT0_time()interrupt 0
{
		j++;
		if(1==j)
		{
			led=0xfe;
			for(i=0;i<7;i++)
			{
				led=_crol_(led,1);	
				delayxms(300);
			}
		}
		else if(2==j)
		{
			led=0xff;
			j=0;
		}
}

void delayxms(uint xms)
{	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}