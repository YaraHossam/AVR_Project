/*
 * ADC_Pro.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#include "../_standard/datatypes.h"
#include "../_standard/calcbit.h"
#include "ADC_Register.h"
#include "ADC_interface.h"

void ADC_vInitialization(ADC_tstrADC * Copy_PtrInput)
{
	/****************** Vref CONFIGURATION ********************/
	if( (Copy_PtrInput->ADC_Vref) == ADC_VrefVcc)                 /* check if the user wanted AVCC with external capacitor at AREF pin */
	{
		clearbit(ADMUX,REFS1);
		setbit(ADMUX,REFS0);
	}
	else if ((Copy_PtrInput->ADC_Vref) == ADC_VrefAref)           /* check if the user wanted AREF, Internal Vref turned off */
	{
		clearbit(ADMUX,REFS1);
		clearbit(ADMUX,REFS0);
	}
	else if ((Copy_PtrInput->ADC_Vref) == ADC_VrefReserved)        /* check if the user wanted it reserved */
	{
		setbit(ADMUX,REFS1);
		clearbit(ADMUX,REFS0);
	}
	else if ((Copy_PtrInput->ADC_Vref) == ADC_VrefInternal)        /* check if the user wanted Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
	{
		setbit(ADMUX,REFS1);
		setbit(ADMUX,REFS0);
	}
	else
	{
		/* DO NTH */
	}

	/************** CHANNEL AND GAIN CONFIG. ***********************/
	if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel0SE)      /* check if the user choosed channel 0 */
	{
		clearbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel1SE) /* check if the user choosed channel 1 */
	{
		setbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel2SE) /* check if the user choosed channel 2 */
	{
		clearbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel3SE) /* check if the user choosed channel 3 */
	{
		setbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel4SE) /* check if the user choosed channel 4 */
	{
		clearbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel5SE) /* check if the user choosed channel 5 */
	{
		setbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel6SE) /* check if the user choosed channel 6 */
	{
		clearbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else if( (Copy_PtrInput->ADC_Channel_Gain) == ADC_Channel7SE) /* check if the user choosed channel 7 */
	{
		setbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
	}
	else
	{
		/*  do NTH */
	}

	/************* DATA ADJUSTMENT *****************/
	if((Copy_PtrInput->ADC_DataAdj) == ADC_Ladj)         /* check if the user choosed Left-ADJUSTMENT */
	{
		setbit(ADMUX,ADLAR);
	}
	else if((Copy_PtrInput->ADC_DataAdj) == ADC_Radj)   /* check if the user choosed Right-ADJUSTMENT */
	{
		clearbit(ADMUX,ADLAR);
	}
	else
	{
		/* DO NTH */
	}

	/********** PRESCALAR **************/
	if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarTwo)                           /*check if the user entered prescalar /2 */
	{
		clearbit(ADCSRA,ADPS0);
		clearbit(ADCSRA,ADPS1);
		clearbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarFour)                    /* check if the user entered prescalar /4 */
	{
		clearbit(ADCSRA,ADPS0);
		setbit(ADCSRA,ADPS1);
		clearbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarEight)                  /* check if the user entered prescalar /8 */
	{
		setbit(ADCSRA,ADPS0);
		setbit(ADCSRA,ADPS1);
		clearbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarSixteen)                /* check if the user entered prescalar /16 */
	{
		clearbit(ADCSRA,ADPS0);
		clearbit(ADCSRA,ADPS1);
		setbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarThirtyTwo)              /* check if the user entered prescalar /32 */
	{
		setbit(ADCSRA,ADPS0);
		clearbit(ADCSRA,ADPS1);
		setbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarSixtyFour)             /* check if the user entered prescalar /64 */
	{
		clearbit(ADCSRA,ADPS0);
		setbit(ADCSRA,ADPS1);
		setbit(ADCSRA,ADPS2);
	}
	else if((Copy_PtrInput->ADC_Prescalar) == ADC_PrescalarOneHundredTwentyEight) /* check if the user entered prescalar /128 */
	{
		setbit(ADCSRA,ADPS0);
		setbit(ADCSRA,ADPS1);
		setbit(ADCSRA,ADPS2);
	}
	else
	{
		/* DO NTH */
	}

	/*************** Auto-Trigger Source ***********/
	if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourFreeRunningMode)       /* check if the user wanted the Trigger-Source Free Running mode */
	{
		clearbit(SFIOR,ADTS0);
		clearbit(SFIOR,ADTS1);
		clearbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourAnalogComparator) /* check if the user wanted the Trigger-Source Analog Comparator */
	{
		setbit(SFIOR,ADTS0);
		clearbit(SFIOR,ADTS1);
		clearbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourExtInterrReq0) /* check if the user wanted the Trigger-Source External Interrupt Request 0 */
	{
		clearbit(SFIOR,ADTS0);
		setbit(SFIOR,ADTS1);
		clearbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourTimerCount0CompMat) /* check if the user wanted the Trigger-Source Timer/Counter0 Compare Match */
	{
		setbit(SFIOR,ADTS0);
		setbit(SFIOR,ADTS1);
		clearbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourTimerCount0Overflow) /* check if the user wanted the Trigger-Source Timer/Counter0 Overflow */
	{
		clearbit(SFIOR,ADTS0);
		clearbit(SFIOR,ADTS1);
		setbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigsourTimerCountCompMatB) /* check if the user wanted the Trigger-Source Timer/Counter Compare Match B */
	{
		setbit(SFIOR,ADTS0);
		clearbit(SFIOR,ADTS1);
		setbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourTimerCount1Overflow) /* check if the user wanted the Trigger-Source Timer/Counter1 Overflow*/
	{
		clearbit(SFIOR,ADTS0);
		setbit(SFIOR,ADTS1);
		setbit(SFIOR,ADTS2);
	}
	else if((Copy_PtrInput->ADC_AutoTrigSource) == ADC_AutoTrigSourTimerCounter1CaptureEvent) /* check if the user wanted the Trigger-Source Timer/Counter1 Capture Event*/
	{
		setbit(SFIOR,ADTS0);
		setbit(SFIOR,ADTS1);
		setbit(SFIOR,ADTS2);
	}
	else
	{
		/* DO NTH */
	}

    /*************** Auto-Trigger **************/
	if((Copy_PtrInput->ADC_AutoTrig) == ADC_AutoTriggEn)  /* check if the user wanted to enable the auto-trigger */
	{
		setbit(ADCSRA,ADATE);
	}
	else if((Copy_PtrInput->ADC_AutoTrig) == ADC_AutoTriggDis) /* check if the user wanted to disable the auto-trigger */
	{
		clearbit(ADCSRA,ADATE);
	}
	else
	{
		/* DO NTH */
	}

	/******************** Interrupt-Enable *****************/
	if((Copy_PtrInput->ADC_InterrEN) == ADC_InterruptEn)  /* check if the user wanted to enable the ADC interrupt */
	{

		setbit(SREG,SREG_I);  /*Global Interrupt Enable*/

		setbit(ADCSRA,ADIE);

	}
	else if((Copy_PtrInput->ADC_InterrEN) == ADC_InterruptDis) /* check if the user wanted to disable the ADC interrupt */
	{

		clearbit(ADCSRA,ADIE);

	}
	else
	{
		/* DO NTH */
	}

	/************** ADC-ENABLE ***************/

		setbit(ADCSRA,ADEN); /* enable the ADC */


}

