/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>


void main(void)
{
//	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
//	while(1){
//	//DIO_vSetPortvalue(DIO_PORTA,1);
//		DIO_vSetPin(DIO_PORTA,0);
//	_delay_ms(1000);
//	DIO_vClearPin(DIO_PORTA,0);
//	_delay_ms(1000);
//	}


	//DIO_vSetPinDirec(DIO_PORTC,0,DIO_INPUT);
	//DIO_vSetPinDirec(DIO_PORTC,1,DIO_INPUT);

	LCD_vInitialize();
	//LCD_vWriteChar('a');
	LCD_vWriteString("yara");
	while(1)
	{
//	      gotoXY(0,2);
		// LCD_vWriteChar('0');
//		 LCD_vWriteChar('a');
//		 LCD_vWriteChar('r');
//		 LCD_vWriteChar('a');
//		 _delay_ms(1000);
		// LCD_vWriteCommand(0b00000001);





	}

}

