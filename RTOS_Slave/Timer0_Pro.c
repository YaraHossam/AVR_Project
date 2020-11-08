/*
 * Timer0_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"

static void (*ptr_fun) (void);

/********************************************************/
/*Description  : Initialize Timer0                      */
/*Input        : None                                   */
/*Output       : None                                   */
/*InputOut     : None                                   */
/********************************************************/
void Timer0_initialize_Comp_mode(void)
{
	// 1ms
	//intialize

		setbit(TCCR0 , 3);
		clearbit(TCCR0 , 6);


		OCR0=50;
		/* enable CMf interrupt  */
		setbit(TIMSK,1);

		/* enable global */
		setbit(SREG  , SREG_I);



		/*prescaler 1024 */
		setbit(TCCR0 , 2);
		clearbit(TCCR0 , 1);
		setbit(TCCR0 , 0);


}

ISR(TIMER0_COMP_vect)
{
	//DIO_vSetPin(DIO_PORTA , 0);
	u8 static local_count = 0 ;
	if(local_count == 2)
	{
		ptr_fun();
		local_count++;
	}
	else
	{
		local_count++;
	}

}

/********************************************************/
/*Description  : set call back                     */
/*Input        : pointer to function                                  */
/*Output       : None                                   */
/*InputOut     : None                                   */
/********************************************************/
void TIMER0_vSetCallback(void (*INP_ptr_fun) (void))
{
	ptr_fun=INP_ptr_fun;

}
