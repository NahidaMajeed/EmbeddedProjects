#include <reg51.h>
#include "stepper.h"
#include "delay.h"

#define DELAY_VALUE			7000
void StepperClockwise()
{
	STEEPER = 0x01;
	delay(DELAY_VALUE);
	STEEPER = 0x02;
	delay(DELAY_VALUE);
	STEEPER = 0x04;
	delay(DELAY_VALUE);
	STEEPER = 0x08;
	delay(DELAY_VALUE);
}

void StepperAntiClockwise()
{
	STEEPER = 0x08;
	delay(DELAY_VALUE);
	STEEPER = 0x04;
	delay(DELAY_VALUE);
	STEEPER = 0x02;
	delay(DELAY_VALUE);
	STEEPER = 0x01;
	delay(DELAY_VALUE);
}