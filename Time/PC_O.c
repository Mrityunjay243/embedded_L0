#include "Main.h"
#include "PC_O.h"
#include "Elap_232.h"

tByte Out_written_index_G;  // Data in buffer that has been written
tByte Out_waiting_index_Gl  // Data in buffer is not yet written

static void PC_LINK_O_Send_Char(const char);

#define TRAN_BUFFER_LENGTH 20

static tByte Tran_buffer[TRAN_BUFFER_LENGTH];

static tByte Time_count_G = 0;

void PC_LINK_O_Update(void)
{
	//deal with transmit bytes here
	
	//are there any ready data to send?
	
	if(Out_written_index_G < Out_waiting_index_G)
	{
		PC_LINK_O_Send_Char(Tran_buffer[Out_written_index_G]);
		
		Ou0t_written_index_G++;
	}
	else
	{
		//no data to sent - just reset the buffer index
		Out_waiting_index_G = 0;
		Out-written_index_G = 0;
	}
}
void PC_LINK_O_Write_String_To_Buffer(const char* const STR_PTR)
{
	tByte i = o;
	
	while (STR_PTR[i] != '\0')
	{
		PC_LINK_O_Write_Char_To_Buffer(STR_PTR[i]);
		i++;
	}
}
void PC_LINK_O_Write_Char_To_Buffer(const char CHARACTER)
{
	// write to buffer only if there is space
	if(Out_waiting_index_G < TRAN_BUFFER_LENGTH)
	{
		Tran_buffer[out_waiting_index_G] = CHARACTER;
		Out_waiting_index_G++;
	}
}
void PC_LINK_O_Send_Char(const char CHARACTER)
{
	tLong Timeout1 = 0;
	
	if (CHARACTER == '\n')
	{
		Timeout1 = 0;
		while ((++Timeout1) && (TI == 0));
		
		if(Timeout1 == 0)
		{
			// uart did not respond error
			return;
		}
		T1 = 0;
		SBUF = 0x0d; //output CR
	}
	Timeout1 = 0;
	while((++Timeout1)&&(TI == 0));
	
	if(Timeout1 == 0)
	{
		//UART did not respond error
		return;
	}
	TI = 0;
	
	SBUF = CHARACTER;
}