#include<reg52.h>						//52系列单片机头文件

typedef unsigned int u16;	  //对数据类型进行声明
typedef unsigned char u8;

sbit LSA=P2^2;  //对单片机io口进行声明
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit pwm=P3^0;	//pwm信号输出
sbit jia=P3^2;	//角度增加按键i/o口
sbit jan=P3^3;  //角度减少按键i/o口

u8 count;	//0.5ms次数标识
u8 jd;		//角度标识
u8 code smgduan[]={0x3f,0x06,0x5b,0x4f,
									 0x66,0x6d,0x7d,0x07,
					         0x7f,0x6f,0x77,0x7c,
							   	 0x39,0x5e,0x79,0x71};//显示0~F的值

void delay(u16 i)	//延时函数
{
	u16 j,k;
	for(j=i;j>0;j--)
		for(k=110;k>0;k--);
}

void Time0_Init()	//定时器初始化
{
	TMOD=0X01;			//定时器0的工作方式为1
	IE=0X82;	//
	TH0=0XFE;
	TL0=0X33;	//11.0592MHz晶振，0.5ms
	TR0=1;	  //定时器开始
}

void Time0_Int() interrupt 1  //中断程序
{
	TH0=0XFE;					//重新赋值
	TL0=0X33;
	if(count<jd)			//判断0.5ms次数是否小于角度标识
		pwm=1;					//确实小于pwm输出高电平
	else
		pwm=0;					//大于则输出低电平
	count=(count+1);	//0.5ms次数加一
	count=count%40;	  //次数始终保持40，即保持周期为20ms
}

void keyscan()	//按键扫描
{
	if(jia==0)		//角度增加按键是否按下
	{
		delay(10);	//按下延时，消抖
		if(jia==0)	//确实按下
		{
			jd++;			//角度标识加1
			count=0;		//按键按下则20ms周期重新开始
      if(jd==6)
					jd=5;
			while(!jia);//等待按键释放
		}
	}
	
	if(jan==0)		//角度减小按键是否按下
	{
		delay(10);	//按键消抖
		if(jan==0)  //再次检测按键是否按下
		{
			jd--;			//角度标识减1
			count=0;
			if(jd==0)
				jd=1;
			while(!jan);	//等待按键释放
		}
	}
}

void display()	//数码管显示函数
{
	u8 bai,shi,ge;
	switch(jd)
	{
		case (1):						//为1，角度为0，前三个数码管显示000
					 bai=0;
					 shi=0;
					 ge=0;
					 break;
		
		case (2):
           bai=0;
					 shi=4;
					 ge=5;
					 break;
		
		case (3):
           bai=0;
					 shi=9;
					 ge=0;
					 break;
		
		case (4):
           bai=1;
					 shi=3;
					 ge=5;
					 break;
		
		case (5):						//为5，角度为180，前三个数码管显示180
           bai=1;
					 shi=8;
					 ge=0;
					 break;
	}

	LSA=0;
	LSB=1;
	LSC=0;		//显示第0位
	P0=smgduan[bai];	//发送段码
	delay(5);	//延时
	
	LSA=1;
	LSB=0;
	LSC=0;		//显示第1位
	P0=smgduan[shi];
	delay(5);
	
	LSA=0;
	LSB=0;
	LSC=0;		//显示第2位
	P0=smgduan[ge];
	delay(5);
	
}

void main()
{
	jd=1;					//角度标识
	count=0;			//0.5ms次数标识
	Time0_Init(); //定时器初始化
	while(1)
	{
		keyscan();	//按键扫描
		display();  //数码管显示
	}
}