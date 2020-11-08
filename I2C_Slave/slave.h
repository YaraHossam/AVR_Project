/*
 * slave.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef SLAVE_H_
#define SLAVE_H_


extern void i2c_initSlave(unsigned char slaveAddress);
extern unsigned char i2c_receive(unsigned char islast);
extern void i2c_listen();

#endif /* SLAVE_H_ */
