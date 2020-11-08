/*
 * main_storehouse.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "DIO_interface.h"
#include "seven_segment_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>
#include "fun_pro.h"

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT); //LCD_RS
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT); //LCD_RW
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT); //ENABLE_LCD
	DIO_vSetPinDirec(DIO_PORTA,3,DIO_OUTPUT); //LED_RED
	DIO_vSetPinDirec(DIO_PORTA,4,DIO_OUTPUT); //LED_YELLOW
	DIO_vSetPinDirec(DIO_PORTA,5,DIO_OUTPUT); //LED_GREEN
	DIO_vSetPinDirec(DIO_PORTA,6,DIO_OUTPUT); //BUZZER
	DIO_vSetPinDirec(DIO_PORTA,7,DIO_OUTPUT); //MOTOR

	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT); //LCD_D0
	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT); //LCD_D1
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT); //LCD_D2
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT); //LCD_D3
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT); //LCD_D4
	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT); //LCD_D5
	DIO_vSetPinDirec(DIO_PORTB,6,DIO_OUTPUT); //LCD_D6
	DIO_vSetPinDirec(DIO_PORTB,7,DIO_OUTPUT); //LCD_D7

	DIO_vSetPinDirec(DIO_PORTC,0,DIO_OUTPUT); //7seg_L0
	DIO_vSetPinDirec(DIO_PORTC,1,DIO_OUTPUT); //7seg_L1
	DIO_vSetPinDirec(DIO_PORTC,2,DIO_OUTPUT); //7seg_L2
	DIO_vSetPinDirec(DIO_PORTC,3,DIO_OUTPUT); //7seg_L3
	DIO_vSetPinDirec(DIO_PORTC,4,DIO_OUTPUT); //7seg_L4
	DIO_vSetPinDirec(DIO_PORTC,5,DIO_OUTPUT); //7seg_L5
	DIO_vSetPinDirec(DIO_PORTC,6,DIO_OUTPUT); //7seg_L6
	DIO_vSetPinDirec(DIO_PORTC,7,DIO_OUTPUT); //motor

	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT); //KeyPad_Colum0
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT); //KeyPad_Colum1
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT); //KeyPad_Colum2
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT); //KeyPad_Colum3
	DIO_vSetPinDirec(DIO_PORTD,4,DIO_INPUT); //KeyPad_Row0
	DIO_vSetPinDirec(DIO_PORTD,5,DIO_INPUT); //KeyPad_Row1
	DIO_vSetPinDirec(DIO_PORTD,6,DIO_INPUT); //KeyPad_Row2
	DIO_vSetPinDirec(DIO_PORTD,7,DIO_INPUT); //KeyPad_Row3
/////////////////////////////////////////////////////////////////////////////////////

	initials_LCD();
	initials_KeyPad();
	initials_7seg();
	initials_led_motor_buzzer();

	LCD_vWriteChar('Y');


}

