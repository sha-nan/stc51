
//该板子上的点阵为8*8，只能显示简单的一些汉子，如果要显示真正的汉字
//通过取模软件取的可以选择16*16点阵的板子

#include<reg51.h>
#include<intrins.h>

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--定义要使用的IO口--//
#define COMMONPORTS		P0

//--列选通控制--//
unsigned char code TAB[8]  = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

//--点阵字码--//
unsigned char code CHARCODE[5][8]=
{
							0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, 
							0xC3,0xE7,0xE7,0xE7,0xE7,0xE7,0xC3,0xFF, 
							0x99,0x00,0x00,0x00,0x81,0xC3,0xE7,0xFF,
							0x99,0x99,0x99,0x99,0x99,0x81,0xC3,0xFF,
							0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}

/*******************************************************************************
* 函数名         : Hc595SendByte(unsigned char dat)
* 函数功能		   : 想74H595发送一个字节的数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
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
/*******************************************************************************
* 函数名         : main
* 函数功能		   : 主函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void main()
{	
 	unsigned char tab, j;
	unsigned int  i;

	while(1)
	{	
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
}
