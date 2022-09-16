#include <reg51.h>
#include "global.h"
#include "robot.h"

sbit SWITCH1 = P1 ^ 0;
sbit SWITCH2 = P1 ^ 1;
sbit SWITCH3 = P1 ^ 2;
sbit SWITCH4 = P1 ^ 3;
sbit SWITCH5 = P1 ^ 4;


void main()
{
	SETBIT(P2,BIT2); //ENABLE
	robotStop();
	while(1)
	{
			if(SWITCH1 == 0)
				robotForward();
			
			if(SWITCH2 == 0)
				robotBackward();
			
			if(SWITCH3 == 0)
				robotLeft();
			
			if(SWITCH4 == 0)
				robotRight();
			
			if(SWITCH5 == 0)
				robotStop();
	}
}
