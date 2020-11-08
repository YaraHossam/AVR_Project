/*
 * I2C_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../_standard/datatypes.h"

extern void I2C_initialize_MASTER(void);
extern void I2C_M_writeBYTE_S_sentBYTE(u8 Data);
extern u8 I2C_M_readBYTE_S_receiveBYTE(void);
extern void I2C_stop(void);
extern void I2C_initialize_SLAVE(u8 slaveAddress);
extern void I2C_listen(void);

#endif /* I2C_INTERFACE_H_ */
