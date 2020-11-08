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
#include <avr/delay.h>

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
						arr_pass[count_arr]=res;
						count_arr++;

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
////////////////////////////////////////////////////
void try3(u8 num_arr_real_pass ,u8 *arr_real_pass)
{
	u8 Global_count=0;
	u8 count=0;
	u8 Res_check;
	u8 arr_password[10];
	for(Global_count=3 ; Global_count>-1 ; Global_count--)
		{
			seven_seg_NumOutput(DIO_PORTC,Global_count);
			if(Global_count==3)
			{
				LCD_vWriteCommand(0b00000001);
				LCD_vWriteString("Enter Password");
				_delay_ms(500);
				count=enter_pass(arr_password);
				Res_check=check(arr_real_pass , arr_password , num_arr_real_pass , count);
				if(Res_check==0)
				{
					_delay_ms(500);
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
			else if(Global_count==2  || Global_count==1 )
			{
				count=enter_pass(arr_password);
				Res_check=check(arr_real_pass,arr_password,num_arr_real_pass,count);
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
							Res_check=check(arr_real_pass,arr_password,num_arr_real_pass,count);
							if(Res_check==0)
							{
								_delay_ms(1000);
								LCD_vWriteCommand(0b00000001);
								LCD_vWriteString("Finsh");
								DIO_vSetPin(DIO_PORTA,3); //Red LED
								DIO_vSetPin(DIO_PORTA,6); //buzzer
								break;
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
//////////////////////////////////////////////////
void Direc()
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
}


















