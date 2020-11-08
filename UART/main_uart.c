/*
 * main_uart.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "UART_FUN_Interface.h"
#include <avr/delay.h>

void main(void)
{
	DIO_vSetPortDirec(DIO_PORTD,DIO_OUTPUT);
	UART_vInitialize();
	_delay_ms(5000);
	UART_Tx('5');
	_delay_ms(1000);


}
