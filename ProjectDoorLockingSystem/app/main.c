#include <reg51.h>
#include <stdio.h>

#include "global.h"
#include "lcd.h"
#include "mkeys.h"
#include "stepper.h"
#include "delay.h"

int password = 1234;
int value = 0;

sbit LED = P3^6;

void initAllComponents()
{
	//Init all the dependent components
	initLCD();
	setLCDCommand(0x80);
	setLCDCommand(0x01);
	setLCDString("Enter Password");
	setLCDCommand(0xC0);
	
	
}
void main()
{
	unsigned char rawValue = 0;
	int count = 0;
	char string[5] = "";
	
	configMKeys();
	
	CLRBIT(P3, 6);

	initAllComponents();
	
	while(1)
	{
		rawValue = getKey();
		if(rawValue)
		{
			if(rawValue == '#')
			{
				//printf("raw value %d %d\n", value, password);
					
				if (value == password)
				{
					count = 0; //reset the password error counter
					setLCDCommand(0x01);
					setLCDCommand(0x80);
					setLCDString("Door Open");
					//Send stepper motor 
					StepperClockwise();
				}
				else
				{
					count ++;
					setLCDCommand(0x01);
					setLCDCommand(0x80);
					setLCDString("Psswrd Er");
				
					if (3 == count)
					{
						count = 0;
						SETBIT(P3, 6);
					}
				}
				
				value = 0;
				resetPassword();
			}
			else if(rawValue == '=')
			{
				initAllComponents();
				value = 0;
				resetPassword();
			}
			else
			{
				setLCDData('*');
				//Creating password
				value = enteredPassword(rawValue);
				
			}
			
			
		}
	}
}