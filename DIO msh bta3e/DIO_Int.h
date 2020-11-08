/*
 * DIO.Int.h
 *
 *  Created on: Oct 14, 2017
 *      Author: Lenovo
 */
#ifndef DIO_Int
#define DIO_Int
/*******************************************************************/

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_DDRA  0
#define DIO_DDRB  1
#define DIO_DDRC  2
#define DIO_DDRD  3
#define DIO_PINA  0
#define DIO_PINB  1
#define DIO_PINC  2
#define DIO_PIND  3

#define DIO_Input 0
#define DIO_Output 1

/************************************* FUNCTIONS PROTOTYPES ***************************************/

extern void DIO_vSetPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber) ;

extern void DIO_vSetPort(u8 Copy_u8PORT) ;

extern void DIO_vClrPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber);

extern void DIO_vClrPort(u8 Copy_u8PORT) ;

extern void DIO_vToggletPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber);

extern void DIO_vToggletPort(u8 Copy_u8PORT) ;

extern u8 DIO_vGetPin(u8 Copy_u8PIN , u8 Copy_u8PinNumber);

extern void DIO_vPort_Direction(u8 Copy_u8PORT , u8 Copy_u8PortDirection);

extern void DIO_vPin_Direction(u8 Copy_u8PORT , u8 Copy_u8PinNumber, u8 Copy_u8PortDirection);
















#endif
