/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>

void main(void)
{
	//PORT D Colums
	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);




	for(int i=0 ; i<520 ; i++){
		DIO_vClearPin(DIO_PORTD,0);
		DIO_vClearPin(DIO_PORTD,1);
		DIO_vClearPin(DIO_PORTD,2);
		DIO_vSetPin(DIO_PORTD,3);
		_delay_ms(2);

		DIO_vClearPin(DIO_PORTD,0);
		DIO_vClearPin(DIO_PORTD,1);
		DIO_vSetPin(DIO_PORTD,2);
		DIO_vClearPin(DIO_PORTD,3);
		_delay_ms(2);

		DIO_vClearPin(DIO_PORTD,0);
		DIO_vSetPin(DIO_PORTD,1);
		DIO_vClearPin(DIO_PORTD,2);
		DIO_vClearPin(DIO_PORTD,3);
		_delay_ms(2);

		DIO_vSetPin(DIO_PORTD,0);
		DIO_vClearPin(DIO_PORTD,1);
		DIO_vClearPin(DIO_PORTD,2);
		DIO_vClearPin(DIO_PORTD,3);
		_delay_ms(2);



	}
	DIO_vClearPin(DIO_PORTD,0);
	DIO_vClearPin(DIO_PORTD,1);
	DIO_vClearPin(DIO_PORTD,2);
	DIO_vClearPin(DIO_PORTD,3);
    _delay_ms(500);

    for(int i=0 ; i<520 ; i++)
    {
    	DIO_vSetPin(DIO_PORTD,0);
    			DIO_vClearPin(DIO_PORTD,1);
    			DIO_vClearPin(DIO_PORTD,2);
    			DIO_vClearPin(DIO_PORTD,3);
    			_delay_ms(2);

    			DIO_vClearPin(DIO_PORTD,0);
    					DIO_vSetPin(DIO_PORTD,1);
    					DIO_vClearPin(DIO_PORTD,2);
    					DIO_vClearPin(DIO_PORTD,3);
    					_delay_ms(2);

    					DIO_vClearPin(DIO_PORTD,0);
    							DIO_vClearPin(DIO_PORTD,1);
    							DIO_vSetPin(DIO_PORTD,2);
    							DIO_vClearPin(DIO_PORTD,3);
    							_delay_ms(2);

    							DIO_vClearPin(DIO_PORTD,0);
    									DIO_vClearPin(DIO_PORTD,1);
    									DIO_vClearPin(DIO_PORTD,2);
    									DIO_vSetPin(DIO_PORTD,3);
    									_delay_ms(2);

    }

}
