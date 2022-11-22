#include <reg51.h>
#include "global.h"
#include "mkeys.h"

#define mkeys	P1

#define senseColoumn1()		ISBITCLR(P1, BIT4)
#define senseColoumn2()		ISBITCLR(P1, BIT5)
#define senseColoumn3()		ISBITCLR(P1, BIT6)
#define senseColoumn4()		ISBITCLR(P1, BIT7)

unsigned char keyBuf[16] = "789%456*123-#0=+";
void activeRow1()
{
	CLRBIT(P1, BIT0);
	SETBIT(P1, BIT1);
	SETBIT(P1, BIT2);
	SETBIT(P1, BIT3);
}
void activeRow2()
{
	SETBIT(P1, BIT0);
	CLRBIT(P1, BIT1);
	SETBIT(P1, BIT2);
	SETBIT(P1, BIT3);
}
void activeRow3()
{
	SETBIT(P1, BIT0);
	SETBIT(P1, BIT1);
	CLRBIT(P1, BIT2);
	SETBIT(P1, BIT3);
}
void activeRow4()
{
	SETBIT(P1, BIT0);
	SETBIT(P1, BIT1);
	SETBIT(P1, BIT2);
	CLRBIT(P1, BIT3);
}

void configMKeys()
{
	mkeys = 0xff;
}

unsigned char getKey()
{
	unsigned char key = 0;
	
	activeRow1();
	if(senseColoumn1())
	{
		while(senseColoumn1());
		key = keyBuf[0];
	}
	else if(senseColoumn2())
	{
		while(senseColoumn2());
		key = keyBuf[1];
	}
	else if(senseColoumn3())
	{
		while(senseColoumn3());
		key = keyBuf[2];
	}
	else if(senseColoumn4())
	{
		while(senseColoumn4());
		key = keyBuf[3];
	}
	else
	{
		activeRow2();
		if(senseColoumn1())
		{
			while(senseColoumn1());
			key = keyBuf[4];
		}
		else if(senseColoumn2())
		{
			while(senseColoumn2());
			key = keyBuf[5];
		}
		else if(senseColoumn3())
		{
			while(senseColoumn3());
			key = keyBuf[6];
		}
		else if(senseColoumn4())
		{
			while(senseColoumn4());
			key = keyBuf[7];
		}
		else
		{
			activeRow3();
			if(senseColoumn1())
			{
				while(senseColoumn1());
				key = keyBuf[8];
			}
			else if(senseColoumn2())
			{
				while(senseColoumn2());
				key = keyBuf[9];
			}
			else if(senseColoumn3())
			{
				while(senseColoumn3());
				key = keyBuf[10];
			}
			else if(senseColoumn4())
			{
				while(senseColoumn4());
				key = keyBuf[11];
			}
			else
			{
				activeRow4();
				if(senseColoumn1())
				{
					while(senseColoumn1());
					key = keyBuf[12];
				}
				else if(senseColoumn2())
				{
					while(senseColoumn2());
					key = keyBuf[13];
				}
				else if(senseColoumn3())
				{
					while(senseColoumn3());
					key = keyBuf[14];
				}
				else if(senseColoumn4())
				{
					while(senseColoumn4());
					key = keyBuf[15];
				}
			}
		}
	}
	return key;
}