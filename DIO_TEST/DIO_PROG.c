/*
 * DIO_PROG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
//#define setbit(x,y) x|=(1<<y)   //set bit (number y) to  1
#include "DIO_INTERFACE.h"
#include "DIO_REG.h"
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"


/*************DESCRIPTION************************/
/*
 *   DATE  :
 *   VERSION:
 *
 */


 /*
 *    DES :set pinX portX
 *   INPUTS:    Port number ,Pin number
 *   OUTPUTS:   void
 */

void DIO_Vsetpin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER)
{

	switch(copy_u8PORT)
	{
	case DIO_PORTA :setbit(PORTA,copy_u8PINNUMBER);
	break ;
	case DIO_PORTB :setbit(PORTB,copy_u8PINNUMBER);
    break ;
	case DIO_PORTC :setbit(PORTC,copy_u8PINNUMBER);
	break ;
	case DIO_PORTD :setbit(PORTD,copy_u8PINNUMBER);
    break ;}

}

/*
*    DES :Reset pinX portX
*   INPUTS:    Port number ,Pin number
*   OUTPUTS:   void
*/

void DIO_Vresetpin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER)
{

	switch(copy_u8PORT)
	{
	case DIO_PORTA :resetbit(PORTA,copy_u8PINNUMBER);
	break ;
	case DIO_PORTB :resetbit(PORTB,copy_u8PINNUMBER);
    break ;
	case DIO_PORTC :resetbit(PORTC,copy_u8PINNUMBER);
	break ;
	case DIO_PORTD :resetbit(PORTD,copy_u8PINNUMBER);
    break ;}

}

/*
*    DES :Toggle pinX portX
*   INPUTS:    Port number ,Pin number
*   OUTPUTS:   void
*/

void DIO_Vtogglepin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER)
{

	switch(copy_u8PORT)
	{
	case DIO_PORTA :togglebit(PORTA,copy_u8PINNUMBER);
	break ;
	case DIO_PORTB :togglebit(PORTB,copy_u8PINNUMBER);
    break ;
	case DIO_PORTC :togglebit(PORTC,copy_u8PINNUMBER);
	break ;
	case DIO_PORTD :togglebit(PORTD,copy_u8PINNUMBER);
    break ;}

}


/*
*    DES :set portX
*   INPUTS:    Port number
*   OUTPUTS:   void
*/

void DIO_Vsetport(u8 copy_u8PORT)
{

	switch(copy_u8PORT)
	{
	case DIO_PORTA :PORTA=0XFF;
	break ;
	case DIO_PORTB :PORTB=0XFF;
    break ;
	case DIO_PORTC :PORTC=0XFF;
	break ;
	case DIO_PORTD :PORTD=0XFF;
    break ;}

}

/*
*    DES :Reset portX
*   INPUTS:    Port number
*   OUTPUTS:   void
*/

void DIO_Vresetport(u8 copy_u8PORT)
{

	switch(copy_u8PORT)
	{
	case DIO_PORTA :PORTA=0X00;
	break ;
	case DIO_PORTB :PORTB=0X00;
    break ;
	case DIO_PORTC :PORTC=0X00;
	break ;
	case DIO_PORTD :PORTD=0X00;
    break ;}

}

/*
*    DES :set pinX Direction (in/out)
*   INPUTS:    Port number ,Pin number,pin statues
*   OUTPUTS:   void
*/

void DIO_Vsetpindirection(u8 copy_u8PORT ,u8 copy_u8PINNUMBER ,u8 copy_u8direction )
{
	{

		switch(copy_u8PORT)
		{
		case DIO_PORTA :
			switch(copy_u8direction)
			{
			case DIO_INPUT :resetbit(DDRA,copy_u8PINNUMBER);break;
			case DIO_OUTPUT :setbit(DDRA,copy_u8PINNUMBER);break;
			} break;
		case DIO_PORTB :
			switch(copy_u8direction)
			        {
			        case DIO_INPUT :resetbit(DDRB,copy_u8PINNUMBER);break;
					case DIO_OUTPUT :setbit(DDRB,copy_u8PINNUMBER);break;
					}break;

		case DIO_PORTC :
			switch(copy_u8direction)
			{
		           case DIO_INPUT :resetbit(DDRC,copy_u8PINNUMBER);break;
    			   case DIO_OUTPUT :setbit(DDRC,copy_u8PINNUMBER);break;
		    }break;

		case (DIO_PORTD) :
		switch(copy_u8direction)
		{
		       case DIO_INPUT :resetbit(DDRD,copy_u8PINNUMBER);break;
   			   case DIO_OUTPUT :setbit(DDRD,copy_u8PINNUMBER);break;
		}

	}
}}
/////////////////
/* Description	: Get the value of pin
 * Inputs		: Port Number, Pin Number
 * Outputs		: Pin Value
 */

/*
*    DES :get pinX portX value
*   INPUTS:    Port number ,Pin number
*   OUTPUTS:   value of pinX
*/

u8  DIO_getpin(u8 copy_u8PORT ,u8 copy_u8PINNUMBER)
	{
	u8 result ;

		switch(copy_u8PORT)
		{
		case DIO_PORTA :result= getbit(PINA,copy_u8PINNUMBER);
		break ;
		case DIO_PORTB :result= getbit(PINB,copy_u8PINNUMBER);
	    break ;
		case DIO_PORTC :result= getbit(PINC,copy_u8PINNUMBER);
		break ;
		case DIO_PORTD :result= getbit(PIND,copy_u8PINNUMBER);
	    break ;}
		return result ;

	}


void DIO_Vsetportvalue(u8 copy_u8PORT,u8 copy_u8value)
{
	switch(copy_u8PORT)
		{
		case DIO_PORTA :PORTA=copy_u8value;
		break ;
		case DIO_PORTB :PORTB=copy_u8value;
	    break ;
		case DIO_PORTC :PORTC=copy_u8value;
		break ;
		case DIO_PORTD :PORTD=copy_u8value;
	    break ;}



}


