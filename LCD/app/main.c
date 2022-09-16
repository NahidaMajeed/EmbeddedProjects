#include <reg51.h>
#include "global.h"
#include "lcd.h"

void main()
{
	init_LCD();
	while(1)
	{
		set_LCDCommand(0x080);//displya in first line
		//set_LCDData('S');
		set_LCDString("Nahida");
		set_LCDCommand(0x0C0);//displya in second line
		//set_LCDData('E');
		set_LCDString("Embedded Software");
	}
}