/*
 * SPI_Proj.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */
#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>



void SPI_vInitialize(SPI_struct * copy_struct)
{
	//data order
	if(copy_struct->SPI_DataOrder==1)
	{
		DIO_vSetPin(SPCR,DORD);

	}
	else if(copy_struct->SPI_DataOrder==0)
	{
		DIO_vClearPin(SPCR,DORD);
	}

	//Master/Slave Select
	if(copy_struct->SPI_MorS==1)
	{
			DIO_vSetPin(SPCR,MSTR);

	}
	else if(copy_struct->SPI_MorS==0)
	{
			DIO_vClearPin(SPCR,MSTR);
	}

	//Clock Polarity
	if(copy_struct->Clock_Polarity==1)
	{
		DIO_vSetPin(SPCR,CPOL);
	}
	else if(copy_struct->Clock_Polarity==0)
	{
		DIO_vClearPin(SPCR,CPOL);
	}
	//Functionality
	if(copy_struct->Functionality==0)
	{
		DIO_vClearPin(SPCR,CPHA);
	}
	else if(copy_struct->Functionality==0)
	{
		DIO_vSetPin(SPCR,CPHA);
	}
	//Clock Rate
	if(copy_struct->Clock_Rate_Select==0b000)
	{
		DIO_vClearPin(SPCR)
	}

	//Enable SPI
	DIO_vSetPin(SPCR,SPE);


}

