

// 0.Documentation Section 
// Button_Reset function
// Runs on LM4F120 or TM4C123
// Authors: khaled ahmed abdelgalil
// Date: 20/3/2019

// 1. Pre-processor Directives Section
#include "button.h"

// function to set reset counter
//INPUTS:void
//POST-condition:zero appears on lcd
void Button_Reset(void)
{

		num=0;
		while(!DIO_ReadPort(0,0x08));
		LCD_clearScreen();
		LCD_intgerToString(num);
}