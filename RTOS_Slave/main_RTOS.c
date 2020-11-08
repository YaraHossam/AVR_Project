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


extern void TASK_LCD(void);
extern void TASK_Motor(void);
extern void TASK_Rec(void);

u8 res='n' ;

void main(void)
{


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
		LCD_vWriteChar('l');

	Timer0_initialize_Comp_mode();
	RTOS_intialize();
	RTOS_tstrTask obj;

	//creat object
	obj.Task_Function = TASK_Rec;
	obj.Perdicity = 1 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 1);

	//creat object
	obj.Task_Function = TASK_Motor;
	obj.Perdicity = 1 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 2);

	//creat object
		obj.Task_Function = TASK_LCD;
		obj.Perdicity = 2 ;
		obj.Delay = 2 ;
		RTOS_vCreatTask(&obj , 3);

	while(1);

}


void TASK_LCD(void)
{

	if (res != 'n')
	{
		LCD_vWriteCommand(0b00000001);
		LCD_vWriteChar(res);
	}
}

void TASK_Motor(void)
{

}

void TASK_Rec(void)
{
	res = i2c_receive(1);
}





