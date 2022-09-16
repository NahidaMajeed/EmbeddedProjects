#include <reg51.h>
#include "global.h"

sbit SWITCH1 = P1 ^ 1;
sbit SWITCH2 = P1 ^ 2;

void main()
{
	
	while(1)
	{
		if (SWITCH1 == 0)
		{
			SETBIT(P2,1);
			CLRBIT(P2,4);
		}
		else if (SWITCH2 == 0)
		{
			CLRBIT(P2,1);
			SETBIT(P2,4);
			
		}
		else
		{
			CLRBIT(P2,1);
			CLRBIT(P2,4);
		}
	}
}
