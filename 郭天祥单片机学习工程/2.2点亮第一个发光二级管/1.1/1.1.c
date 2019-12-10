#include<reg52.h>
//#define led P2
sbit LED=P0^4;
void main()
{
	LED=1;
	while(1);
}