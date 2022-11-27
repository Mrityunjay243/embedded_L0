#include "main.h"
#include "port.h"

#include "Delay_T0.h"
#include "LED_Flash.h"

void main(void)
{
	LED_FLASH_Init();
	
	while(1)
	{
		//CHANGE THE LED STATE
		LED_FLASH_Change_State();
		
		DELAY_TO_Wait(1000);//delay for approx 1000ms
	}
}
