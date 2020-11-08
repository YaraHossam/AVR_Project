/*
 * main_storehouse.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "DIO_interface.h"
#include "seven_segment_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>
#include "fun_pro.h"

u8 Global_count=0;

void main(void)
{
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT); //LCD_RS
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT); //LCD_RW
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT); //ENABLE_LCD
	DIO_vSetPinDirec(DIO_PORTA,3,DIO_OUTPUT); //LED_RED
	DIO_vSetPinDirec(DIO_PORTA,4,DIO_OUTPUT); //LED_YELLOW
	DIO_vSetPinDirec(DIO_PORTA,5,DIO_OUTPUT); //LED_GREEN
	DIO_vSetPinDirec(DIO_PORTA,6,DIO_OUTPUT); //BUZZER
	DIO_vSetPinDirec(DIO_PORTA,7,DIO_OUTPUT); //MOTOR

	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT); //LCD_D0
	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT); //LCD_D1
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT); //LCD_D2
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT); //LCD_D3
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT); //LCD_D4
	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT); //LCD_D5
	DIO_vSetPinDirec(DIO_PORTB,6,DIO_OUTPUT); //LCD_D6
	DIO_vSetPinDirec(DIO_PORTB,7,DIO_OUTPUT); //LCD_D7

	DIO_vSetPinDirec(DIO_PORTC,0,DIO_OUTPUT); //7seg_L0
	DIO_vSetPinDirec(DIO_PORTC,1,DIO_OUTPUT); //7seg_L1
	DIO_vSetPinDirec(DIO_PORTC,2,DIO_OUTPUT); //7seg_L2
	DIO_vSetPinDirec(DIO_PORTC,3,DIO_OUTPUT); //7seg_L3
	DIO_vSetPinDirec(DIO_PORTC,4,DIO_OUTPUT); //7seg_L4
	DIO_vSetPinDirec(DIO_PORTC,5,DIO_OUTPUT); //7seg_L5
	DIO_vSetPinDirec(DIO_PORTC,6,DIO_OUTPUT); //7seg_L6
	DIO_vSetPinDirec(DIO_PORTC,7,DIO_OUTPUT); //motor

	DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT); //KeyPad_Colum0
	DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT); //KeyPad_Colum1
	DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT); //KeyPad_Colum2
	DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT); //KeyPad_Colum3
	DIO_vSetPinDirec(DIO_PORTD,4,DIO_INPUT); //KeyPad_Row0
	DIO_vSetPinDirec(DIO_PORTD,5,DIO_INPUT); //KeyPad_Row1
	DIO_vSetPinDirec(DIO_PORTD,6,DIO_INPUT); //KeyPad_Row2
	DIO_vSetPinDirec(DIO_PORTD,7,DIO_INPUT); //KeyPad_Row3
/////////////////////////////////////////////////////////////////////////////////////

	initials_LCD();
	initials_KeyPad();
	initials_7seg();
	initials_led_motor_buzzer();
	u8 count=0;
	u8 Res_check;

	u8 arr_password[10];
	u8 arr_real_pass[5]={1,2,3,4,5};


	for(Global_count=3 ; Global_count>-1 ; Global_count--)
	{
		seven_seg_NumOutput(DIO_PORTC,Global_count);
		if(Global_count==3)
		{
			count=enter_pass(arr_password);
			Res_check=check(arr_real_pass,arr_password,5,count);
			if(Res_check==0)
			{
				_delay_ms(1000);
				LCD_vWriteCommand(0b00000001);
				LCD_vWriteString("Enter Password");
				gotoXY(1,0);
				LCD_vWriteString("Again");
				_delay_ms(500);
			}
			else if(Res_check==1)
			{
				DIO_vSetPin(DIO_PORTA,5); //Green LED
				DIO_vSetPin(DIO_PORTA,7); //Motor
				_delay_ms(1000);
			}
		}
		else if(Global_count==2)
		{
			count=enter_pass(arr_password);
			Res_check=check(arr_real_pass,arr_password,5,count);
			if(Res_check==0)
			{
				_delay_ms(1000);
				LCD_vWriteCommand(0b00000001);
				LCD_vWriteString("Enter Password");
				gotoXY(1,0);
				LCD_vWriteString("Again");
				_delay_ms(500);
			}
			else if(Res_check==1)
			{
				DIO_vSetPin(DIO_PORTA,5); //Green LED
				DIO_vSetPin(DIO_PORTA,7); //Motor
				_delay_ms(1000);
			}
		}
		else if(Global_count==1)
		{
			count=enter_pass(arr_password);
						Res_check=check(arr_real_pass,arr_password,5,count);
						if(Res_check==0)
						{
							_delay_ms(1000);
							LCD_vWriteCommand(0b00000001);
							LCD_vWriteString("Enter Password");
							gotoXY(1,0);
							LCD_vWriteString("Again");
							_delay_ms(500);
						}
						else if(Res_check==1)
						{
							DIO_vSetPin(DIO_PORTA,5); //Green LED
							DIO_vSetPin(DIO_PORTA,7); //Motor
							_delay_ms(1000);
						}
		}
		else if(Global_count==0)
		{
			count=enter_pass(arr_password);
						Res_check=check(arr_real_pass,arr_password,5,count);
						if(Res_check==0)
						{
							_delay_ms(1000);
							LCD_vWriteCommand(0b00000001);
							LCD_vWriteString("Finsh");
							DIO_vSetPin(DIO_PORTA,3); //Red LED
							DIO_vSetPin(DIO_PORTA,6); //buzzer
						}
						else if(Res_check==1)
						{
							DIO_vSetPin(DIO_PORTA,5); //Green LED
							DIO_vSetPin(DIO_PORTA,7); //Motor
							_delay_ms(1000);
						}
		}
	}




}

