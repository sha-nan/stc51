#include<reg52.h>		//52单片机系列头文件
#define uchar unsigned char//宏定义
#define uint unsigned int

sbit LSA=P2^2;//控制138译码器
sbit LSB=P2^3;
sbit LSC=P2^4;

void delayxms(uint);//延时函数声明
void saomiao(uchar,uchar);//数码管扫描函数声明
uchar num,num1;//数据类型声明
uchar shi,ge;//数据类型声明

uchar code table[]={0x3F,0x06,0x5B,0x4F,
					0x66,0x6D,0x7D,0x07,
					0x7F,0x6F,0x77,0x7C,
					0x39,0x5E,0x79,0x71};//显示0~f的值


void main()	//主函数
{
	TMOD=0X01;//设置定时器0的为工作方式1（0000 0001）
	TH0=(65536-45872)/256;//装初值
	TL0=(65536-45872)%256;
	EA=1;//开总中断
	ET0=1;//开定时器0中断
	TR0=1;//启动定时器0
	while(1)
	{
		saomiao(shi,ge);
	}
	
	
	
}

void saomiao (uchar shi,uchar ge)//显示子函数
{	
	LSA=1;LSB=0;LSC=0;//开启第二个数码管
	P0=table[shi];//送段选数据
	delayxms(5);//延时5毫秒
	LSA=0;LSB=0;LSC=0;//开启第一个数码管
	P0=table[ge];//送入段选数据
	delayxms(5);//延时5毫秒
}

void delayxms(uint xms)//延时函数
{
	uint i,j;
	for (i=xms;i>0;i--)
		for(j=110;j>0;j--);//i=xms即延时约xms毫秒
}

void T0_time() interrupt 1//中断服务程序（定时器0的中断序号是1）
{
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;//重装初值
	num1++;
	if(num1 == 20)//如果到了20次，说明一秒的时间到
	{
		num1=0;//然后把num1清0，重新计20次
		num++;
		if(num == 60)//这个数用来送数码管显示，到60后归0 
			num=0;
		shi=num/10;//把一个两位数分离后，分别送入数码管显示
		ge=num%10;//十位和个位
		
	}
}