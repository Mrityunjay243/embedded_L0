#include "main.h"
#include "Port.h"

#include "Display_Count.h"


void DISPLAY_COUNT_Init(void)
{
	Count_port = 0x00;
}

//DISPLAY_COUNT_Update()
//simple function to display tByte data (count) on leds connected to port (Count_Port)

void DISPLAY_COUNT_Update(const tByte COUNT)
	{
	Count_port = COUNT;
}