/*
 * main_RTOS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "RTOS_interface.h"
#include "Timer0_interface.h"
#include "DIO_interface.h"

void Control_LED1(void);
void Control_LED2(void);
void Control_LED3(void);

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTA , 0 , DIO_OUTPUT);

	DIO_vSetPinDirec(DIO_PORTB , 0 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB , 1 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB , 2 , DIO_OUTPUT);

	Timer0_initialize_Comp_mode();
	//DIO_vTogglePin(DIO_PORTA , 0);
	RTOS_intialize();
	RTOS_tstrTask obj;

	//creat object
	obj.Task_Function = Control_LED1;
	obj.Perdicity = 4 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 0);

	//creat object
	obj.Task_Function = Control_LED2;
	obj.Perdicity = 8 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 1);

	//creat object
	obj.Task_Function = Control_LED3;
	obj.Perdicity = 2 ;
	obj.Delay = 1 ;
	RTOS_vCreatTask(&obj , 2);

	while(1);

}

void Control_LED1(void)
{
	DIO_vTogglePin(DIO_PORTB , 0);
}

void Control_LED2(void)
{
	DIO_vTogglePin(DIO_PORTB , 1);
}

void Control_LED3(void)
{
	DIO_vTogglePin(DIO_PORTB , 2);
}
