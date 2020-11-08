/*
 * main_RTOS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "RTOS_interface.h"
#include "Timer0_interface.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"

extern void TASK_KEYPAD(void);
extern void TASK_LCD(void);

u8 res ;

void main(void)
{

	DIO_vSetPortDirec(DIO_PORTC , DIO_OUTPUT); //LCD_DATA
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT); //LCD_RS
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT); //LCD_RW
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT); //ENABLE_LCD

	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT); //KeyPad_Colum0
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT); //KeyPad_Colum1
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT); //KeyPad_Colum2
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT); //KeyPad_Colum3
	DIO_vSetPinDirec(DIO_PORTD,4,DIO_INPUT); //KeyPad_Row0
	DIO_vSetPinDirec(DIO_PORTD,5,DIO_INPUT); //KeyPad_Row1
	DIO_vSetPinDirec(DIO_PORTD,6,DIO_INPUT); //KeyPad_Row2
	DIO_vSetPinDirec(DIO_PORTD,7,DIO_INPUT); //KeyPad_Row3

	//ENABLE PULL UP RESISTOR for keyPad
	DIO_vSetPin(DIO_PORTD,4);
	DIO_vSetPin(DIO_PORTD,5);
	DIO_vSetPin(DIO_PORTD,6);
	DIO_vSetPin(DIO_PORTD,7);

	LCD_vInitialize();

	Timer0_initialize_Comp_mode();
	RTOS_intialize();
	RTOS_tstrTask obj;

	//creat object
	obj.Task_Function = TASK_KEYPAD;
	obj.Perdicity = 1 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 1);

	//creat object
	obj.Task_Function = TASK_LCD;
	obj.Perdicity = 1 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 2);

	while(1);

}

void TASK_KEYPAD(void)
{
	res = Keypad_u8ReadKey();
}

void TASK_LCD(void)
{

	if (res != 100)
	{
		LCD_vWriteCommand(0b00000001);
		LCD_vWriteChar(res);
	}
}

