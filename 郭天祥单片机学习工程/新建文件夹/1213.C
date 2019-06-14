#include<reg52.h>
#include<intrins.h> 
#define uint unsigned int;
#defind uchar unsigned char;
void delayxms(uint);
uint u,j;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
u8 code smgduan[]={0x7f};
void delayxms(uint xms)
{
	for(u=xms;u>0;u--)
		for(j=110;j>0;j--);
}
void DigDisplay()
{
	uchar i;
	for(i=0;i<2;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(1):LSA=0;LSB=0;LSC=0; break;//显示第0位
			
		}		
		P0=smgduan[i];//发送段码
		delayxms(500);  //间隔一段时间扫描	
		P0=0x00;      //消隐
	}
}
void main()
{	
	while(1)
	{	
		DigDisplay(); 		//数码管显示函数
	}
}