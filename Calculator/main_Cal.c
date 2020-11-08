/*
 * main_Cal.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "../_standard/calcbit.h"
#include <avr/delay.h>

s16 final_res[3];

s16 add(u8 num1,u8 num2);
s16 sub(u8 num1,u8 num2);
s16 mult(u8 num1,u8 num2);
s16 dev(u8 num1,u8 num2);
s16 operator(u8 num1 , u8 num2 , u8 op);
void fun_t2sem(s8 arr[],u8 size ,u8 num_of_op, u8 num_of_eq );

void main(void)
{
	//Keypad Pins
	   //PORT D Colums
		DIO_vSetPinDirec(DIO_PORTD,0,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTD,1,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTD,2,DIO_OUTPUT);
		DIO_vSetPinDirec(DIO_PORTD,3,DIO_OUTPUT);

		//PORT D Rows
		DIO_vSetPinDirec(DIO_PORTD,4,DIO_INPUT);
		DIO_vSetPinDirec(DIO_PORTD,5,DIO_INPUT);
		DIO_vSetPinDirec(DIO_PORTD,6,DIO_INPUT);
		DIO_vSetPinDirec(DIO_PORTD,7,DIO_INPUT);

		//intional
		DIO_vSetPin(DIO_PORTD,4);
		DIO_vSetPin(DIO_PORTD,5);
		DIO_vSetPin(DIO_PORTD,6);
		DIO_vSetPin(DIO_PORTD,7);

	//LCD Pins

	//LCD data pins
	DIO_vSetPinDirec(DIO_PORTB,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,2,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,3,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,4,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,5,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,6,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTB,7,DIO_OUTPUT);
	//LCD control pins
	DIO_vSetPinDirec(DIO_PORTA,0,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,1,DIO_OUTPUT);
	DIO_vSetPinDirec(DIO_PORTA,2,DIO_OUTPUT);


	LCD_vInitialize();
	LCD_vWriteChar('0');

	u8 res;
	s16 the_Res;
	u8 count=0;
	s8 arr[6];
	u8 num_of_op;
	u8 num_of_eq;



	while(1)
	{
		res=Keypad_u8ReadKey();
		//first num
		if(res<10 && count==0)
		{
			LCD_vWriteCommand(0b00000001);
			LCD_vWriteChar(res+'0');
			arr[count]=res;
			count++;
		}
		//normal num
		else if(res<10 && count!=0)
		{
			LCD_vWriteChar(res+'0');
			arr[count]=res;
			count++;
		}

		//op
		else if(res>10 && res<100)
		{

			LCD_vWriteChar(res);
			if(res=='=')
			{

				num_of_eq=count;
				fun_t2sem(arr,6,num_of_op,num_of_eq );
				the_Res=operator(final_res[0],final_res[2],final_res[1]);
				if(the_Res>=0)
				{
					final_res[0]=the_Res/100;
					the_Res=the_Res%100;
					//LCD_vWriteChar(final_res[0]+'0');
					final_res[1]=the_Res/10;
					the_Res=the_Res%10;
					//LCD_vWriteChar(final_res[1]+'0');
					final_res[2]=the_Res;
					//LCD_vWriteChar(final_res[2]+'0');
					if(final_res[0]==0 && final_res[1]==0)
					{
						LCD_vWriteChar(final_res[2]+'0');
					}
					else if(final_res[0]==0 && final_res[1]!=0)
					{
						LCD_vWriteChar(final_res[1]+'0');
						LCD_vWriteChar(final_res[2]+'0');
					}
					else
					{
						LCD_vWriteChar(final_res[0]+'0');
						LCD_vWriteChar(final_res[1]+'0');
						LCD_vWriteChar(final_res[2]+'0');
					}
				}
				else
				{
					LCD_vWriteChar('-');
					the_Res=the_Res*(-1);
					                   final_res[0]=the_Res/100;
										the_Res=the_Res%100;
										//LCD_vWriteChar(final_res[0]+'0');
										final_res[1]=the_Res/10;
										the_Res=the_Res%10;
										//LCD_vWriteChar(final_res[1]+'0');
										final_res[2]=the_Res;
										//LCD_vWriteChar(final_res[2]+'0');
										if(final_res[0]==0 && final_res[1]==0)
										{
											LCD_vWriteChar(final_res[2]+'0');
										}
										else if(final_res[0]==0 && final_res[1]!=0)
										{
											LCD_vWriteChar(final_res[1]+'0');
											LCD_vWriteChar(final_res[2]+'0');
										}
										else
										{
											LCD_vWriteChar(final_res[0]+'0');
											LCD_vWriteChar(final_res[1]+'0');
											LCD_vWriteChar(final_res[2]+'0');
										}

				}

			}
			else if(res=='.')
			{
				LCD_vWriteCommand(0b00000001);
				count=0;
			}
			else
			{
				arr[count]=res;
				num_of_op=count;
				count++;
			}


		}
		else
		{

		}



	}

}

//fun add +
s16 add(u8 num1,u8 num2){
	return num1+num2;
}
//fun sub -
s16 sub(u8 num1,u8 num2){
	return num1-num2;
}
//fun mult *
s16 mult(u8 num1,u8 num2){
	return num1*num2;
}
//fun dev /
s16 dev(u8 num1,u8 num2){
	if(num2 == 0){
		return 0;
	}
	else{
		return num1/num2;
	}
}

//fun
s16 operator(u8 num1 , u8 num2 , u8 op){
	s16 res;
	if(op=='+'){
		res=add(num1,num2);
	}
	else if(op=='-'){
		res=sub(num1,num2);
	}
	else if(op=='*'){
		res=mult(num1,num2);
	}
	else if(op=='/'){
		res=dev(num1,num2);
	}
	return res;

}

void fun_t2sem(s8 arr[],u8 size ,u8 num_of_op, u8 num_of_eq )
{
	size=6;
	if(num_of_eq==3)
	{
		final_res[0]=arr[0];
		final_res[1]=arr[1];
		final_res[2]=arr[2];
	}
	else if(num_of_eq==4)
	{
		if(num_of_op==1)
		{
			final_res[0]=arr[0];
			final_res[1]=arr[1];
			final_res[2]=arr[2]*10+arr[3];
		}
		else
		{
			final_res[0]=arr[0]*10+arr[1];
			final_res[1]=arr[2];
			final_res[2]=arr[3];

		}
	}
	else if(num_of_eq==5)
	{
		final_res[0]=arr[0]*10+arr[1];
		final_res[1]=arr[2];
		final_res[2]=arr[3]*arr[4];
	}
}












