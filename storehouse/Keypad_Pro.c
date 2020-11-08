/*
 * Keypad_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"

/*
 * Descraption:know read anhy push bottom ana daysa 3alah p el ana 7ata fe 2l KeypadArr
 * input:
 * output:retrun number from 0 to 15
 */

u8 Keypad_u8ReadKey(void)
{
	u8 local_au8KeypadArr[4][4]={{0,1,2,3},{4,5,6,7},{8,9,'A','B'},{'C','D','E','F'}};
	u8 local_u8Row;
	u8 local_u8Colum;
	u8 local_u8Read;
	u8 local_u8RetrunValue =100;

	for(local_u8Colum =0 ; local_u8Colum <4 ; local_u8Colum ++)
	{
		DIO_vSetPin(Colums_Port,0);
		DIO_vSetPin(Colums_Port,1);
		DIO_vSetPin(Colums_Port,2);
		DIO_vSetPin(Colums_Port,3);

		DIO_vClearPin(Colums_Port,local_u8Colum);

		for(local_u8Row =4 ; local_u8Row <8 ; local_u8Row ++)
		{
			local_u8Read=DIO_vGetPin(Rows_Port,local_u8Row);
			if(local_u8Read==0)
			{
				local_u8RetrunValue= local_au8KeypadArr[local_u8Row-4][local_u8Colum];
				while(DIO_vGetPin(Rows_Port,local_u8Row)==0)
				{

				}
			}
			else
			{
				//nothing
			}
		}

	}
	return local_u8RetrunValue;
}
