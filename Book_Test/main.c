/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "DIO_interface.h"
#include <avr/delay.h>

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTD , 0 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD , 1 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD , 2 , DIO_OUTPUT);

	DIO_vSetPin(DIO_PORTD , 0);
	DIO_vSetPin(DIO_PORTD , 1);
	DIO_vSetPin(DIO_PORTD , 2);

	_delay_ms(1000);


	while(1){

	}
}

