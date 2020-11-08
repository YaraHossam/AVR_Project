/*
 * main_key.c
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
	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);

	//PORT C Rows
	DIO_vSetPinDirec(DIO_PORTC,0,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTC,1,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTC,2,DIO_INPUT);
	DIO_vSetPinDirec(DIO_PORTC,3,DIO_INPUT);

	//
	DIO_vSetPin(DIO_PORTC,0);
	DIO_vSetPin(DIO_PORTC,1);
	DIO_vSetPin(DIO_PORTC,2);
	DIO_vSetPin(DIO_PORTC,3);

	//LED
	DIO_vSetPinDirec(DIO_PORTA,7,DIO_OUTPUT);

	u8 Res;
	u8 count=0;

	while(1)
	{
		Res=Keypad_u8ReadKey();

		if(Res!=100)
		{
			if(count%2==0)
			{
			DIO_vSetPin(DIO_PORTA,7);
			}
			else
			{
				DIO_vClearPin(DIO_PORTA,7);
			}
			count++;

		}
		else
		{

		}
	}

}
