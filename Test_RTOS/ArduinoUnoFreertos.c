/*
 * ArduinoUnoFreertos.c
 *
 * Created: 10/01/2017 04:49:23 م
 *  Author: D.Randa and Hisham
 */ 

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>
#include <util/delay.h>

// declaration of two methods

//-----------------------------------------------------------

void Blink_200ms_task( void *pvParameters)
{
	DDRC |=(1<<0); //PA.0 is output
	
	while(1)
	{
		
		PORTC ^= (1<<0); //toggle PA.0
		vTaskDelay(200); //OS Delay
	}
}
//--------------------------------------------------
void Blink_1000ms_task( void *pvParameters)
{
	DDRB |=(1<<0); //PB.0 is output
	TickType_t xLastWakeTime;
	while(1)
	{

		PORTB ^= (1<<0); //toggle PB.0
		vTaskDelay(1000); //OS Delay
	}
}

int main(void)
{ 
	// Create Tasks
	xTaskCreate( Blink_200ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL );
	xTaskCreate( Blink_1000ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	
	// Start FreeRTOS
	vTaskStartScheduler();
}

//-----------------------------------------------------------

// method1 implementation 





// method2 implementation 