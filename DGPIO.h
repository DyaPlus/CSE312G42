#include "tm4c123gh6pm.h"
#include "stdint.h"                  

#define PORTA_P 0x40004000UL
#define PORTB_P 0x40005000UL
#define PORTD_P 0x40007000UL

#define HWREG(x) 						(*((volatile unsigned long *)(x)))



void delayms(float delay);
void GPIOPortWrite(unsigned char word,uint32_t port, uint8_t mask) {
		word = word & (mask);
		HWREG(port+0x3FC) = (word);
}




