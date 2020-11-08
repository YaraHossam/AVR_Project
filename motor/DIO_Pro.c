/*
 * DIO_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

/*
 *
 *Date :
 *version:
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "DIO_Registers.h"

/*
 * Description: set 1 in pinNumber in PortNumber
 * Input: Port number , pin number
 * Output:
 * 1
 */
void DIO_vSetPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		setbit(PORTA,Copy_u8PinNumber);
		break;
	case  DIO_PORTB:
			setbit(PORTB,Copy_u8PinNumber);
			break;
	case  DIO_PORTC:
				setbit(PORTC,Copy_u8PinNumber);
				break;
	case  DIO_PORTD:
				setbit(PORTD,Copy_u8PinNumber);
				break;
	}
}
/*
 * Description: set 0 in pinNumber in portNumber
 * Input: Port number , pin number
 * Output:
 * 2
 */
void DIO_vClearPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		clearbit(PORTA,Copy_u8PinNumber);
		break;
	case  DIO_PORTB:
		clearbit(PORTB,Copy_u8PinNumber);
			break;
	case  DIO_PORTC:
		clearbit(PORTC,Copy_u8PinNumber);
				break;
	case  DIO_PORTD:
		clearbit(PORTD,Copy_u8PinNumber);
				break;
	}
}

/*
 * Description: toggle pin if 1 set 0 ,else if 0 set 1
 * Input: Port number , pin number
 * Output:
 * 3
 */
void DIO_vTogglePin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		togglebit(PORTA,Copy_u8PinNumber);
		break;
	case  DIO_PORTB:
		togglebit(PORTB,Copy_u8PinNumber);
			break;
	case  DIO_PORTC:
		togglebit(PORTC,Copy_u8PinNumber);
				break;
	case  DIO_PORTD:
		togglebit(PORTD,Copy_u8PinNumber);
				break;
	}
}
/*
 * Description: i will use it when i want to know number of pin
 * Input: Port number , pin number
 * Output:return number of pin whether 0 or 1
 * 4
 */
u8 DIO_vGetPin(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber)
{
	u8 ret;
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		ret= getbit(PINA,Copy_u8PinNumber);

		break;
	case  DIO_PORTB:
		ret= getbit(PINB,Copy_u8PinNumber);
			break;
	case  DIO_PORTC:
		ret= getbit(PINC,Copy_u8PinNumber);
				break;
	case  DIO_PORTD:
		ret= getbit(PIND,Copy_u8PinNumber);
				break;
	}
	return ret;
}
/*
 * Description: set 1 in all pins in special port
 * Input: Port number
 * Output:
 * 5
 */
void DIO_vSetPort(u8 Copy_u8PORTNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		PORTA=0b11111111;
		break;
	case  DIO_PORTB:
		PORTB=0b11111111;
		break;
	case  DIO_PORTC:
		PORTC=0b11111111;
		break;
	case  DIO_PORTD:
		PORTD=0b11111111;
		break;
	}
}
/*
 * Description:set 0 in all pins in special port
 * Input: Port number
 * Output:
 * 6
 */
void DIO_vClearPort(u8 Copy_u8PORTNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case  DIO_PORTA:
		PORTA=0b00000000;
		break;
	case  DIO_PORTB:
		PORTB=0b00000000;
		break;
	case  DIO_PORTC:
		PORTC=0b00000000;
		break;
	case  DIO_PORTD:
		PORTD=0b00000000;
		break;
	}
}
/*
 * Description:Determination the pin if Input or Output
 * Input: Port number , pin number , Direc
 * Output:
 * 7
 */
void DIO_vSetPinDirec(u8 Copy_u8PORTNumber , u8 Copy_u8PinNumber,u8 Copy_u8Direc)
{
	switch(Copy_u8PORTNumber)
		{
		case  DIO_PORTA:
			switch(Copy_u8Direc)
			{
			case DIO_INPUT:
				clearbit(DDRA,Copy_u8PinNumber);
				break;
			case DIO_OUTPUT:
				setbit(DDRA,Copy_u8PinNumber);
				break;
			}
			break;
		case  DIO_PORTB:
			switch(Copy_u8Direc)
						{
						case DIO_INPUT:
							clearbit(DDRB,Copy_u8PinNumber);
							break;
						case DIO_OUTPUT:
							setbit(DDRB,Copy_u8PinNumber);
							break;
						}
			break;
		case  DIO_PORTC:
			switch(Copy_u8Direc)
						{
						case DIO_INPUT:
							clearbit(DDRC,Copy_u8PinNumber);
							break;
						case DIO_OUTPUT:
							setbit(DDRC,Copy_u8PinNumber);
							break;
						}
			break;
		case  DIO_PORTD:
			switch(Copy_u8Direc)
						{
						case DIO_INPUT:
							clearbit(DDRD,Copy_u8PinNumber);
							break;
						case DIO_OUTPUT:
							setbit(DDRD,Copy_u8PinNumber);
							break;
						}
			break;
		}
}
/*
 * Description:switch all pins 0-->1 & 1-->0
 * Input: Port number
 * Output:
 * 8
 */
void DIO_vToggletPort(u8 Copy_u8PORTNumber)
{
	switch(Copy_u8PORTNumber)
	{
	case DIO_PORTA :
	{
		for(int Pin_Counter=0 ; Pin_Counter < 8 ; Pin_Counter++) // looping on ever pin in the port
		{
			togglebit(PORTA , Pin_Counter) ;
		}
		break;
	}
	case DIO_PORTB :
	{
		for(int Pin_Counter=0 ; Pin_Counter < 8 ; Pin_Counter++) // looping on ever pin in the port
		{
			togglebit(PORTB , Pin_Counter) ;
		}
		break;
	}
	case DIO_PORTC :
	{
		for(int Pin_Counter=0 ; Pin_Counter < 8 ; Pin_Counter++) // looping on ever pin in the port
		{
			togglebit(PORTC , Pin_Counter) ;
		}
		break;
	}
	case DIO_PORTD :
	{
		for(int Pin_Counter=0 ; Pin_Counter < 8 ; Pin_Counter++) // looping on ever pin in the port
		{
			togglebit(PORTD , Pin_Counter) ;
		}
		break;
	}

	}


}

/*
 * Description: set el command in all part
 * Input: Port number , command
 * Output:
 * 9
 */
void DIO_vSetPortvalue(u8 Copy_u8PORTNumber,u8 Copy_u8value)
{
	switch(Copy_u8PORTNumber)
		{
		case DIO_PORTA:
			PORTA=Copy_u8value;
			break;
		case DIO_PORTB:
			PORTB=Copy_u8value;
			break;
		case DIO_PORTC:
			PORTC=Copy_u8value;
			break;
		case DIO_PORTD:
			PORTD=Copy_u8value;
			break;

		}
}
