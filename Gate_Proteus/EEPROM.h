/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "../_standard/datatypes.h"

extern u8 EEPROM_read(u16 Address);
extern void EEPROM_write( u16 Address, u8 Data);



#endif /* EEPROM_H_ */
