/*
 * SPI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


typedef struct
{
	u8 SPI_DataOrder : 1 ;
	u8 SPI_MorS : 1 ;
	u8 Clock_Polarity : 1 ;
	u8 Functionality : 1 ;
	u8 Clock_Phase : 1 ;
	u8 Clock_Rate_Select : 3 ;


}SPI_struct;

extern void SPI_vInitialize(SPI_struct * copy_struct);
extern u8 SPI_TxRx(u8);


#endif /* SPI_INTERFACE_H_ */
