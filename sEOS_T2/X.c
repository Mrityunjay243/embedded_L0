#include "X.H"
#include <reg52.h>
sbit led = P1^0;

void X_Init(void)
{
	led = 0;
}

void X(void)
{
	led = 1;
}
