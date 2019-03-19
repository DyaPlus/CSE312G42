// 0.Documentation Section 
// LCD_displayCharacter function
// Runs on LM4F120 or TM4C123
// Authors: khaled ahmed abdelgalil
// Date: 20/3/2019

#include "lcd.h"
#include "MCAL.h"
#include "delay.h"

void LCD_displayCharacter(uint8 data)
{
		DIO_WritePort(PORT_F_INDEX,PIN_2,STD_HIGH); /* Data Mode RS=1 */
		delayms(1); /* delay for processing Tas = 50ns */
	
		DIO_WritePort(PORT_F_INDEX,PIN_3,STD_HIGH); /* Enable LCD E=1 */
		delayms(1); /* delay for processing Tpw - Tdws = 190ns */
	
		DIO_WritePort1(data,PORTA_P,PORT_UPPER); /* out the required command to the data bus D0 --> D7 */
		DIO_WritePort1(data,PORTD_P,PORT_LOWER);
		delayms(1); /* delay for processing Tdsw = 100ns */
	
		DIO_WritePort(PORT_F_INDEX,PIN_3,STD_LOW); /* disable LCD E=0 */
		delayms(1); /* delay for processing Th = 13ns */	
}