#include<reg52.h>
unsigned int num=0;//计数
sbit WAVE=P1^0;/
void init()
{
	TMOD=0x01;	//设置定时器0的工作方式为1（m0m1为01）
	TH0=(65536-50000)/256;	//装初值12M晶振，定时50ms
	TL0=(65536-50000)%256;
	EA=1;			//开总中断
	ET0=1;		//开定时器0中断	
	TR0=1;		//启动定时器0
}
void main()
{
	init();//定时器初始化
	while(1)
	{
		if(num==10)//即10次翻转一次电平值
		{
			num=0;
			WAVE=~WAVE;//产生1hz方波
		}
	}
}
	
void T0_time()interrupt 1
{
	TH0=(65536-50000)/256;	//装初值12M晶振，定时50Ms
	TL0=(65536-50000)%256;
	num++;//计数次，计10次即为500ms
}