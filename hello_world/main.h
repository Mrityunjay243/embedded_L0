#include <reg52.h>
//stores all the register definitions of the chip like driverlib.h

#define OSC_FREQ (12000000UL)
#define OSC_PER_INST (12)

typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;

#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5