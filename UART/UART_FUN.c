/*
 * UART_FUN.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "UART_FUN_Interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void UART_vInitialize(void)
{
	//UCSRC
	UCSRC=0b10101110;

	//UCSZ2 bit 2
		clearbit(UCSRB , 2);

	clearbit(UCSRC,7);
	UBRRL=51;



}

u8 UART_Rx(void)
{
	setbit(UCSRB,4);
	while ( !(UCSRA & (1<<RXC)) ); // Check on Receiver Copmlete
		return UDR ;

}

void UART_Tx(u8 Data)
{
	setbit(UCSRB,4);
	while ( !( UCSRA & (1<<UDRE)) ); // if the register empty
		UDR= Data;

}
