#include <reg51.h>

sbit LED = P0^1;
sbit SWITCH = P1 ^ 1;

void main()
{
	while(1)
	{
		if (1 == SWITCH)
		{
			LED = 1;
		}
		else if (0 == SWITCH)
		{
			LED = 0;
		}
	}
}