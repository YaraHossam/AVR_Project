/*
 * RTOS_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "Timer0_interface.h"
#include "RTOS_interface.h"
#include "RTOS_Config.h"

RTOS_tstrTask RTOS_astrTaskArr[RTOS_Tasks_Num];

void RTOS_intialize(void)
{
	u8 Local_count ;
	for(Local_count =0 ; Local_count < RTOS_Tasks_Num ; Local_count++)
	{
		RTOS_astrTaskArr[Local_count].Task_Function = NULL;
		RTOS_astrTaskArr[Local_count].Perdicity = NULL;
		RTOS_astrTaskArr[Local_count].Delay = NULL;

	}
	TIMER0_vSetCallback(RTOS_vScheduler);
}

void RTOS_vScheduler(void)
{
	u8 Local_count ;
	for(Local_count = 0 ; Local_count < RTOS_Tasks_Num ; Local_count++)
	{
		RTOS_astrTaskArr[Local_count].Delay --;
		if(RTOS_astrTaskArr[Local_count].Delay == 0)
		{
			if(RTOS_astrTaskArr[Local_count].Task_Function != NULL)
			{
				RTOS_astrTaskArr[Local_count].Task_Function();
				RTOS_astrTaskArr[Local_count].Delay = RTOS_astrTaskArr[Local_count].Perdicity;
			}
		}
	}
}
void RTOS_vCreatTask(RTOS_tstrTask * INP_Task , u8 Priotiy)
{
	RTOS_astrTaskArr[Priotiy].Task_Function = INP_Task->Task_Function;
	RTOS_astrTaskArr[Priotiy].Perdicity = INP_Task->Perdicity;
	RTOS_astrTaskArr[Priotiy].Delay = INP_Task->Delay;
}
