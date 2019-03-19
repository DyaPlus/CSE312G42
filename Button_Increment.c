#include "button.h"

void Button_Increment(void)
{	
while(!DIO_ReadPort(5,0x10))
		{
			num++;
			if(num==1000)
				num--;
			if(num==42)
			{
				LCD_displayStringRowColumn(1,7,"Bingo");
				delayms(1000);
			}
			//show on display
			LCD_clearScreen();
			LCD_intgerToString(num);
			
			delayms(200);
		}	
	}		