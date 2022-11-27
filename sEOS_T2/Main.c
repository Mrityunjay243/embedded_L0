#include "Main.h"
#include "Port.h"
#include "Simple_EOS.h"
#include "X.h"

void main(void)
{
	X_Init();
	
	sEOS_Init_Timer2(50); //50ms tick interval
	
	while(1)
	{
		sEOS_Go_To_Sleep();
	}
}
