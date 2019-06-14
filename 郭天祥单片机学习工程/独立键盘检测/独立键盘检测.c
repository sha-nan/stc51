#include<reg52.h>					//52系列单片机头文件

#define uint unsigned int //宏定义,数据类型
#define uchar unsigned char

sbit LSA=P2^2;		//寄存器声明
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

uchar code smgduan[]={0x3F,0x06,0x5B,0x4F,
											0x66,0x6D,0x7D,0x07,
											0x7F,0x6F,0x77,0x7C,
											0x39,0x5E,0x79,0x71};//显示0~F的值

void delayxms(uint);			//延时函数声明
uchar numt0,num;					//数据类型声明
void display(uchar numdis)//数码管显示函数
{
	uchar shi,ge;						//数据类型声明
	shi=numdis/10;					//把一个两位数分离后，分别送入数码管显示
	ge=numdis%10;						//十位和个位
	LSA=1;
	LSB=0;
	LSC=0;									//将第二位数码管点亮
	P0=smgduan[shi];
	delayxms(5);						//延时5毫秒
	LSA=0;
	LSB=0;
	LSC=0;									//点亮第一位数码管
	P0=smgduan[ge];
	delayxms(5);						//延时5毫秒
}

void delayxms(uint xms)		//延时函数
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);		//延时约xms毫秒
}

void init()				//初始化函数
{
	TMOD=0X01;			//设置定时器0为工作方式1
	TH0=0X4C;				//装初值50毫秒中断一次
	TL0=0X00;
	EA=1;						//开总中断
	ET0=1;					//开定时器0中断
}

void key()							//按键处理函数
{
	if(k1==0)							//检测按键1是否按下
	{
		delayxms(10);				//按键去抖
		if(k1==0)						//再次检测按键1是否按下
		{
			num++;						//num自增1
			if(num==60)				//当num到60时重新归0
			num=0;
			while(!k1);				//等待按键释放
		}
	}
	
	if(k2==0)							//检测按键2是否按下
	{
		delayxms(10);				//按键去抖，约10毫秒
		if(k2==0)						//再次检测按键2是否按下
		{
			if(num==0)				//当num到0时重新回归60
				num=60;
				num--;					//nun减一
				while(!k2);			//等待按键释放
		}
	}
	
	if(k3==0)							//检测按键3是否按下
	{
		delayxms(10);				//延时10毫秒，去除按键抖动
		if(k3==0)						//再次检测按键三是否按下
			{
				num=0;					//num清零
				while(!k3);			//等待按键释放
			}
	}
	
	if(k4==0)							//检测按键4是否按下
	{
		delayxms(10);				//延时约10毫秒，去除抖动
		if(k4==0)						//再次检测按键4是否落下
		{	
			while(!k4);				//等待按键4释放
			TR0=~TR0;					//启动或停止定时器0
		}
	}
}

void main()				//主函数
{
	init();					//调用初始化函数
	while(1)
	{
		key();				//调用按键处理函数
		display(num); //调用数码管扫描函数
	}
}

void t0_time()interrupt 1	//中断函数
{
	TH0=0X4C;								//重装初值
	TL0=0X00;
	numt0++;
	if(numt0==20)						//如果numt0自增到20，表明1秒的时间已到
	{
		numt0=0;							//然后把numt0清零，重新计时
		num++;
		if(num==60)						//如果num自增到60，num清零
		num=0;
	}
}