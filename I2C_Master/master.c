/*
 * master.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include <avr/io.h>
#include "master.h"

void i2c_write(unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
}

void i2c_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
}

void i2c_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void i2c_init(void)
{
	//prescaler
	TWSR=0x00;
	TWBR= 0x47;
	TWCR =0x04;
}
