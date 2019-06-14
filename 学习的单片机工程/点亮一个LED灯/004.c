#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar m;
void main()
{	
	m=0xfe;
	while(1)
	{	uint i,j;
		P2=m;
		for(i=100;i>0;i--)
			for(j=110;j>0;j--);
		m=_cror_(m,1);
	}
	
}void  main()

{

    uchar m= 0,n;
	uint  i,j = 0;


    while(1)                //程序死循环  

    {

        P2 = ~(0x01 << m++);     //P0等于1左移j位，并且j++

        for(i=1000;i>0;i--)
			for(j=110;j>0;j--);  //延时

        if(m == 8)                //如果j等于8，重新给j赋值0

        {
            j = 0;
		 
        }

     }

}