/*Read */
u8 ADC_u8Read(void)
{
	u8 Local_Read;

	/* Start Conversion */
	setbit(ADCSRA,ADSC);

	/* Wait until interrupt flag is set */
	while(!getbit(ADCSRA,ADIF));

	/* Put the ADCH in the local variable */
	Local_Read = ADCH ;

	/* Clear Interrupt Flag to Enable Reading Again*/
	setbit(ADCSRA,ADIF);

	return Local_Read;
}
void ADC_ChangeChannel(u8 Copy_ChannelNumber)
{
	/* Disable the ADC */
	clearbit(ADCSRA,ADEN);

	/* Enable the ADC */
	setbit(ADCSRA,ADEN);

	/* Switch to see which channel the user wanted */
	switch(Copy_ChannelNumber)
	{
	case ADC_Channel0SE :
		clearbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel1SE :
		setbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel2SE :
		clearbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel3SE :
		setbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		clearbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel4SE :
		clearbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel5SE :
		setbit(ADMUX,MUX0);
		clearbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel6SE :
		clearbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	case ADC_Channel7SE :
		setbit(ADMUX,MUX0);
		setbit(ADMUX,MUX1);
		setbit(ADMUX,MUX2);
		clearbit(ADMUX,MUX3);
		clearbit(ADMUX,MUX4);
		break;
	}



}
