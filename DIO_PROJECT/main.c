/*
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: Yara
 */
#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "../_standard/datatypes.h"
#include <avr/delay.h>

#define setbit(reg,bitnumber) reg|=(1<<bitnumber)
#define clearbit(reg,bitnumber) reg&=(~(1<<bitnumber))
#define togglebit(reg,bitnumber) reg^=(1<<bitnumber)
#define getbit(reg,bitnumber) ((reg&(1<<bitnumber))>>bitnumber)


#include <avr/io.h>

u8 read(u16 Address)
{

	while(EECR & (1<<EEWE));
	EEAR = Address;
	setbit(EECR,EERE);
	return EEDR;
}
void write( u16 Address, u8 Data)
{
	while(EECR & (1<<EEWE));
	EEAR = Address;
	EEDR = Data;
	setbit(EECR,EEMWE);
	setbit(EECR,EEWE);
}

int main(void)
{
	DDRC = 0xFF;

	u8 data;
	data = read(0x0001);
	PORTC =data;
	data++;
	write(0x0001, data);
	while(1);
}


//void main(void)
//{
//	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
//	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT);
//	DIO_vSetPinDirec(DIO_PORTC,2,DIO_OUTPUT);
//	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);
//
//	while(1)
//	{
//		DIO_vSetPin(DIO_PORTA,0);
//		DIO_vSetPin(DIO_PORTB,5);
//		DIO_vSetPin(DIO_PORTC,2);
//		DIO_vSetPin(DIO_PORTD,3);
//		_delay_ms(1000);
//
//		DIO_vClearPin(DIO_PORTA,0);
//		DIO_vClearPin(DIO_PORTB,5);
//		DIO_vClearPin(DIO_PORTC,2);
//		DIO_vClearPin(DIO_PORTD,3);
//		_delay_ms(1000);
//
//	}
//
//}
