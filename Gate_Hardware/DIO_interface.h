/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../_standard/datatypes.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_INPUT 0
#define DIO_OUTPUT 1

extern void DIO_vSetPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber); //fun1
extern void DIO_vClearPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber);  //fun2
extern void DIO_vTogglePin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber);  //fun3

extern u8 DIO_vGetPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber); //fun4

extern void DIO_vSetPort(u8 Copy_u8PORTNumber);  //fun5
extern void DIO_vClearPort(u8 Copy_u8PORTNumber);  //fun6
extern void DIO_vSetPinDirec(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber,u8 Copy_u8Direc);  //fun7
extern void DIO_vToggletPort(u8 Copy_u8PORTNumber);  //fun8

extern void DIO_vSetPortvalue(u8 Copy_u8PORTNumber,u8 Copy_u8value);  //fun9
extern void DIO_vSetPortDirec(u8 Copy_u8PORTNumber ,u8 Copy_u8Direc); //fun10

#endif /* DIO_INTERFACE_H_ */
