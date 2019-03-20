#include "button.h"
void Button_Decrement(void)
{	
if(num!=0){
		num--;
		LCD_clearScreen();
		LCD_intgerToString(num);
		//show on display
		while(!DIO_ReadPort(0,0x04));
		}
	}