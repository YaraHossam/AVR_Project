/*
 * fun_pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "fun_pro.h"

void initials_LCD(void)
{
	LCD_vInitialize();

}

void initials_KeyPad(void)
{
	DIO_vSetPin(DIO_PORTD,4);
	DIO_vSetPin(DIO_PORTD,5);
	DIO_vSetPin(DIO_PORTD,6);
	DIO_vSetPin(DIO_PORTD,7);

}

void initials_7seg(void)
{
	DIO_vSetPin(DIO_PORTC,0);
	DIO_vSetPin(DIO_PORTC,1);
	DIO_vSetPin(DIO_PORTC,2);
	DIO_vSetPin(DIO_PORTC,3);
	DIO_vSetPin(DIO_PORTC,4);
	DIO_vSetPin(DIO_PORTC,5);
	DIO_vSetPin(DIO_PORTC,6);


}

void initials_led_motor_buzzer(void)
{
	DIO_vClearPin(DIO_PORTA,3);
	DIO_vClearPin(DIO_PORTA,4);
	DIO_vClearPin(DIO_PORTA,5);

	DIO_vClearPin(DIO_PORTA,6);

	DIO_vClearPin(DIO_PORTA,7);
	DIO_vClearPin(DIO_PORTC,7);

}

u8 enter_pass(u8 *arr_pass)
{
	u8 res;
	u8 count_arr = 0;
	LCD_vWriteCommand(0b00000001);
	while(1)
	{
		res=Keypad_u8ReadKey();
				if(res!=100)
				{
					if(res<10){
					//LCD_vWriteCommand(0b00000001);
					arr_pass[count_arr]=res;
					count_arr++;
					LCD_vWriteChar(res+'0');
					}
					else if(res=='#')
					{
						LCD_vWriteCommand(0b00000001);
						break;
					}
					else{
						//LCD_vWriteCommand(0b00000001);

						LCD_vWriteChar(res);
					}
				}
				else
				{

				}


	}
	return count_arr;
}

u8 check(u8 * arr_realPass , u8 * arr_usePass , u8 Num_digit_realPass , u8 Num_digit_usePass)
{
	if(Num_digit_realPass != Num_digit_usePass)
	{
		LCD_vWriteCommand(0b00000001);
		LCD_vWriteString("Error");
		return 0;

	}
	else
	{
		for(int i=0 ; i<Num_digit_realPass ; i++)
		{
			if(arr_realPass[i]!= arr_usePass[i])
			{
				LCD_vWriteCommand(0b00000001);
				LCD_vWriteString("Error");
				return 0;
			}
			else
			{

			}
		}
		return 1;
	}

}




















