#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
uchar num;
uchar code smgduan[]={0x30,0x38,0x3f,0x3e,0x79,0x6e,0x3f,0x3e};
void delayxms(uint);
void main()
{
	
	while(1)
	{
		LSA=1;
		LSB=0;
		LSC=0;
		for(num=0;num<8;num++)
		{
		P0=smgduan[num];
		delayxms(1000);
		}
	}
}
void delayxms(uint xms)
	{
		uint i,j;
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}