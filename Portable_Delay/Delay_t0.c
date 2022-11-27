#include "main.h"

#define PRELOAD01 (65536 - (tWord)(OSC_FREQ / (OSC_PER_INST*1020)))
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)

void DELAY_TO_Wait(const tWord N)
{
	tWord ms;
	
	TMOD &= 0xF0; //clear all T0 BITS(T1 LEFT UNCHANGED)
	 TMOD |= 0x01; //set required T0 bits (t1 left unchanged)
	 
	 ET0 = 0; // no interrupts
	 
	 // values for 1 ms delay per loop
	 for(ms = 0 ; ms < N ; ms++)
	{ TH0 = PRELOAD01H ; // TIMER 0 INITIAL VALUE(HIGH BYTE)
	 TL0 = PRELOAD01L ; // TIMER 0 INITIAL VALUE(LOW BYTE)
	 
	 TF0 = 0; //CLEAR OVERFLOW FLAG
	 TR0 = 1; //START TIMER 0
	 
	 while(TF0 == 0);
	 // LOOP UNTIL TIMER 0 OVERFLOWS (TF0 == 1)
	 
	 TR0 = 0 ; // stop timer 0
	}
}
