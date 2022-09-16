#include <reg51.h>

sbit LED1 = P0^1;
sbit LED2 = P0^2;

sbit SWITCH1 = P1 ^ 1;
sbit SWITCH2 = P1 ^ 2;
sbit SWITCH3 = P1 ^ 3;

void main()
{
	while(1)
	{
		if (1 == SWITCH1)
		{
			LED1 = 1;
		}
		else if (0 == SWITCH1)
		{
			LED1 = 0;
		}
		
		if (1 == SWITCH2)
		{
			LED2 = 1;
		}
		else if (0 == SWITCH2)
		{
			LED2 = 0;
		}
		
		if (1 == SWITCH3)
		{
			LED1 = 1;
			LED2 = 1;
		}
		else if (0 == SWITCH3)
		{
			LED1 = 0;
			LED2 = 0;
		}
	}
}