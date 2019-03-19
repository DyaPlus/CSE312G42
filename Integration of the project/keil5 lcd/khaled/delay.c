
#include "MCAL.h"

void delayms(float delay); {
	delay = (16 * 1000 * delay) - 1;
	NVIC_ST_RELOAD_R = delay;
	NVIC_ST_CURRENT_R = 1;
	NVIC_ST_CTRL_R |= 0x5; 
	while ((NVIC_ST_CTRL_R&(1<<16))==0);
	NVIC_ST_CTRL_R = 0; 
}
