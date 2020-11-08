/*
 * I2C_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "I2C_Interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>


void I2C_initialize_MASTER(void)
{
	TWSR = 0;
	//set prescaler bits to zero (TWPS1 , TWPS0) //1
	clearbit(TWSR,TWPS0);
	clearbit(TWSR,TWPS1);
	//SCL freq. ???????????????
	TWBR=0x47;
//	//Enable TWI Module
//		setbit(TWCR,TWEN);

	/*I2C start*/
	//Enable Interrupt TWINT
	setbit(TWCR , TWINT);
	//Start condition bit
	setbit(TWCR , TWSTA);
	//Enable TWI Module
	setbit(TWCR,TWEN);

}
void I2C_M_writeBYTE_S_sentBYTE(u8 Data)
{
	TWDR = Data;  //Data
	// enable interrupt & TWI Module
	setbit(TWCR , TWINT);
	setbit(TWCR,TWEN);

	// Wait for TWINT Flag Set
	while ((TWCR & (1<<TWINT)) == 0);
}

u8 I2C_M_readBYTE_S_receiveBYTE(void)
{
	// enable interrupt & TWI Module
		setbit(TWCR , TWINT);
		setbit(TWCR,TWEN);
	// Wait for TWINT Flag Set
		while ((TWCR & (1<<TWINT)) == 0);

		return TWDR;
}

void I2C_stop(void)
{
	// enable interrupt & TWI Module
		setbit(TWCR , TWINT);
		setbit(TWCR,TWEN);
	//End condition bit
		setbit(TWCR , TWSTO);
}
///////////////////////////////////////////////////////////////////////////////
void I2C_initialize_SLAVE(u8 slaveAddress)
{
	// enable TWI Module
		setbit(TWCR,TWEN);
	//set Address
		TWAR=slaveAddress;
	// enable interrupt & TWI Module
		setbit(TWCR , TWINT);
		setbit(TWCR,TWEN);

		//TWIE
		//
	//Acknowledge
		setbit(TWCR , TWEA);

}
void I2C_listen(void)
{
	//wait to be addressed
	while ((TWCR & (1<<TWINT)) == 0);
}
