/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include <avr/io.h>
#include <avr/delay.h>

void main(void)
{
	DDRA=0b00000001;
	DDRD=0b00000000;
	DDRC=0b00000000;

	while(1){

		if(PIND==1){
		PORTA = 1;
		_delay_ms(50);
		PORTA=0;
		_delay_ms(50);
		}
		else if(PINC==1){
		PORTA = 1;
		_delay_ms(1000);
		PORTA=0;
		_delay_ms(1000);
		}
		else if (PINC==0 && PIND==0){
			PORTA=0;
		}
	}

}
