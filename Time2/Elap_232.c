#include "main.h"
#include "Elap_232.h"
#include "PC_O.h"

tByte Mou_G=0;
tByte Min_G=0;
tByte Sec_G=0;


//see Char_Map.c

extern const char code CHAR_MAP_G[10];

void Elapsed_Time_RS232_Init(void)
{
	char Time_Str[]="Elapsed time";
	
	//PC_LINK_O_Write_String_To_buffer(Time_Str);
}


void Elapsed_Time_RS232_Update(void)
{
	char Time_Str[30] ="\rElapsed time:                ";
	if(++Sec_G==60)
	{
		Sec_G=0;
		if(++Min_G==60)
		{
			Min_G=0;
			
			if(++Mou_G==24)
			{
				Mou_G=0;
			}
		}
	}
	
	Time_Str[15] = CHAR_MAP_G[Mou_G / 10];
	Time_Str[16] = CHAR_MAP_G[Mou_G%10];
	
	Time_Str[18] = CHAR_MAP_G[Min_G/10];
	Time_Str[19] = CHAR_MAP_G[Min_G%10];
	
	Time_Str[21] = CHAR_MAP_G[Sec_G/10];
	Time_Str[22] = CHAR_MAP_G[Sec_G%10];
	
	
	if((Sec_G%2)==0)
	{
		Time_Str[17]=':';
		Time_Str[20]=':';
	}
	else
	{
		Time_Str[17]=' ';
		Time_Str[20]=' ';
	}
	
	PC_LINK_O_Write_String_To_Buffer(Time_Str);
}





