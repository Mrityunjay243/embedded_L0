#include "Main.H"
#include "Simple_EOS.H"

#include "T_Lights.H"

//Private variable definitions
static tByte Call_count_G;

sEOS_ISR() interrupt INTERRUPT_Timer_2_Overflow
{
	TF2 = 0; //Must manually reset T2 flag
	

	PC_LINK_O_Update();
	if (++Call_count_G == 200)
	{
		Call_count_G = 0;
		Elapsed_Time_RS232_Update();
	}
	
	
}
void sEOS_Init_Timer2(const tByte TICK_MS)
{
	tLong Inc;
	tWord Reload_16;
	tByte Reload_08H , Reload_08L;
	
	//Timer 2 is configured as a 16-bit timer
	//automatically realoaded when overflows
	T2CON = 0x04;
	//Number of timer increments required
	Inc = ((tLong)TICK_MS * (OSC_FREQ/1000)) / (tLong)OSC_PER_INST;
	
	//16- bit reload value
	Reload_16 = (tWord) (65536UL - Inc);
	
	// 8 bit reload values ( High and Low )
	Reload_08H = (tByte)(Reload_16 / 256);
	Reload_08L = (tByte)(Reload_16 % 256);
	
	//Used for manually checking timing in  simulator
	
	TH2 = Reload_08H;    // load timer 2 high byte
	RCAP2H = Reload_08H; // load timer 2 reload capt. reg. high byte
	TL2 = Reload_08L;    // Load timer 2 Low byte
	RCAP2L = Reload_08L; // load timer 2 reload capt. reg. low byte
	
	ET2 = 1;
	
	TR2 = 1; //Start timer 2 running
	
	EA = 1;  //globally enable interrupts
}

void sEOS_Go_To_Sleep(void)
	{
		PCON |= 0x01;
	}