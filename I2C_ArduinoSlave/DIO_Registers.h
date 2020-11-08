/*
 * DIO_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#ifndef DIO_Resgisters
#define DIO_Resgisters
#include "../_standard/datatypes.h"

#define PORTB (*(volatile u8 *)0x25)
#define PORTC (*(volatile u8 *)0x28)
#define PORTD (*(volatile u8 *)0x2B)

#define DDRB (*(volatile u8 *)0x24)
#define DDRC (*(volatile u8 *)0x27)
#define DDRD (*(volatile u8 *)0x2A)

#define PINB (*(volatile u8 *)0x23)
#define PINC (*(volatile u8 *)0x26)
#define PIND (*(volatile u8 *)0x29)

#endif
