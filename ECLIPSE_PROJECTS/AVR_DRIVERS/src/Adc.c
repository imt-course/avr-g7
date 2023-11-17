/*
 * Adc.c
 *
 *  Created on: Nov 17, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Registers.h"
#include "Macros.h"
#include "Interrupts.h"
#include "Adc.h"

void Adc_Init(void)
{
    /* Reference Selection Bits */
    /* AVCC with external capacitor at AREF pin */
    SET_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
    /* ADC Left Adjust Result Off */
    CLR_BIT(ADMUX, 5);
    /*  Analog Channel and Gain Selection Bits ADC0 */
    CLR_BIT(ADMUX,0);
    CLR_BIT(ADMUX,1);
    CLR_BIT(ADMUX,2);
    CLR_BIT(ADMUX,3);
    CLR_BIT(ADMUX,4);

    /* ADC Auto Trigger Enable Off */
    CLR_BIT(ADCSRA, 5);

    /* ADC Prescaler Select Bits 128 */
    SET_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);

    /* ADC Enable */
    SET_BIT(ADCSRA, 7);
}
void Adc_StartConversion(void)
{
    /* Wait until current conversion completes */
    while(GET_BIT(ADCSRA, 6) == 1);
    /* Start New Conversion */
    SET_BIT(ADCSRA, 6);
}

u16 Adc_GetResult(void)
{
    /* Wait until conversion completes */
    while (GET_BIT(ADCSRA, 4) == 0);
    /* Return Result */
    return (ADC_DATA & 0b1111111111);
    // return ((ADCL | (ADCH<<8)) & 0b1111111111);
}
