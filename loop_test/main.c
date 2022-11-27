#include <reg52.h>

#include "TimeoutL.h"

typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;

void Test_Timeout(void) ;

void main(void)
{
	while(1)
	{
		Test_Timeout();
	}
}

void Test_Timeout(void)
{
	tLong Timeout_loop = LOOP_TIMEOUT_INIT_10000ms;
	//simple loop timeout
	while (++Timeout_loop != 0);
}