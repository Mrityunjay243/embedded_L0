#include <reg52.h>

sbit LED_pin = P1^5 ;
bit LED_state_G ;
 void LED_FLASH_Init(void) ;
 void LED_FLASH_Change_State(void);
 
 void DELAY_HARDWARE_One_Second(void);
 void DELAY_HARDWARE_50ms(void) ;
 
 void main(void)
 {
	 LED_FLASH_Init();
	 
	 while(1)
	 {
		 //change the led state 
		 LED_FLASH_Change_State();
		 DELAY_HARDWARE_One_Second() ;
	 }
 }
 
 void LED_FLASH_Init(void)
 {
	 LED_state_G = 0;
 }
 
 void LED_FLASH_Change_State(void)
 {
	 if(LED_state_G == 1)
	 {
		 LED_state_G = 0;
		 LED_pin=0 ;
	 }
	 else
	 {
		 LED_state_G = 1;
		 LED_pin=1 ;
	 }
 }
 
 void DELAY_HARDWARE_One_Second(void)
 {
	 unsigned char d;
	 for(d=0 ; d<20 ; d++)
	 {
		 DELAY_HARDWARE_50ms();
	 }
 }
 
 void DELAY_HARDWARE_50ms(void)
 {
	 //configure timer 0 as 16 bit timer
	 
	 TMOD &= 0xF0; //clear all T0 BITS(T1 LEFT UNCHANGED)
	 TMOD |= 0x01; //set required T0 bits (t1 left unchanged)
	 
	 ET0 = 0; // no interrupts
	 
	 // values for 50 ms delay
	 
	 TH0 = 0x3C ; // TIMER 0 INITIAL VALUE(HIGH BYTE)
	 TL0 = 0xB0 ; // TIMER 0 INITIAL VALUE(LOW BYTE)
	 
	 TF0 = 0; //CLEAR OVERFLOW FLAG
	 TR0 = 1; //START TIMER 0
	 
	 while(TF0 == 0);
	 // LOOP UNTIL TIMER 0 OVERFLOWS (TF0 == 1)
	 
	 TR0 = 0 ; // stop timer 0
 }
		 
