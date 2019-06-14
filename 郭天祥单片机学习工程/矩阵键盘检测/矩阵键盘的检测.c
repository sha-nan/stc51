#include<reg52.h>
typedef unsigned int u16;
typedef unsigned char u8;

//sbit LSA=P2^2;
//sbit LSB=P2^3;
//sbit LSC=P2^4;



u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
										 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值

void delay(u16 xms)//延时函数
{	u16 j,i;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void display(u8 num)
{
	P0=smgduan[num];
	delay(10);
}

void matrixkeyscan()
{
	u8 temp,key;
	
	P1=0XFE;
	temp=P1;
	temp=temp&0xf0;
	if (temp!=0xf0)
	{
		delay(10);
		temp=P1;
		temp=temp&0xf0;
			if (temp!=0xf0)
			{
				temp=P1;
				switch(temp)
				{
					case 0xee: key=0;
										 break;
					case 0xde: key=1;
										 break;
					case 0xbe: key=2;
										 break;
					case 0x7e: key=3;
										 break;
				}
				while(temp!=0xf0)
					{
						temp=P1;
						temp=temp&0xf0;
					}
						display(key);
			}
		}
	
		P1=0XFD;
	temp=P1;
	temp=temp&0xf0;
	if (temp!=0xf0)
	{
		delay(10);
		temp=P1;
		temp=temp&0xf0;
			if (temp!=0xf0)
			{
				temp=P1;
				switch(temp)
				{
					case 0xed: key=4;
										 break;
					case 0xdd: key=5;
										 break;
					case 0xbd: key=6;
										 break;
					case 0x7d: key=7;
										 break;
				}
				while(temp!=0xf0)
					{
						temp=P1;
						temp=temp&0xf0;
					}
						display(key);
			}
		}
			
	P1=0XFB;
	temp=P1;
	temp=temp&0xf0;
	if (temp!=0xf0)
	{
		delay(10);
		temp=P1;
		temp=temp&0xf0;
			if (temp!=0xf0)
			{
				temp=P1;
				switch(temp)
				{
					case 0xeb: key=8;
										 break;
					case 0xdb: key=9;
										 break;
					case 0xbb: key=10;
										 break;
					case 0x7b: key=11;
										 break;
				}
				while(temp!=0xf0)
					{
						temp=P1;
						temp=temp&0xf0;
					}
						display(key);
			}
		}
				P1=0XF7;
	temp=P1;
	temp=temp&0xf0;
	if (temp!=0xf0)
	{
		delay(10);
		temp=P1;
		temp=temp&0xf0;
			if (temp!=0xf0)
			{
				temp=P1;
				switch(temp)
				{
					case 0xe7: key=12;
										 break;
					case 0xd7: key=13;
										 break;
					case 0xb7: key=14;
										 break;
					case 0x77: key=15;
										 break;
				}
				while(temp!=0xf0)
					{
						temp=P1;
						temp=temp&0xf0;
					}
						display(key);
			}
	}
}

void main()
{
	P0=0;
//	LSA=0;LSB=0;LSC=0;
//	LSA=1;LSB=0;LSC=0;
//	LSA=0;LSB=1;LSC=0;
//	LSA=1;LSB=1;LSC=0;
//	LSA=0;LSB=0;LSC=1;
//	LSA=1;LSB=0;LSC=1;
//	LSA=0;LSB=1;LSC=1;
//	LSA=1;LSB=1;LSC=1;
	while(1)
	{
		matrixkeyscan();
	}
}