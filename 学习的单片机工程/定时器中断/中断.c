#include<reg52.h>
#define uint unsigned int
#define uhar unsigned char
sbit led=P2^1;
uchar; num;
void main()
	{
		TMOD=0x01;	//设置定时器0的工作方式为1（m0m1为01）
		TH0=0x4c;	//装初值11.0592M晶振，定时50ms
		TL0=0x00;
		EA=1;		//开总中断
		ET0=1;		//开定时器0中断	
		TR0=1;		//启动定时器0
		while(1)	//程序停止在这里等待中断发生
		{
			if(num==20)		//如果到了20次，说明1秒的时间到
				{
					num=0;	//然后把num清零，重新计算20次
					led=~led;//让法光管状态取反
				}	
		}
	}
	
void T0_time()interrupt 1
	{
		TH0=0x4c;		//重装初值
		TL0=0x00;
		num++;			//num每加1次，判断一次是否到达20次
	}