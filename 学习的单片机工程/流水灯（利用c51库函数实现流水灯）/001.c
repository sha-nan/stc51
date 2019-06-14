#include<reg51.h>  							//51单片机头文件
#include<intrins.h> 						//包含有左右循环移位子函数的库
#define uint unsigned int    				//宏定义
#define uchar unsigned char 				//宏定义
void delay(uint);
void main()            						//主函数
{
    uchar a,i,j;
    while(1)        						//大循环
    {
        a=0xfe;    							//赋初值
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++)  					//左移一次
        {
            P2=a;       					//点亮小灯
			delay(1000);
            a=_crol_(a,1); 					//将a变量循环左移一位
        }
        a=0x7f;
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++) 					//右移一次
        {
            P2=a;       					//点亮小灯
			delay(1000);
            a=_cror_(a,1); 					//将a变量循环右移一位
        }        
    }
}
void delay(uint z)  						//延时函数,z的取值为这个函数的延时ms数，如delay(200);大约延时200ms.
{                   						//delay(500);大约延时500ms.
    uint x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);    
}