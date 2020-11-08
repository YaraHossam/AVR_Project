/*
 * slave.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include <avr/io.h>
#include "slave.h"
void i2c_initSlave(unsigned char slaveAddress)
{
	TWCR = 0x04;
	TWAR = slaveAddress;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

}

unsigned char i2c_receive(unsigned char islast)
{
	if (islast ==0)
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	else
		TWCR = (1<<TWINT)|(1<<TWEN);

	while((TWCR & (1<<TWINT))==0);

	return (TWDR);
}

void i2c_listen()
{
	while((TWCR & (1<<TWINT))==0);
}
