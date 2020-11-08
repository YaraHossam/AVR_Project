/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "ADC.h"
#include <avr/delay.h>

void ADC_Init(unsigned char channel)
{
	DDRC&=(~(1<<channel));        /* Make ADC port as input */
	ADCSRA = 0x87;          /* Enable ADC, with freq/128  */
	ADMUX = 0x40;           /* Vref: Avcc, ADC channel: 0 */
}

unsigned char ADC_Read(unsigned char channel)
{
	ADMUX = 0x40 | (channel & 0x07);   /* set input channel to read */
	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
	_delay_ms(10);                      /* Wait a little bit */
	return ADCH;                       /* Return ADC word */
}
