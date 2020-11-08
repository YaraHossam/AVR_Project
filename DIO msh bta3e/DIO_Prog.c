
/************************* Description *******************/
/*
 * DIO_Prog.c
 *
 * Date:16/102017
 *
 * Version:1
 *
 * Author : karim adel
 */
//*************************************************************************
#include"../standard/datatypes.h"
#include"../standard/bitcalc.h"
#include"DIO_Int.h"
#include"DIO_Reg.h"

//*************************************************************************

/*
 * desc   :set a pin in a port
 * inptuts: port number , pin number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vSetPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber)
{
	switch (Copy_u8PORT)
	{
	case DIO_PORTA : setbit(PORTA , Copy_u8PinNumber) ;
	break;
	case DIO_PORTB : setbit(PORTB , Copy_u8PinNumber) ;
	break;
	case DIO_PORTC : setbit(PORTC , Copy_u8PinNumber) ;
	break;
	case DIO_PORTD : setbit(PORTD , Copy_u8PinNumber) ;
	break;
	}

}

//************************************************************************

/*
 * desc   : clear a pin in a port
 * inptuts: port number , pin number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vClrPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber)
{
	switch(Copy_u8PORT)
	{
	case DIO_PORTA : clrbit(PORTA , Copy_u8PinNumber) ;
	break;
	case DIO_PORTB : clrbit(PORTB , Copy_u8PinNumber) ;
	break;
	case DIO_PORTC : clrbit(PORTC , Copy_u8PinNumber) ;
	break;
	case DIO_PORTD : clrbit(PORTD , Copy_u8PinNumber) ;
	break;
	}
}

//*************************************************************************************

/*
 * desc   : toggle a pin in a port
 * inptuts: port number , pin number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vToggletPin(u8 Copy_u8PORT ,u8 Copy_u8PinNumber)
{
	switch(Copy_u8PORT)
	{
	case DIO_PORTA : togglebit(PORTA , Copy_u8PinNumber) ;
	break;
	case DIO_PORTB : togglebit(PORTB , Copy_u8PinNumber) ;
	break;
	case DIO_PORTC : togglebit(PORTC , Copy_u8PinNumber) ;
	break;
	case DIO_PORTD : togglebit(PORTD , Copy_u8PinNumber) ;
	break;
	}


}

//***********************************************************************************

/*
 * desc   : SET a PORT
 * inptuts: port number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vSetPort(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT)
	{
	case DIO_PORTA : PORTA=0xff ;
	break;
	case DIO_PORTB : PORTB=0xff ;
	break;
	case DIO_PORTC : PORTC=0xff ;
	break;
	case DIO_PORTD : PORTD=0xff ;
	break;
	}
}

//*******************************************************************************

/*
 * desc   : clearing a PORT
 * inptuts: port number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vClrPort(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT)
	{
	case DIO_PORTA : PORTA=0 ;
	break;
	case DIO_PORTB : PORTB=0 ;
	break;
	case DIO_PORTC : PORTC=0 ;
	break;
	case DIO_PORTD : PORTD=0 ;
	break;
	}


}

//*************************************************************************************

/*
 * desc   : do the direction of the DDR if its output or input
 * inptuts: port number , pin number , direction
 * output : void
 */

/*
 * 0 -> DDRA
 * 1 -> DDRB
 * 2 -> DDRC
 * 3 -> DDRD
 */
void DIO_vPin_Direction(u8 Copy_u8PORT ,u8 Copy_u8PinNumber, u8 Copy_u8PortDirection)
{
	if(Copy_u8PortDirection == DIO_Input) // check if the direction is input
	{
	switch(Copy_u8PORT)
	{
	case DIO_DDRA : setbit(DDRA , Copy_u8PinNumber) ;
	break;
	case DIO_DDRB : setbit(DDRB , Copy_u8PinNumber) ;
	break;
	case DIO_DDRC : setbit(DDRC , Copy_u8PinNumber) ;
	break;
	case DIO_DDRD : setbit(DDRD , Copy_u8PinNumber) ;
	break;
	}
	}

	else if(Copy_u8PortDirection == DIO_Output) // check if the direction is output
	{
	switch(Copy_u8PORT)
	{
	case DIO_DDRA : clrbit(DDRA , Copy_u8PinNumber) ;
	break;
	case DIO_DDRB : clrbit(DDRB , Copy_u8PinNumber) ;
	break;
	case DIO_DDRC : clrbit(DDRC , Copy_u8PinNumber) ;
	break;
	case DIO_DDRD : clrbit(DDRD , Copy_u8PinNumber) ;
	break;
	}
	}

	else{}
}

//******************************************************************************

/*
 * desc   : do the direction of the DDR if it is input or output
 * inptuts: port number ,direction
 * output : void
 */

/*
 * 0 -> DDRA
 * 1 -> DDRB
 * 2 -> DDRC
 * 3 -> DDRD
 */
void DIO_vPort_Direction(u8 Copy_u8PORT , u8 Copy_u8PortDirection)
{
	if(Copy_u8PortDirection == DIO_Input) // check if the direction is input
	{
	switch(Copy_u8PORT)
	{
	case DIO_DDRA : DDRA=0 ;
	break;
	case DIO_DDRB : DDRB=0 ;
	break;
	case DIO_DDRC : DDRC=0 ;
	break;
	case DIO_DDRD : DDRD=0 ;
	break;
	}
	}

	if(Copy_u8PortDirection == DIO_Output) // check if the direction is output
	{
		switch(Copy_u8PORT)
		{
		case DIO_DDRA : DDRA=0xff ;
		break;
		case DIO_DDRB : DDRB=0xff ;
		break;
		case DIO_DDRC : DDRC=0xff ;
		break;
		case DIO_DDRD : DDRD=0xff ;
		break;
		}
	}

}

//*****************************************************************************

/*
 * desc   : check the value of a pin if its high or low
 * inptuts: PIN number , pin number
 * output : high  , low
 */

/*
 * 0 -> PINA
 * 1 -> PINB
 * 2 -> PINC
 * 3 -> PIND
 */
u8 DIO_vGetPin(u8 Copy_u8PIN , u8 Copy_u8PinNumber)
{
	u8 temp=0 ;
	switch(Copy_u8PIN)
	{
	case DIO_PINA :
	{
	    temp = getbit(PINA , Copy_u8PinNumber) ;
	     break;
	}
	case DIO_PINB :
	{
	    temp = getbit(PINB , Copy_u8PinNumber) ;
	     break;
	}
	case DIO_PINC :
	{
	    temp = getbit(PINC , Copy_u8PinNumber) ;
	     break;
	}

	case DIO_PIND :
	{
	    temp = getbit(PINC , Copy_u8PinNumber) ;
	     break;
	}

	}

    return temp;
}


//**********************************************************************************************

/*
 * desc   : toggle all pins in a port
 * inptuts: port number
 * output : void
 */

/*
 * 0 -> PORTA
 * 1 -> PORTB
 * 2 -> PORTC
 * 3-> PORTD
 */
void DIO_vToggletPort(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT)
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
