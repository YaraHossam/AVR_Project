/*
 * EEPROM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "EEPROM.h"
#include "DIO_interface.h"
#include <avr/delay.h>
#include <avr/io.h>

u8 EEPROM_read(u16 Address)
{

	while(EECR & (1<<EEWE));
	EEAR = Address;
	setbit(EECR,EERE);
	return EEDR;
}


void EEPROM_write( u16 Address, u8 Data)
{
	while(EECR & (1<<EEWE));
	EEAR = Address;
	EEDR = Data;
	setbit(EECR,EEMWE);
	setbit(EECR,EEWE);
}
