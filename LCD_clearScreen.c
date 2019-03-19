// 0.Documentation Section 
// LCD_clearScreen function
// Runs on LM4F120 or TM4C123
// Authors: khaled ahmed abdelgalil
// Date: 20/3/2019
#include "lcd.h"
#include "MCAL.h"
#include "delay.h"



void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}
