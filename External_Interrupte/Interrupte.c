/*
 * Interrupte.c
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

void initialization_ADC0(void);
u16 ADC0_Read();

void main(void)
{

	u8 final_out;
	u8 read;
	u8 temp;
	u16 final_res[10];

	u16 res;
	initialization_ADC0();
	LCD_vInitialize();


	while(1){
	res =ADC0_Read();
	LCD_vWriteCommand(0b00000001);
	//LCD_vWriteChar(res+'0');
	final_out=(5*res*1000)/255;
	//read=final_out*1000;
	temp=final_out/10;

	res=temp;

	////////////
	final_res[0]=res/100;
						res=res%100;
						//LCD_vWriteChar(final_res[0]+'0');
						final_res[1]=res/10;
						res=res%10;
						//LCD_vWriteChar(final_res[1]+'0');
						final_res[2]=res;
						//LCD_vWriteChar(final_res[2]+'0');
						if(final_res[0]==0 && final_res[1]==0)
						{
							LCD_vWriteChar(final_res[2]+'0');
						}
						else if(final_res[0]==0 && final_res[1]!=0)
						{
							LCD_vWriteChar(final_res[1]+'0');
							LCD_vWriteChar(final_res[2]+'0');
						}
						else
						{
							LCD_vWriteChar(final_res[0]+'0');
							LCD_vWriteChar(final_res[1]+'0');
							LCD_vWriteChar(final_res[2]+'0');
						}
						_delay_ms(10);
	}


}

void initialization_INT0(void)
{
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_INPUT);
	//mode      falling mode
	setbit(MCUCR,ISC01);
	clearbit(MCUCR,ISC00);


	//enable int0
	setbit(GICR,6);

	// enable global int0
	setbit(SREG,7);


}

ISR (INT0_vect)
{
	togglebit(PORTA,0);
}

void initialization_ADC0(void)
{
	//ADMUX
	//Reference Selection Bits  //AVCC with external capacitor at AREF pin
	clearbit(ADMUX , REFS1);
	setbit(ADMUX , REFS0);
	//Left Adjust Result
	setbit(ADMUX,ADLAR);
	//Analog Channel
	clearbit(ADMUX , MUX4);
	clearbit(ADMUX , MUX3);
	clearbit(ADMUX , MUX2);
	clearbit(ADMUX , MUX1);
	clearbit(ADMUX , MUX0);

	//ADCSRA
	//Auto Trigger Enable
	clearbit(ADCSRA , ADATE);
	//Prescaler Select Bits
	clearbit(ADCSRA , ADPS0);
	clearbit(ADCSRA , ADPS1);
	clearbit(ADCSRA , ADPS2);
	//ADC Enable
	setbit(ADCSRA , ADEN);


}

u16 ADC0_Read()
{
	//ADCSRA
	//Start Conversion
	setbit(ADCSRA , ADSC);
	while (!getbit(ADCSRA ,ADIF))
	{

	}
	//clear flag
	setbit(ADCSRA ,ADIF);

	return ADCH;
}

