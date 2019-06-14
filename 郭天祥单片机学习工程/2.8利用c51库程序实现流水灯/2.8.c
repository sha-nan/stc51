#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define COMMONPORTS		P0
sbit SRCLK=P3^6;

sbit SER=P3^4;
uchar aa;
uchar code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
uchar code CHARCODE[4][8]=
{

0x00,0x12,0x14,0x78,0x14,0x12,0x00,0x00,  //大
0x00,0x08,0x12,0x01,0xFF,0x00,0x10,0x08,   //小
0x7F,0x41,0x5D,0x55,0x5D,0x41,0x7F,0x00,  //回

{0x7C,0x48,0x48,0xFF,0x48,0x48,0x7C,0x00}  //中

};
void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}
void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}
void Hc595SendByte(uchar);
void delayms(uint);
void main()
{
	aa=0xfe;
	while(1)
	{ 	unsigned char tab, j;
	unsigned int  i;

	
	
		for(i= 0; i<50; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				Hc595SendByte(CHARCODE[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 4)
		{
			j = 0;
		}
	}
		P2=aa;
		delayms(500);
		aa=_cror_(aa,1);
	
}
void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}