#include <reg51.h>
#include "global.h"
#include "delay.h"
#include "lcd.h"

#define LCD_DATA_PORT	P2
#define SET_LCD_CommandMode()	CLRBIT(P3,BIT5);
#define SET_LCD_DataMode()			SETBIT(P3,BIT5);

static void setLCDClock()
{
	CLRBIT(P3,BIT7);
	delay(1000);
	SETBIT(P3,BIT7);
}
static void writeLCDPort(unsigned char value)
{
	LCD_DATA_PORT = value;
}
void setLCDCommand(unsigned char command)
{
	writeLCDPort(command);
	SET_LCD_CommandMode();
	setLCDClock();
}

void setLCDData(unsigned char value)
{
	writeLCDPort(value);
	SET_LCD_DataMode();
	setLCDClock();
}

void setLCDString(unsigned char *value)
{
	while(*value != '\0')
	{
		setLCDData(*value);
		value++;
	}
}

void initLCD()
{
	setLCDCommand(0x38);//8tbit and bothlines
	setLCDCommand(0x0E);
	setLCDCommand(0x06);
}