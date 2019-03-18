#include "DGPIO.h" 

/* LCD DMACROS*/
#define RS(X)     GPIO_PORTF_DATA_R = ((GPIO_PORTF_DATA_R & ~(1<<1)) | (X<<1)) // RS is bit 1
#define EN(X)     GPIO_PORTF_DATA_R = ((GPIO_PORTF_DATA_R & ~(1<<2)) | (X<<2)) // EN is bit 2

void LCDWriteByte(unsigned char LCDData) {
GPIOPortWrite(LCDData,PORTD_P, 0x0F);
//GPIOPortWrite(LCDData,PORTB_P, 0x20);
GPIOPortWrite(LCDData,PORTA_P, 0xF0);
EN(1);
delayms(1);
EN(0);
}

void LCD_command(unsigned char LCDData) {//Function to pass command to the LCD 
	
RS(0); //RS = 0 since command to LCD
LCDWriteByte(LCDData); //Send data on LCD data bus

}

void LCD_data(unsigned char LCDData) {//Function to write data to the LCD
	
RS(1);//RS = 1 since data to LCD
LCDWriteByte(LCDData);
RS(0);
}

void InitLCD(void) {
	delayms(200);
	LCD_command(0x30);
	delayms(20);
	LCD_command(0x30);
	delayms(20);
	LCD_command(0x30);
	delayms(20);
	LCD_command(0x38);
	delayms(20);
	LCD_command(0x08);
	delayms(20);
	LCD_command(0x01);
	delayms(20);
	LCD_command(0x06);
	delayms(20);
	LCD_command(0x0C);
	delayms(20);
	
}
