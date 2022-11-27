#include "main.h"
#include "Port.h"

#include "Delay_Loop.h"
#include "LED_flash.h"

void main (void)
{
	LED_FLASH_Init();
	
	while(1)
	{
		//change the led state
		LED_Flash_Change_State();
		
		//delay for "approx" 1000ms
		DELAY_LOOP_Wait(1000);
		
	}
}