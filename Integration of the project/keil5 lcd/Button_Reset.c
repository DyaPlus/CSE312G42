#include "button.h"
void Button_Reset(void)
{

		num=0;
		while(!DIO_ReadPort(0,0x08));
		LCD_clearScreen();
		LCD_intgerToString(num);
}