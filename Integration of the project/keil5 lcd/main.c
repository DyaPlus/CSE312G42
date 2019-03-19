#include "tm4c123gh6pm.h"
#include "lcd.h"
#include "delay.h"
#include "typedefs.h"
#include "MCAL.h"
#include "button.h"

int num=0;
int main(void){
	
	
	
	Port_Init(0);
	Port_Init(3);
	Port_Init(5);
	Port_SetPinDirection(5,0x10,PORT_PIN_IN);
	Port_SetPinPullUp(5,0x10,1);
	Port_SetPinDirection(0,0x0C,PORT_PIN_IN);
	Port_SetPinPullUp(0,0x0C,1);
	
	
	LCD_init();
	LCD_clearScreen();
			LCD_intgerToString(num);
	while(1){
	if(!DIO_ReadPort(5,0x10))
	{
		Button_Increment();
	}
	else if(!DIO_ReadPort(0,0x04))
	{
		Button_Decrement();
	}
	else if(!DIO_ReadPort(0,0x08))
	{
		Button_Reset();
	}
	
	}
	
	

}
