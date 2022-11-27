#include "Main.h"
#include "PC_O_T1.h"

extern tByte Out_written_index_G;
extern tByte Out_waiting_index_G;

void PC_LINK_O_Init_T1(const tWord BAUD_RATE)
{
	PCON &= 0x7F;
	
	// Receiver disabled
	
	SCON = 0X42;
	
	TMOD |= 0X20;
	
	TH1 = (256 - (tByte)((((tLong)OSC_FREQ / 100) * 3125)
				   / ((tLong) BAUD_RATE * OSC_PER_INST * 1000)));
	
	TL1 = TH1;
	TR1 = 1;
	TI = 1;
	
	Out_written_index_G = 0;
	Out_waiting_index_G = 0;
	
	ES = 0;
}
