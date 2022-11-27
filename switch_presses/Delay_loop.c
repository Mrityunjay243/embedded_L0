#include "Port.h"
#include "Delay_loop.h"
#include "main.h"

void DELAY_LOOP_Wait(const tWord DELAY_MS)
{
	tWord x , y;
	for(x=0 ; x<=DELAY_MS ; x++)
	{
		for(y=0 ; y<=120 ; y++);
	}
}