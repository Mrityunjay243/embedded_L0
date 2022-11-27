#ifndef _SWITCH_WAIT_H
#define _SWITCH_WAIT_H

#define SWITCH_NOT_PRESSED (bit) 0
#define SWITCH_PRESSED (bit) 1

void SWITCH_Init(void);
bit SWITCH_Get_Input(const tByte);

#endif
