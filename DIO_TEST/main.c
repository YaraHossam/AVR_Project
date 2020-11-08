/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "DIO_interface.h"
#include "../_standard/datatypes.h"
#include <avr/delay.h>


void main(void)
{
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTC,7,DIO_OUTPUT);

	u8 ret;

	while(1)
	{

		ret=DIO_vGetPin(DIO_PORTA,0);
	if(ret==1)
	{
			DIO_vSetPin(DIO_PORTC,7);

		}
		else if(ret==0)
		{
			DIO_vClearPin(DIO_PORTC,7);
		}
//		DIO_vSetPin(DIO_PORTC,7);
//		_delay_ms(2000);
//		DIO_vClearPin(DIO_PORTC,7);
//		_delay_ms(2000);

	}

}


