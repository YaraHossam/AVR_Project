/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>

void main(void)
{
	//PORT D Colums
	DIO_vSetPinDirec(DIO_PORTD,0,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_INPUT);

	DIO_vSetPin(DIO_PORTD,0);
	DIO_vSetPin(DIO_PORTD,1);
	DIO_vSetPin(DIO_PORTD,2);
	DIO_vSetPin(DIO_PORTD,3);


	//buzzer
	DIO_vSetPinDirec(DIO_PORTA,7,DIO_OUTPUT);

	u8 Res;
	u8 count=0;

	while(1)
	{
		if(DIO_vGetPin(DIO_PORTD,0)==0)
		{
			DIO_vSetPin(DIO_PORTA,7);
			_delay_ms(10);
			DIO_vClearPin(DIO_PORTA,7);
			_delay_ms(10);
		}
		else if(DIO_vGetPin(DIO_PORTD,1)==0)
		{
			DIO_vSetPin(DIO_PORTA,7);
			_delay_ms(2);
			DIO_vClearPin(DIO_PORTA,7);
			_delay_ms(2);
		}
		else if(DIO_vGetPin(DIO_PORTD,2)==0)
		{
					DIO_vSetPin(DIO_PORTA,7);
					_delay_ms(150);
					DIO_vClearPin(DIO_PORTA,7);
					_delay_ms(2);
		}
		else
		{

		}


	}

}

