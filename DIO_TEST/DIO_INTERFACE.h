/*
 * DIO_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef DIO_INT
#define DIO_INT
#include "../_standard/datatypes.h"

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3
#define DIO_INPUT  0
#define DIO_OUTPUT 1

extern void DIO_Vresetpin (u8 copy_u8PORT ,u8 copy_u8PINNUMBER );
extern void DIO_Vsetpin (u8 copy_u8PORT ,u8 copy_u8PINNUMBER ) ;
extern void DIO_Vtogglepin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER);
extern void DIO_Vsetport(u8 copy_u8PORT);
extern void DIO_Vresetport(u8 copy_u8PORT);
extern void DIO_Vsetpindirection(u8 copy_u8PORT ,u8 copy_u8PINNUMBER ,u8 copy_u8direction );
extern u8  DIO_getpin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER) ;
extern void DIO_Vsetportvalue(u8 copy_u8PORT,u8 copy_u8value);

#endif
