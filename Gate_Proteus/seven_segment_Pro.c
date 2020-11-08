/*
 * seven_segment_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "seven_segment_interface.h"

/*
 * Descraption:
 * input:
 * output:
 */
void seven_seg_NumOutput(u8 copy_u8Port_num , u8 copy_u8NumOutput)
{
	if(copy_u8NumOutput==0)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vClearPin(copy_u8Port_num,4);
		DIO_vClearPin(copy_u8Port_num,5);
		DIO_vSetPin(copy_u8Port_num,6);

	}
	else if(copy_u8NumOutput==1)
	{
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vSetPin(copy_u8Port_num,0);
		DIO_vSetPin(copy_u8Port_num,3);
		DIO_vSetPin(copy_u8Port_num,4);
		DIO_vSetPin(copy_u8Port_num,5);
		DIO_vSetPin(copy_u8Port_num,6);

	}
	else if(copy_u8NumOutput==2)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vClearPin(copy_u8Port_num,4);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vSetPin(copy_u8Port_num,2);
		DIO_vSetPin(copy_u8Port_num,5);

	}
	else if(copy_u8NumOutput==3)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vSetPin(copy_u8Port_num,4);
		DIO_vSetPin(copy_u8Port_num,5);

	}
	else if(copy_u8NumOutput==4)
	{
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vClearPin(copy_u8Port_num,5);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vSetPin(copy_u8Port_num,0);
		DIO_vSetPin(copy_u8Port_num,3);
		DIO_vSetPin(copy_u8Port_num,4);

	}
	else if(copy_u8NumOutput==5)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vClearPin(copy_u8Port_num,5);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vSetPin(copy_u8Port_num,1);
		DIO_vSetPin(copy_u8Port_num,4);
	}
	else if(copy_u8NumOutput==6)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vClearPin(copy_u8Port_num,4);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vClearPin(copy_u8Port_num,5);
		DIO_vSetPin(copy_u8Port_num,1);

	}
	else if(copy_u8NumOutput==7)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vSetPin(copy_u8Port_num,3);
		DIO_vSetPin(copy_u8Port_num,4);
		DIO_vSetPin(copy_u8Port_num,5);
		DIO_vSetPin(copy_u8Port_num,6);

	}
	else if(copy_u8NumOutput==8)
	{
		DIO_vClearPort(copy_u8Port_num);

	}
	else if(copy_u8NumOutput==9)
	{
		DIO_vClearPin(copy_u8Port_num,0);
		DIO_vClearPin(copy_u8Port_num,1);
		DIO_vClearPin(copy_u8Port_num,2);
		DIO_vClearPin(copy_u8Port_num,3);
		DIO_vClearPin(copy_u8Port_num,5);
		DIO_vClearPin(copy_u8Port_num,6);
		DIO_vSetPin(copy_u8Port_num,4);
	}
}
