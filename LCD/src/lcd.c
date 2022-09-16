#include <reg51.h>
#include "global.h"
#include "delay.h"
#include "lcd.h"

#define LCD_DATA_PORT	P2
#define SET_LCD_CommandMode()	CLRBIT(P3,BIT5);
#define SET_LCD_DataMode()			SETBIT(P3,BIT5);

static void set_LCDClock()
{
	CLRBIT(P3,BIT7);
	delay(1000);
	SETBIT(P3,BIT7);
}
static void write_LCDPort(unsigned char value)
{
	LCD_DATA_PORT = value;
}
void set_LCDCommand(unsigned char command)
{
	write_LCDPort(command);
	SET_LCD_CommandMode();
	set_LCDClock();
}

void set_LCDData(unsigned char value)
{
	write_LCDPort(value);
	SET_LCD_DataMode();
	set_LCDClock();
}

void set_LCDString(unsigned char *value)
{
	while(*value != '\0')
	{
		set_LCDData(*value);
		value++;
	}
}

void init_LCD()
{
	set_LCDCommand(0x38);//8tbit and bothlines
	set_LCDCommand(0x0E);
	set_LCDCommand(0x06);
}