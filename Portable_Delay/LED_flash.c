#include "main.h"
#include "Port.h"

#include "LED_flash.h"

static bit LED_state_G;

//LED_FLASH_Init()

void LED_FLASH_Init(void)
{
	LED_state_G = 0;
}

void LED_FLASH_Change_State(void)
{
	//Change the led from OFF to ON 
	if (LED_state_G ==1)
	{
		LED_state_G = 0;
		LED_pin = 0;
	}
	else
	{
		LED_state_G = 1;
		LED_pin = 1;
	}
}

