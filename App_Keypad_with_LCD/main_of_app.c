/*
 * main_of_app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>


void main(void)
{
	//Keypad Pins
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

		//intional
		DIO_vSetPin(DIO_PORTC,0);
		DIO_vSetPin(DIO_PORTC,1);
		DIO_vSetPin(DIO_PORTC,2);
		DIO_vSetPin(DIO_PORTC,3);

	//LCD Pins

	//LCD data pins
	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,6,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,7,DIO_OUTPUT);
	//LCD control pins
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT);


	LCD_vInitialize();
	LCD_vWriteChar('0');

	u8 res;

	while(1)
	{
		res=Keypad_u8ReadKey();
		if(res!=100)
		{
			if(res<10){
			LCD_vWriteCommand(0b00000001);
			LCD_vWriteChar(res+'0');
			}
			else{
				LCD_vWriteCommand(0b00000001);
				LCD_vWriteChar('1');
				LCD_vWriteChar((res%10)+'0');
			}
		}
		else
		{

		}



	}

}
