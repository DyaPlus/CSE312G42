
#include "lcd.h"
#include "MCAL.h"
#include "delay.h"


void LCD_sendCommand(uint8 command)
{
	DIO_WritePort(PORT_F_INDEX,PIN_2,STD_LOW); /* Instruction Mode RS=0 */
	delayms(1); /* delay for processing Tas = 50ns */
	
	DIO_WritePort1(command,PORTA_P,PORT_UPPER); /* out the required command to the data bus D0 --> D7 */
	DIO_WritePort1(command,PORTD_P,PORT_LOWER); /* out the required command to the data bus D0 --> D7 */
	
	DIO_WritePort(PORT_F_INDEX,PIN_3,STD_HIGH); /* Enable LCD E=1 */
	delayms(1); /* delay for processing Tpw - Tdws = 190ns */
	
	DIO_WritePort(PORT_F_INDEX,PIN_3,STD_LOW); /* disable LCD E=0 */
	
}
