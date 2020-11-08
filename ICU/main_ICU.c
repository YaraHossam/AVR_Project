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
#include "LCD_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>
#define Tcount (0.000128)

u8 count_OVF = 0;


void main(void)
{
	DIO_vSetPinDirec(DIO_PORTB , 3 , DIO_OUTPUT);
	//LCD
	DIO_vSetPinDirec(DIO_PORTC,0,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,1,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,2,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,3,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,4,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,5,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,6,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTC,7,DIO_OUTPUT);

		DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT);
	 LCD_vInitialize();


}

void initialization_INT0(void)
{
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_INPUT);
	//mode      Any change
	clearbit(MCUCR,ISC01);
	setbit(MCUCR,ISC00);


	//enable int0
	setbit(GICR,6);

	// enable global int0
	setbit(SREG,7);


}

ISR (INT0_vect)
{
	u8 static counter =0;
	u8 static read;
	u8 time;
	u8 freq;
	u8 Tof;
	u8 DC;
	if(counter==0)
	{
		TCNT0=0;
		read=DIO_vGetPin(DIO_PORTD , 2);
		counter++;
	}
	if(counter==2)
	{
		time = TCNT0*Tcount+(count_OVF*255*Tcount);
		freq=1/time;
		if(read>0){
			DC=Tof/time;
		}
		else{
			DC=(time-Tof)/time;
		}
		LCD_vWriteString("DC = ");
		LCD_vWriteChar(DC+'0');
	}
	if(counter==1)
	{
		Tof = TCNT0 * Tcount+(count_OVF*255*Tcount);
		counter++;
	}

}

void TIMER_intial_fast_PWM(void)
{
	/* pwm mode */
	setbit(TCCR0,3);
	setbit(TCCR0,6);

	/*Compare Output Mode, Fast PWM Mode*/
	setbit(TCCR0 , 4);
    setbit(TCCR0 , 5);

   OCR0=150;

   /* enable OVf interrupt  */
   	setbit(TIMSK,0);

   	/* enable global */
   	setbit(SREG  , SREG_I);

    /* Clock Select */
    	setbit(TCCR0 , 0);
    	clearbit(TCCR0 , 1);
    	setbit(TCCR0 , 2);
}

ISR(TIMER0_OVF_vect)
{
	count_OVF++;
}
