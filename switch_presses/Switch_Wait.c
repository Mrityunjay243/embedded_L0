#include "main.h"
#include "Port.h"
#include "Switch_Wait.h"
#include "Delay_loop.h"
void SWITCH_Init(void)
{
	Switch_pin = 1 ;
	//USE THIS PIN FOR INPUT
}

//SWITCH_Get_Input()   reads and debounces switch as follows

bit SWITCH_Get_Input(const tByte DEBOUNCE_PERIOD)
{
	bit Return_value = SWITCH_NOT_PRESSED ;
	if(Switch_pin == 0)
	{
		DELAY_LOOP_Wait(DEBOUNCE_PERIOD);
		
		if(Switch_pin == 0)
		{
			while(Switch_pin == 0);
			Return_value = SWITCH_PRESSED ;
		}
	}
	
	return Return_value ;
}