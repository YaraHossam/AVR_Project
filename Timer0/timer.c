/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"

void TIMR0_intial_Overflow_mode(void);
void TIMER_intial_fast_PWM(void);

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTA , 0 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA , 1 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA , 2 , DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB , 3 , DIO_OUTPUT);

	DIO_vSetPin(DIO_PORTA , 0);
	DIO_vSetPin(DIO_PORTA , 1);
	DIO_vSetPin(DIO_PORTA , 2);

	TIMER_intial_fast_PWM();

	//TIMR0_intial_Overflow_mode();
	//sei() ;
	while(1)
	{

	}

}

void TIMR0_intial_Overflow_mode(void)
{
	/* wave generation mode */
	clearbit(TCCR0,3);
	clearbit(TCCR0,6);

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
//	static u8 count1=0;
//	static u8 count2=0;
//	static u8 count3=0;
//	count1 ++;
//	count2 ++;
//	count3 ++;
//
//	if(count1== 30){
//	DIO_vTogglePin(DIO_PORTA , 0);
//	count1 =0;
//	}
//
//	if(count2== 60){
//		DIO_vTogglePin(DIO_PORTA , 1);
//		count2 =0;
//		}
//	if(count3== 90){
//		DIO_vTogglePin(DIO_PORTA , 2);
//		count3 =0;
//		}

	static u8 count1=0;
	static u8 fl=0;
		count1++;
		if(count1== 50)
		{
			if(fl == 0){
				OCR0=OCR0+10;
			}
			else
			count1 =0;
		}

}

void TIMR0_intial_Comp_mode(void)
{
	/* Compare Match Output Mode */
	clearbit(TCCR0 , 4);
	clearbit(TCCR0 , 5);


	/* enable CMf interrupt  */
	setbit(TIMSK,1);

	/* enable global */
	setbit(SREG  , SREG_I);

	OCR0=150;

}

/*ISR(TIMER0_COMP_vect)
{
	static u8 count1=0;
	count1++;
	if(count1== 8)
	{
		OCR0=OCR0+10;
		count1 =0;
	}

}*/


void TIMER_intial_fast_PWM(void)
{
	/* pwm mode */
	setbit(TCCR0,3);
	setbit(TCCR0,6);

	/*Compare Output Mode, Fast PWM Mode*/
	setbit(TCCR0 , 4);
    setbit(TCCR0 , 5);

   OCR0=0;

   /* enable OVf interrupt  */
   	setbit(TIMSK,0);

   	/* enable global */
   	setbit(SREG  , SREG_I);

    /* Clock Select */
    	clearbit(TCCR0 , 0);
    	setbit(TCCR0 , 1);
    	clearbit(TCCR0 , 2);
}
