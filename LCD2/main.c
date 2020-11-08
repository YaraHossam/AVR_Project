/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>
#include "Keypad_interface.h"
#include "LCD_interface.h"

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,6,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,7,DIO_OUTPUT);

	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT);  //A0
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT);  //A1
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT); //WR
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT); //RD

	//DIS RD
	DIO_vSetPin(DIO_PORTB,4);
	//DIS WR
	DIO_vSetPin(DIO_PORTB,3);

	//set control register
	//a1 , a0 -> 11 ---------> ADDER
	DIO_vSetPin(DIO_PORTB,1);
	DIO_vSetPin(DIO_PORTB,2);
	//VALL
	DIO_vClearPin(DIO_PORTD,0);
	DIO_vClearPin(DIO_PORTD,1);
	DIO_vClearPin(DIO_PORTD,2);
	DIO_vSetPin(DIO_PORTD,3);
	DIO_vClearPin(DIO_PORTD,4);
	DIO_vClearPin(DIO_PORTD,5);
	DIO_vClearPin(DIO_PORTD,6);
	DIO_vSetPin(DIO_PORTD,7);
	//enable WR
	DIO_vClearPin(DIO_PORTB,3);
	_delay_ms(500);

	DIO_vSetPin(DIO_PORTB,3); //dis WR
	//ADDRES
	DIO_vSetPin(DIO_PORTB,1);
	DIO_vClearPin(DIO_PORTB,2);
	DIO_vClearPin(DIO_PORTB,3);
	LCD_vInitialize();
	LCD_vWriteChar('y');

while(1)
{

}

}

