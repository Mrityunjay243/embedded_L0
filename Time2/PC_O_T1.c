#include "main.h"
#include "PC_O_T1.h"

extern tByte Out_written_index_G;
extern tByte Out_waiting_index_G;


void PC_LINK_O_Init_T1(const tWord BAUD_RATE)
{
	PCON &=0x7F;   //set SMOD bit to 0 (don't double baud rates)
	//receiver disabled
	//8-bit data, 1 start bit, 1 stop bit , variable baud rate (asynchronous)
	SCON=0x42;
	
	TMOD |= 0x20;  //T1 in mode 2, 8 bit auto reload
	
	TH1 = (256 - (tByte)((((tLong OSC_FREQ / 100) * 3125)
							/ ((tLong) BAUD_RATE * OSC_PER_INST * 1000)));
	
	TL1 = TH1;
	TR1 = 1;  //RUN THE TIMER

	TI=1;  //SEND FIRST CHARACTER (DUMMY)
	
	//SET UP THE BUFFERS FOR READING AND WRITING 
	Out_written_index_G=0;
	Out_waiting_index_G=0;
	
	//interrupt not enabled
	ES=0;
	
	
}
