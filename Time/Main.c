#include "Main.H"
#include "Port.H"
#include "Simple_EOS.H"

#include "PC_O_T1.h"
#include "Elap_232.h"


void main(void)
{
	PC_LINK_O_Init_T1(9600); //setting baud rate to 9600
	
	Elapsed_Time_RS232_Init(); //prepared for elapsed time measurement
	
	sEOS_Init_Timer2(5); //set up simple eos to 5ms tick
	
	while(1)
	{
		sEOS_Go_To_Sleep(); //Enter idle mode to save power
	}
}

	