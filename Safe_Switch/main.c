#include "main.h"
#include "port.h"

#include "Switch_wait_TimeoutL.h"
#include "Display_count.h"

void main(void)
{
	tByte Switch_presses = 0 ;
	 SWITCH_Init();
	DISPLAY_COUNT_Init();
	
	while(1)
	{
		if(SWITCH_Get_Input(30) == SWITCH_PRESSED)
		{
			Switch_presses++ ;
		}
		
		DISPLAY_COUNT_Update(Switch_presses) ;
	}
}