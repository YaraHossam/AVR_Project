/*
 * DIO_Reg.h
 *
 *  Created on: Oct 14, 2017
 *      Author: Lenovo
 */
#ifndef DIO_Reg
#define DIO_Reg

#include "../standard/bitcalc.h"
#include "../standard/datatypes.h"

/***********  PORT **************/
#define PORTA ( *((volatile u8 *)0x3b) )

#define PORTB ( *((volatile char *)0x38) )

#define PORTC ( *((volatile char *)0x35) )

#define PORTD ( *((volatile char *)0x32) )

/***********  PIN ***************/
#define PINA ( *((volatile char *)0x39) )

#define PINB ( *((volatile char *)0x36) )

#define PINC ( *((volatile char *)0x33) )

#define PIND ( *((volatile char *)0x30) )

/************* DDR ***************/
#define DDRA ( *((volatile char *)0x3a) )

#define DDRB ( *((volatile char *)0x37) )

#define DDRC ( *((volatile char *)0x34) )

#define DDRD ( *((volatile char *)0x31) )






























#endif
