/*
 * RTOS_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

#include "../_standard/datatypes.h"


#define NULL 0

typedef struct{
	void (*Task_Function) (void);
	u8 Perdicity;
	u8 Delay;
}RTOS_tstrTask;

extern void RTOS_intialize(void);
extern void RTOS_vScheduler(void);

#endif /* RTOS_INTERFACE_H_ */
