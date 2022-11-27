#ifndef _T_LIGHTS_H
#define _T_LIGHTS_H

typedef
	enum {RED, RED_AND_AMBER, GREEN, AMBER} eLight_State;

void TRAFFIC_LIGHTS_Init(const eLight_State);
void TRAFFIC_LIGHTS_Update(void);

#endif