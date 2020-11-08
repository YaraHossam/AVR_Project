/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "DIO_interface.h"
#include <avr/delay.h>

void main (void)
{
	DIO_vSetPortDirec(DIO_PORTA,DIO_OUTPUT);

	while(1)
	{
		DIO_vSetPin(DIO_PORTA , 0);
		DIO_vClearPin(DIO_PORTA , 1);
		_delay_ms(1000);
		DIO_vClearPin(DIO_PORTA , 0);
		DIO_vClearPin(DIO_PORTA , 1);
		_delay_ms(500);
		DIO_vSetPin(DIO_PORTA , 1);
		DIO_vClearPin(DIO_PORTA , 0);
		_delay_ms(1000);
	}
}

