/*
 * main_file.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "../_standard/datatypes.h"
#include <avr/delay.h>

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT);



	while(1)
	{

		DIO_vSetPin(DIO_PORTB,0);
		_delay_ms(2);


		DIO_vClearPin(DIO_PORTB,0);
		_delay_ms(2);




	}
}

