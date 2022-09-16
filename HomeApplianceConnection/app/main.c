#include <reg51.h>
#include "global.h"

sbit SWITCH1 = P1 ^ 0;
sbit SWITCH2 = P1 ^ 1;
sbit SWITCH3 = P1 ^ 2;
sbit SWITCH4 = P1 ^ 3;
sbit SWITCH5 = P1 ^ 4;
sbit SWITCH6 = P1 ^ 5;

void main()
{
	int flag = 0;
	while(1)
	{
		if (flag == 0)
		{
			if(SWITCH1 == 0)
				SETBIT(P0,1); //LED
			else if(SWITCH1 == 1)
				CLRBIT(P0,1);
			
			if(SWITCH2 == 0)
				SETBIT(P2,1); //FAN
			else if(SWITCH2 == 1)
				CLRBIT(P2,1);
			
			if(SWITCH3 == 0)
				SETBIT(P0,4); //LIGHT
			else if(SWITCH3 == 1)
				CLRBIT(P0,4);			
			
			if(SWITCH4 == 0)
				SETBIT(P2,3); //A/C
			else if(SWITCH4 == 1)
				CLRBIT(P2,3);
		}
		if(SWITCH5 == 0 && flag == 0)
		{
			flag = 1;
			SETBIT(P0,1);
			SETBIT(P2,1);
			SETBIT(P0,4);
			SETBIT(P2,3);
		}
		else
			flag = 0;
		
		if(SWITCH6 == 0)
		{
			flag = 2;
			SWITCH5 = 1;
			CLRBIT(P0,1);
			CLRBIT(P2,1);
			CLRBIT(P0,4);
			CLRBIT(P2,3);
		}
		else
			flag = 0;
	}
}
