#include "tm4c123gh6pm.h"
#include "TM4C123.h"                    // Device header
#include "LCD.h" 

void PORTF_Init(int mode);
void PORTA_Init(int mode);
void PORTB_Init(int mode);
void PORTD_Init(int mode);
void delayms(float delay);

void Init(void){
	PORTF_Init(1);
	PORTA_Init(1);
	PORTB_Init(1);
	PORTD_Init(1);
}


int main(void){
	Init();
	InitLCD();
	LCD_data('D');
	LCD_data('Y');
	LCD_data('A');
	LCD_data('A');

}


void PORTF_Init(int mode){									// 1 for Output , 0 for Input
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  // PortF clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PortF Commit register  
  GPIO_PORTF_CR_R |= 0xFF;          				// Allow changes to PortF
  GPIO_PORTF_AMSEL_R &= ~0xFF;      				// Disable analog function
  GPIO_PORTF_PCTL_R &= ~0xFF;  							// GPIO clear bit PCTL  
  GPIO_PORTF_AFSEL_R &= ~0xFF;      				// No alternate function
	if (mode) {
		GPIO_PORTF_DIR_R |= 0xFF;								// Set PORT Direction as output
	}
	else {
			GPIO_PORTF_DIR_R &= ~0xFF;						// Set PORT Direction as input
		  GPIO_PORTF_DATA_R &= ~0xFF;						// Initalize PORT to be 0

	}
  GPIO_PORTF_DEN_R |= 0xFF;         				// Enable digital For all bits *Could be a problem for anal output or input
}

void PORTB_Init(int mode){									// 1 for Output , 0 for Input
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;  // PortB clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PortB Commit register  
  GPIO_PORTB_CR_R |= 0xFF;          				// Allow changes to PortB
  GPIO_PORTB_AMSEL_R &= ~0xFF;      				// Disable analog function
  GPIO_PORTB_PCTL_R &= ~0xFF;  							// GPIO clear bit PCTL  
  GPIO_PORTB_AFSEL_R &= ~0xFF;      				// No alternate function
	if (mode) {
		GPIO_PORTB_DIR_R |= 0xFF;								// Set PORT Direction as output
	}
	else {
			GPIO_PORTB_DIR_R &= ~0xFF;						// Set PORT Direction as input
		  GPIO_PORTB_DATA_R &= ~0xFF;				// Initalize PORT to be 0

	}
  GPIO_PORTB_DEN_R |= 0xFF;         // Enable digital For all bits *Could be a problem for anal output or input
}

void PORTA_Init(int mode){									// 1 for Output , 0 for Input
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;  // PortB clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PortA Commit register  
  GPIO_PORTA_CR_R |= 0xFF;          				// Allow changes to PortB
  GPIO_PORTA_AMSEL_R &= ~0xFF;      				// Disable analog function
  GPIO_PORTA_PCTL_R &= ~0xFF;  							// GPIO clear bit PCTL  
  GPIO_PORTA_AFSEL_R &= ~0xFF;      				// No alternate function
	if (mode) {
		GPIO_PORTA_DIR_R |= 0xFF;								// Set PORT Direction as output
		GPIO_PORTA_DATA_R &= ~0xFF;				// Initalize PORT to be 0
	}
	else {
			GPIO_PORTA_DIR_R &= ~0xFF;						// Set PORT Direction as input
	}
  GPIO_PORTA_DEN_R |= 0xFF;         // Enable digital For all bits *Could be a problem for anal output or input
}

void PORTD_Init(int mode){									// 1 for Output , 0 for Input
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;  // PortB clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PortA Commit register  
  GPIO_PORTD_CR_R |= 0x0F;          				// Allow changes to PortB
  GPIO_PORTD_AMSEL_R &= ~0x0F;      				// Disable analog function
  GPIO_PORTD_PCTL_R &= ~0x0F;  							// GPIO clear bit PCTL  
  GPIO_PORTD_AFSEL_R &= ~0x0F;      				// No alternate function
	if (mode) {
		GPIO_PORTD_DIR_R |= 0x0F;								// Set PORT Direction as output
		GPIO_PORTD_DATA_R &= ~0x0F;				// Initalize PORT to be 0
	}
	else {
			GPIO_PORTD_DIR_R &= ~0x0F;						// Set PORT Direction as input
	}
  GPIO_PORTD_DEN_R |= 0x0F;         // Enable digital For all bits *Could be a problem for anal output or input
}
void delayms(float delay) {
	delay = (16 * 1000 * delay) - 1;
	NVIC_ST_RELOAD_R = delay;
	NVIC_ST_CURRENT_R = 1;
	NVIC_ST_CTRL_R |= 0x5; 
	while ((NVIC_ST_CTRL_R&(1<<16))==0);
	NVIC_ST_CTRL_R = 0; 
}

