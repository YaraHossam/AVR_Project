/*
 * main_APP.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "I2C_Interface.h"
#include "DIO_interface.h"
#include "DIO_Registers.h"
#include "LCD_interface.h"
#include <avr/delay.h>

void main(void)
{
	//LCD
		 LCD_vInitialize();
		 ///////////////////
	u8 res=0;

	 I2C_initialize_MASTER(32);
	 I2C_start ();
	 I2C_M_writeBYTE_S_sentBYTE(0b10100000);
	 I2C_M_writeBYTE_S_sentBYTE(10);
	 I2C_M_writeBYTE_S_sentBYTE(0);
	 _delay_ms(500);

	  I2C_start ();
	  I2C_M_writeBYTE_S_sentBYTE(0b10100000);
	  I2C_M_writeBYTE_S_sentBYTE(12);
	  I2C_start ();
	  I2C_M_writeBYTE_S_sentBYTE(0b10100001);
	  res=I2C_M_readBYTE_S_receiveBYTE();
	  I2C_stop();

	  LCD_vWriteChar(res+'0');

	 while(1);

}
