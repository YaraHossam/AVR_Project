/*
 * main_storehouse.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "seven_segment_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>
#include "fun_pro.h"
//#include "EEPROM.h"
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


void main(void)
{
	//Direc();
/////////////////////////////////////////////////////////////////////////////////////
	//initials_LCD();
	//initials_KeyPad();
	//initials_7seg();
	//initials_led_motor_buzzer();
////////////////////////////////////////////////////////////

	//num of index of real password
	//u8 num_arr_real_pass_A = 5;
	//u8 arr_real_pass_A[5]={1,2,3,4,5};
	//try3(num_arr_real_pass_A ,arr_real_pass_A );

/////////////////////////////////////////////////////////////////
	// u8 data = '5';
	// EEPROM_write(0x0000, data);
	// u8 res;
	// res =EEPROM_read(0x0000);
	// LCD_vWriteChar(res);

	DDRC = 0xFF;

		u8 data;
		EEPROM_write(0x0000, 0);
		_delay_ms(1000);
		data = EEPROM_read(0x0000);
		PORTC =data;
		//data++;
		//EEPROM_write(0x0000, data);
		//_delay_ms(1000);



	 while(1);
}
///////////////////////////////////////end main///////////////////////////////


