#include <reg51.h>
#include "global.h"
#include "stepper.h"


sbit SWITCH1 = P1 ^ 0;
sbit SWITCH2 = P1 ^ 1;

void main()
{
	while(1)
	{
		if(SWITCH1 == 0)
			StepperClockwise();
		if(SWITCH2 == 0)
			StepperAntiClockwise();
	
	}
}
