#include <reg51.h>
#include "global.h"
#include "lcd.h"
#include "mkeys.h"

void main()
{
	unsigned char rawValue = 0;
	initLCD();
	configMKeys();
	
	while(1)
	{
		setLCDCommand(0x80);
		setLCDString("My Mkey Values:");
		rawValue = getKey();
		if(rawValue)
		{
			setLCDCommand(0xC0);
			setLCDData(rawValue);
		}
	}
}