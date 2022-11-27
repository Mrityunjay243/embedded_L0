#include "main.h"
#include "Port.h"
#include "Simple_EOS.h"

#include "PC_O_T1.h"
#include "Elap_232.h"

void main(void)
{
	//set baud rate to 9600
	PC_LINK_O_Init_T1(9600);
	
	
	//prepare for elapsed time measurement
	Elapsed_Time_RS232_Init();
	
	//set up simple EOS (5ms ticks)
	sEOS_Init_Timer2(5);
	
	while(1)
	{
		sEOS_Go_To_Sleep();
	}
}

