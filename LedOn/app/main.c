#include <reg51.h>

sbit LED = P0^1;

void main()
{
	while(1)
	{
		LED = 1;
	}
}