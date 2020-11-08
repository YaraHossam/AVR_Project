/*
 * Keypad_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "DIO_interface.h"
#include "../_standard/datatypes.h"

#define Colums_Port DIO_PORTD // pins 0,1,2,3
#define Rows_Port DIO_PORTC // pins 0,1,2,3

extern u8 Keypad_u8ReadKey(void);


#endif /* KEYPAD_INTERFACE_H_ */
