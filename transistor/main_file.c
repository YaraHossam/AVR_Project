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

u8 res;

void main(void)
{

	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,1,DIO_INPUT);



	while(1)
	{

		res=DIO_vGetPin(DIO_PORTC,0);
		if(res==0)
		{
			DIO_vSetPin(DIO_PORTD,0);
		}
		else if(res==1)
		{
			DIO_vClearPin(DIO_PORTD,0);
		}



	}

}
