#include<reg52.h>
#define uint unsigned int
#define led1 P2						//宏定义（将P2口定义为led 后面就可以使用led代替P2口）
unit;i,j;
void delayxms(unit);				//声明子函数（注意声明变量类型）
void main()
{
	while(1)						//大循环
	{	
		led1=0xAA;					/*点亮发光二级管1，3，5，7*/	
		delayxms(100);				//延时100毫秒
		led1=0X55;					/*点亮发光二级管2，4，6，8*/
		delayxms(100);				//延时100毫秒
	}
}
void delayxms(uint xms)				//子函数体（注意声明变量类型）
{
	for(i=xms;i>0;i--)				//i=xms即延时约x毫秒
		for(j=110;j>0;j--);
}