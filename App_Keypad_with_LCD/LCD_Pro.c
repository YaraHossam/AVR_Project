/*
 * LCD_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

// El functions bta3at 2l LCD (WriteChar,WritString.......)

#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>



void LCD_vWriteCommand(u8 copy_u8command)
{
	//RS control -> 0
	DIO_vClearPin(DIO_PORTA,LCD_RSPin);
	// RW control -> 0
	DIO_vClearPin(DIO_PORTA,LCD_RWPin);
	//Data output
	DIO_vSetPortvalue(DIO_PORTB,copy_u8command);
	//enable ->1
	DIO_vSetPin(DIO_PORTA,LCD_EnablePin);
	//delay
	_delay_ms(2);
	// disable ->0
	DIO_vClearPin(DIO_PORTA,LCD_EnablePin);
}

void LCD_vWriteChar(u8 copy_u8Char)
{
	//RS control -> 1
	DIO_vSetPin(DIO_PORTA,LCD_RSPin);
	// RW control -> 0
	DIO_vClearPin(DIO_PORTA,LCD_RWPin);
	//Data output
	DIO_vSetPortvalue(DIO_PORTB,copy_u8Char);
	//enable
	DIO_vSetPin(DIO_PORTA,LCD_EnablePin);
	//delay
	_delay_ms(2);
	// disable
	DIO_vClearPin(DIO_PORTA,LCD_EnablePin);
}

void LCD_vInitialize(void)
{
	//delay 500 ms
	_delay_ms(500);
	//writeCommand 0011 1000
	LCD_vWriteCommand(0b00111000);
	//delay 2 ms
	_delay_ms(2);
	//writeCommand 0000 1100
	LCD_vWriteCommand(0b00001100);
	//delay 2 ms
	_delay_ms(2);
	//writeCommand 0000 0001
	LCD_vWriteCommand(0b00000001);
	//delay 2 ms
	_delay_ms(2);
}

void gotoXY(u8 X,u8 Y)
{
	u8 Address;
	switch(X)
	{
	case 0:
		Address=Y;
		break;
	case 1:
		Address =Y+(0x40);
		break;
	}
	setbit(Address,7);
	 LCD_vWriteCommand(Address);
}



