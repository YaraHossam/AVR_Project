/*
 * ADC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../_standard/datatypes.h"
#include "ADC_Register.h"

/*ADMUX*/
#define ADLAR 5
#define REFS0 6
#define REFS1 7
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4


/*ADCSRA*/
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 5

/* Globle_Enable */
#define SREG_I 7

/*SFIOR*/
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7

/*SingleEndedChannel*/
#define ADC_Channel0SE 0 /* single ended ADC0 */
#define ADC_Channel1SE 1 /* single ended ADC1 */
#define ADC_Channel2SE 2 /* single ended ADC2 */
#define ADC_Channel3SE 3 /* single ended ADC3 */
#define ADC_Channel4SE 4 /* single ended ADC4 */
#define ADC_Channel5SE 5 /* single ended ADC5 */
#define ADC_Channel6SE 6 /* single ended ADC6 */
#define ADC_Channel7SE 7 /* single ended ADC7 */

/*DiffChannel&Gain*/
#define ADC_DiADC00 8 /* +ADC0 -ADC0 Gain=10x */
#define ADC_DiADC10 9 /* +ADC1 -ADC0 Gain=10x */

/*AdcEnable*/
#define ADC_EnableADC 1  /* enable the ADC PINS */
#define ADC_DisableADC 0 /* disable the ADC PINS */

/*StartConversion*/
#define ADC_StrtConvADC 1 /* start conversion */
#define ADC_EndConv 0     /*  end conversion */

/*AutoTrigger*/
#define ADC_AutoTriggEn 1  /* enable auto trigger */
#define ADC_AutoTriggDis 0 /* disable auto trigger */

/*ADCflag*/
#define ADC_FlagClr 0 /* clear the ADC flag */

/*InterruptEnable*/
#define ADC_InterruptEn 1  /* enable interrupt baed conversion */
#define ADC_InterruptDis 0 /* disable interrupt baed conversion */

/*ADCprescalar*/
#define ADC_PrescalarTwo 0                   /* disvison factor 2 */
#define ADC_PrescalarFour 2                  /* disvison factor 4 */
#define ADC_PrescalarEight 3                 /* disvison factor 8 */
#define ADC_PrescalarSixteen 4               /* disvison factor 16 */
#define ADC_PrescalarThirtyTwo 5             /* disvison factor 32 */
#define ADC_PrescalarSixtyFour 6             /* disvison factor 64 */
#define ADC_PrescalarOneHundredTwentyEight 7 /* disvison factor 128 */

/*AutoTriggerSource*/
#define ADC_AutoTrigSourFreeRunningMode 0            /* Free Running mode */
#define ADC_AutoTrigSourAnalogComparator 1           /* Analog Comparator */
#define ADC_AutoTrigSourExtInterrReq0 2              /* External Interrupt Request 0 */
#define ADC_AutoTrigSourTimerCount0CompMat 3         /* Timer/Counter0 Compare Match */
#define ADC_AutoTrigSourTimerCount0Overflow 4        /* Timer/Counter0 Overflow */
#define ADC_AutoTrigsourTimerCountCompMatB 5         /* Timer/Counter Compare Match B */
#define ADC_AutoTrigSourTimerCount1Overflow 6        /* Timer/Counter1 Overflow */
#define ADC_AutoTrigSourTimerCounter1CaptureEvent 7  /* Timer/Counter1 Capture Event */

/*Vref*/
#define ADC_VrefAref 0     /* Aref 'internal vref turned off' */
#define ADC_VrefVcc 1      /* vcc with internal capacitor at Aref pin */
#define ADC_VrefReserved 2 /* reserved */
#define ADC_VrefInternal 3 /* Internal 2.56V Voltage Reference with external capacitor at AREF pin */

/*DataAdjustment*/
#define ADC_Ladj 1  /* Left Adjustment */
#define ADC_Radj 0  /* Right Adjustment */


typedef struct
{
	u8 ADC_Channel_Gain : 5 ;   /* 5 bits to decide the channel and gain */
	u8 ADC_Prescalar : 3 ;      /* 3 bits 2 control the ADC prescalar */
	u8 ADC_AutoTrigSource : 3 ; /* 3 bits to decide the Autotrigger source */
	u8 ADC_Vref : 2 ;           /* 2 bit to decide Vref */
	u8 ADC_DataAdj : 1 ;        /* 1 bit to decide leftADJ or rightADJ */
	u8 ADC_InterrEN : 1 ;       /* 1 bit to enable the intterrupt base */
	u8 ADC_Flag : 1 ;           /* 1 bit to control the ADC flag */
	u8 ADC_AutoTrig : 1 ;       /* 1 bit to enable the auto trigger */
	u8 ADC_StrtConv : 1 ;       /* 1 bit to start the conversion */
	u8 ADC_Enable : 1 ;         /* 1 bit to enable the ADC */


}ADC_tstrADC;

extern void ADC_vInitialization(ADC_tstrADC * ADC_PtrInput);
extern u8 ADC_u8Read(void);
extern void ADC_vChangeChanel(ADC_tstrADC * ADC_PtrInput);
extern void ADC_Disable(void);


#endif /* ADC_INTERFACE_H_ */
