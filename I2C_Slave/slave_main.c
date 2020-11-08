/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
//#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>
#include "slave.h"

void main(void)
{
	unsigned char res='n';

	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT);

	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,6,DIO_OUTPUT);

	LCD_vInitialize();
	LCD_vWriteChar(res);
	i2c_initSlave(0x10);
	i2c_listen();
	res = i2c_receive(1);
	LCD_vWriteChar(res);
	res = i2c_receive(1);
	LCD_vWriteChar(res);
	res = i2c_receive(1);
	LCD_vWriteChar(res);
	while(1)
	{

	}

}

