#include<reg52.h>	//52系列单片机头文件
#include<intrins.h>
#define uint unsigned int//对数据类型进行声明
#define uchar unsigned char
#define led P2
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P3^1;//定义P31口是k1
sbit k2=P3^0;
uchar ;num;
uchar code smgduan[]={0x30,0x38,0x3f,0x3e,0x79,0x6e,0x3f,0x3e};
uint i,j;
void delayxms(uint xms)//延时函数，输入xms毫秒即延时xms
	{	
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	
void DigDisplay()//动态数码管扫描函数，循环扫描8个数码管显示
{
	uchar i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(7):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(6):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(5):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(3):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(2):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(1):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
			
		}		
		P0=smgduan[i];//发送段码
		delayxms(500);  //间隔一段时间扫描	
		P0=0x00;      //消隐
	}
}


void key()//按键处理函数，判断按键k1是否按下
{
	
		if(k1==0);//检测k1是否按下
		{
			delayxms(10);//消除抖动一般大约10ms
			if(k1==0)//再次判断按键是否按下
				{	
					uchar i;
					led=0xfe;
					for(i=0;i<7;i++)
						{
							led=_crol_(led,1);			//循环左移
							delayxms(100);
						}
				
					for(i=0;i<7;i++)
						{
							led=_cror_(led,1);//循环右移
							delayxms(100);//延时100ms
						}
				while(!k1);
				}
		
		}
		
		if(k2==0);
		{
			delayxms(10);
			if(k2==0)
			{
				DigDisplay();
			}
		while(!k2);			
		}
		
}


void main()
{
	while(1)
		{
				key();//按键处理函数
			
		}
}