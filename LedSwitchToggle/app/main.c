#include <reg51.h>
#include "global.h"


sbit LED = P0^1;
sbit SWITCH = P1 ^ 1;

void main()
{
	while(1)
	{
		if (SWITCH == 0)
		{
			while(SWITCH == 0);
				LED = ~LED;
		}
	}
}
