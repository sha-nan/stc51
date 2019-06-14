#include<reg52.h>			//52系列单片机头文件
#define uint unsigned int	//宏定义
sbit led1=P2^0;				//声明单片机P1口的第一位
void delayxms(uint);
void main()					//主函数
{
	while(1)
		{
			led1=0;						/*点亮第一个发光二级管*/
			delayxms(500);	
			led1=1;						/*关闭第一个发光二级管*/
			delayxms(1000);
		}
}
void delayxms(uint xms)
	{   uint i,j;
		for(i=xms;i>0;i--)			
			for(j=110;j>0;j--);
	}