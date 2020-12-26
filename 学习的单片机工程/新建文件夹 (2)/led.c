////芯片A程序
//#include <reg52.h>
//#define uint unsigned int
//#define uchar unsigned char
//	
//uint num=0;	//计数
//uchar i=0;

//void time0_init()
//{
//	TMOD=0X01;
//	TH0=(65535-50000)/256;//定时50ms
//	TL0=(65535-50000)%256;
//	TR0=1;
//	ET0=1;
//	EA=1;//打开全局中断
//}
//	
//void uart_init()//串口初始化函数
//{
//	TMOD=0X20;//设置定时器T1为工作方式2，8位自动重装载 作用是产生波特率
//	TH1=0XFD;//设置波特率为9600bps
//	TL1=0XFD;
//	TR1=1;//开启定时器
//	PCON=0X00;
//	SCON=0X50; //工作方式1，波特率9600bit/s,允许接收
//}
//void main()
//{
//	time0_init();//定时器初始化
//	uart_init();//串口初始化
//	while(1)
//	{
//		if(num==20)//计数20次到1s
//		{
//			num=0;
//			i=P1;//读取P1口8位数据
//			SBUF=i;//发送数据
//			while(TI==0);//等待发送完成
//			TI=0;//清标志
//		}
//	}
//}

//void Timer0() interrupt 1 //定时器0中断（计数20次即1s）
//{
//	TH0=(65535-50000)/256;//定时50ms
//	TL0=(65535-50000)%256;
//	num++;
//}

//芯片B程序
#include <reg52.h>
#define uchar unsigned char

uchar j=0;//串口接收到的数据

void uart_init()//串口初始化函数
{
	TMOD=0X20;//设置定时器T1为工作方式2，8位自动重装载 作用是产生波特率
	TH1=0XFD;//设置波特率为9600bps
	TL1=0XFD;
	TR1=1;//开启定时器
	PCON=0X00;
	SCON=0X50; //工作方式1，波特率9600bit/s,允许接收
}

void main()
{
	uart_init();//串口初始化
	while(1)
	{
			while(!RI);//等待接收完成
		  RI=0;//清标志
			j=SBUF;//读取接收到的数据
		  P2=j;//将8位数据进行点灯
	}
}
