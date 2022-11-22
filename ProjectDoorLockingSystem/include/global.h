#ifndef __global_h_
#define __global_h_

#define SETBIT(reg, bitpos) reg = reg | (1 << bitpos)
#define CLRBIT(reg, bitpos) reg = reg & ~(1 << bitpos)
#define ISBITSET(reg, bitpos) reg &(1<<bitpos)
#define ISBITCLR(reg, bitpos) !(reg &(1<<bitpos))

#define BIT0	0
#define BIT1	1
#define BIT2	2
#define BIT3	3
#define BIT4	4
#define BIT5	5
#define BIT6	6
#define BIT7	7

#endif