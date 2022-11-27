#include "main.h"
#include "PC_O.h"
#include "Elap_232.h"

tByte Out_written_index_G ; // DATA I BUFER THAT HAS NOT BEEN WRITTEN
tByte Out_waiting_index_G ; // DATA IN BUFFER NOT YET WRITTEN

static void PC_LINK_O_Send_Char(const char) ;

#define TRAN_BUFFER_LENGTH 20 // THE TRANSMIT BUFFER LENGTH
	
	static tByte Tran_buffer[TRAN_BUFFER_LENGTH] ;
	
	static tByte Time_count_G = 0 ;
	
	void PC_LINK_O_Update(void)
	{
		// deals with transmit bytes here 
		// are there any data ready to send?
		
		if(Out_written_index_G < Out_waiting_index_G)
		{
			PC_LINK_O_Send_Char(Tran_buffer[Out_written_index_G]) ;
			Out_written_index_G++ ;
		}
		else
		{
			// no data to send - just reset tghe buffer
			
			Out_waiting_index_G =0 ;
			Out_written_index_G = 0 ;
		}
	}
		
		void PC_LINK_O_Write_String_To_Buffer(const char* const STR_PTR)
		{
			tByte i = 0 ;
			
			while(STR_PTR[i] != '\0')
			{
				PC_LINK_O_Write_Char_To_Buffer(STR_PTR[i]) ;
				i++ ;
			}
		}
		
		void PC_LINK_O_Write_Char_To_Buffer(const char CHARACTER)
		{
			// WRITE TO THE BUFFER ONLY THERE IS SPACE
			// (NO ERROR REPORTING IN THIS LIBRARY ...)
			
			if(Out_waiting_index_G < TRAN_BUFFER_LENGTH)
			{
				Tran_buffer[Out_waiting_index_G] =CHARACTER ;
				Out_waiting_index_G++ ;
			}
		}
		
		void PC_LINK_O_Send_Char(const char CHARACTER) 
		{
			tLong Timeout1 = 0 ;
			if(CHARACTER == '\n')
			{
				Timeout1 = 0 ;
				while((++Timeout1) && (TI == 0));
				
				if(Timeout1 == 0)
				{
					
				// uart did not respond - error 
				// no error reporting in this library ...
				return ;
				}
				
				TI = 0 ;
				SBUF =0x0d ; // OUTPUT CR
				
			}
			
		Timeout1 = 0 ;
			while((++Timeout1) && (TI == 0)) ;
			
			if(Timeout1 == 0)
			{
				// uart did not respind - error 
				// no error reporting in this simpkle library ...
				return ;
			}
			
			TI = 0 ;
			 SBUF = CHARACTER ;
		}
		