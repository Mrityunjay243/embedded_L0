#include "Main.H"
#include "Port.H"

#include "T_Lights.H"

#define ON 0
#define OFF 1

//Times in each of the states

#define RED_DURATION 20
#define RED_AND_AMBER_DURATION 5
#define GREEN_DURATION 30
#define AMBER_DURATION 5


// state of the system
static eLight_State Light_state_G;

// time time in that state
static tLong Time_in_state;

// used by sEOS
static tByte Call_count_G = 0;

void TRAFFIC_LIGHTS_Init(const eLight_State START_STATE)
{
	Light_state_G = START_STATE; //decide on initial state
}

void TRAFFIC_LIGHTS_Update(void)
{
	switch(Light_state_G)
	{
		case RED:
		{
			Red_light = ON;
			Amber_light = OFF;
			Green_light = OFF;
			
			if (++Time_in_state == RED_DURATION)
			{
				Light_state_G = RED_AND_AMBER;
				Time_in_state = 0;
			}
			break;
		}
		case RED_AND_AMBER:
		{
			Red_light = ON;
			Amber_light = ON;
			Green_light = OFF;
			
			if(++Time_in_state == RED_AND_AMBER_DURATION)
			{
				Light_state_G = GREEN;
				Time_in_state = 0;
			}
			
			break;
		}
		case GREEN:
		{
			Red_light = OFF;
			Amber_light = OFF;
			Green_light = ON;
			
			if(++ Time_in_state == GREEN_DURATION)
			{
				Light_state_G = AMBER;
				Time_in_state = 0;
			}
			break;
		}
		case AMBER:
		{
			Red_light = OFF;
			Amber_light = ON;
			Green_light = OFF;
			
			if(++Time_in_state == AMBER_DURATION)
			{
				Light_state_G = RED;
				Time_in_state = 0;
			}
			break;
		}
	}
}

			
	
	
	