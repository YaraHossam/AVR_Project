/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
extern void ADC_Init(unsigned char channel);
extern unsigned char ADC_Read(unsigned char channel);

#endif /* ADC_H_ */
