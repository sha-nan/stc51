#include<reg52.h> //数码管显示I LOVE U.
#include<intrins.h> 
typedef unsigned int u16;
typedef unsigned char u8;
void delayxms(u16);
u16;u,j;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
u8 code smgduan[19]={
0x06,0x00,0x38,0x3f,
0x3e,0x79,0x00,0xbe};
void delayxms(u16 xms)
{
	for(u=xms;u>0;u--)
		for(j=110;j>0;j--);
}
void DigDisplay()
{
	u8 i;
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
		delayxms(1);  //间隔一段时间扫描	
		P0=0x00;      //消隐
	}
}
void main()
{	
	while(1)
	{	
		DigDisplay(); 		//数码管显示函数
	}
}
		
	/*while(1)       						//大循环
    {	u8 a,i,j;
        a=0xfe;    							//赋初值
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++)  					//左移一次
        {
            P2=a;       					//点亮小灯
			delayxms(500);
            a=_crol_(a,1); 					//将a变量循环左移一位
        }
        a=0x7f;
        for(j=0;j<1;j++) 
		for(i=0;i<8;i++) 					//右移一次
        {
            P2=a;       					//点亮小灯
			delayxms(500);
            a=_cror_(a,1); 					//将a变量循环右移一位
        }        
    }
	}		
}*/
