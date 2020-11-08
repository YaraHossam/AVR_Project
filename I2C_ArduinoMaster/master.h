/*
 * master.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef MASTER_H_
#define MASTER_H_

extern void i2c_write(unsigned char data);
extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_init(void);

#endif /* MASTER_H_ */
