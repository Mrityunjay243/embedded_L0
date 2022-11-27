#include "main.h"
#include "Simple_EOS.h"
#include "PC_O.h"
#include "Elap_232.h"

static tByte Call_count_G=0;

sEOS_ISR() interrupt INTERRUPT_Timer_2_Overflow
{
	
	TF2=0;   //must manually reset the T2 flag
	
	//call RS-232 update function every 5ms
	
	PC_LINK_O_Update();
	
	//this isr called every 5ms
	//-only want to update time evry second
	if(++Call_count_G==200)
	{
		//time to update time
		Call_count_G=0;
		
		//call time update function
		Elapsed_Time_RS232_Update();
		
		
		
	}
}

void sEOS_Init_Timer2(const tByte TICK_MS)
{
	tLong Inc;
	tWord Reload_16;
	tByte Reload_08H, Reload_08L;
	//timer2 is configured as a 16- bit timer,
	//which is automatically reloaded when it overflows
	T2CON=0x04;   //load timer2 control register
	
	
	//number of timer increments required(max 65536)
	Inc=((tLong)TICK_MS * (OSC_FREQ/1000))/ (tLong)OSC_PER_INST;

		//16-BIT reload value
	Reload_16=(tWord)(65536UL-Inc);
	
	//8-bit reload values (High & low)
	Reload_08H=(tByte)(Reload_16/256);
	Reload_08L=(tByte)(Reload_16%256);
	
	//used for manually checking timing (in simulator)
	//P2=Reload_08H;
	//P3=Reload_08L;
	
	TH2    =Reload_08H;    //load timer2 high byte
	RCAP2H =Reload_08H;    //load timer2 reload capture register high byte
	TL2    =Reload_08L;    //load Timer2 low byte
	RCAP2L =Reload_08L;    //load timer2 reload capture register low byte
	
	//timer2 interrupt is enabled, and ISR will be called whenevr the timer overflows.
	
	ET2=1;
	
	//start Timer2 running
	TR2=1;
	
	
	EA=1;    //globally enable interrupts
}


void sEOS_Go_To_Sleep(void)
{
	PCON|=0x01;    //enter idle(sleep) mode (generic 8051 version)
}

