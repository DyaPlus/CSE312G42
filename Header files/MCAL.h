// 0.Documentation Section 
// Runs on LM4F120 or TM4C123
// MCAL library contains initilazation-functions-prototypes of ports
// Authors: khaled ahmed abdelgalil
// Date: 18/3/2019
#include "tm4c123gh6pm.h"
#include "typedefs.h"

#ifndef MCAL_H_
#define MCAL_H_

/*Enum contains the direction of GPIO pins
0 for input 
1 for output
*/
enum Port_PinDirectionType {
	 PORT_PIN_IN = 0  , PORT_PIN_OUT = 1 
};

//functions prototype
void Port_SetPinDirection (uint8 port_index , uint8 pins_mask , enum Port_PinDirectionType pins_direction);
void Port_Init (uint8 port_index);
void Port_SetPinPullUp (uint8 port_index , uint8 pins_mask , uint8 enable);

#endif /* MCAL_H_ */
