#include <reg51.h>
#include "global.h"
#include "robot.h"

//Forward 1010
void robotForward()
{
	SETBIT(P2, BIT0);
	CLRBIT(P2, BIT1);
	SETBIT(P2, BIT6);
	CLRBIT(P2, BIT7);
}

//backward 0101
void robotBackward()
{
	CLRBIT(P2, BIT0);
	SETBIT(P2, BIT1);
	CLRBIT(P2, BIT6);
	SETBIT(P2, BIT7);
}

//left 0010
void robotLeft()
{
	CLRBIT(P2, BIT0);
	CLRBIT(P2, BIT1);
	SETBIT(P2, BIT6);
	CLRBIT(P2, BIT7);
}
//right 1000
void robotRight()
{
	SETBIT(P2, BIT0);
	CLRBIT(P2, BIT1);
	CLRBIT(P2, BIT6);
	CLRBIT(P2, BIT7);
}
//stop 0000
void robotStop()
{
	CLRBIT(P2, BIT0);
	CLRBIT(P2, BIT1);
	CLRBIT(P2, BIT6);
	CLRBIT(P2, BIT7);
}
