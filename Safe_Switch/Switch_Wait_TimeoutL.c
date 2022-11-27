#include "main.h"
#include "port.h"

#include "Switch_wait_TimeoutL.h"
#include "Delay_t0.h"
#include "TimeoutL.h"

void SWITCH_Init(void)
{
	Switch_pin = 1 ; //use this pin for input
}

bit SWITCH_Get_Input(const tByte DEBOUNCE_PERIOD)
{
	bit Return_value = SWITCH_NOT_PRESSED ;
	tLong Timeout_loop = LOOP_TIMEOUT_INIT_10000ms ;
	
	if(Switch_pin == 0)
	{
		// switch is presssed
		// debounce _just wait
		
		DELAY_TO_Wait(DEBOUNCE_PERIOD) ;
		
		if(Switch_pin == 0)
		{
			//wait until switch is released
			//with timeout loop - 10 sec
			
			while((Switch_pin == 0) && (++Timeout_loop != 0)) ;
			
			// check for timeout
			
			if(Timeout_loop == 0)
			{
				Return_value = SWITCH_NOT_PRESSED ;
			}
			
			else
			{
				Return_value = SWITCH_PRESSED ;
			}
		}
	}
	
	return Return_value ;
}