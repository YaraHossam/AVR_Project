/*
 * main_seven_segment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "../_standard/datatypes.h"
#include "DIO_interface.h"
#include "seven_segment_interface.h"
#include <avr/delay.h>

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTC,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,6,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTC,7,DIO_OUTPUT);

	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,6,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTD,7,DIO_OUTPUT);


	seven_seg_NumOutput(DIO_PORTC,2);

//	while(1)
//	{
//		for(int i=0 ; i<=6 ; i++)
//		{
//			seven_seg_NumOutput(DIO_PORTC,i);
//			for(int j=0 ; j<=9 ;j++)
//			{
//				seven_seg_NumOutput(DIO_PORTD,j);
//				_delay_ms(1000);
//			}
//
//
//		}
//	}

}
