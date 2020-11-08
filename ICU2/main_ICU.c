/*
 * main_ICU.c
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
#include "KEYPad.h"


void main(void)
{
	LCD_vInitialize();
	char C;
	C=keypad();
	LCD_vWriteChar(C);


}
