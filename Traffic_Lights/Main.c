#include "Main.H"
#include "Port.H"
#include "Simple_EOS.h"

#include "T_Lights.H"

void main(void)
{
	//prepare to run traffic sequence
	TRAFFIC_LIGHTS_Init(RED);
	
	//set up simple EOS (50ms ticks)
	sEOS_Init_Timer2(50);
	
	while(1)
	{
		sEOS_Go_To_Sleep();
	}
}
