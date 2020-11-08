/*
 * ADC_Register.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
#include "../_standard/datatypes.h"

#define ADMUX (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCH (*(volatile u8 *)0x25)
#define ADCL (*(volatile u8 *)0x24)
#define SFIOR (*(volatile u8 *)0x50)

#define SREG (*(volatile u8 *)0x5F)


#endif /* ADC_REGISTER_H_ */
