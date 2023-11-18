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
#include "Adc_Cfg.h"
#include "Adc.h"

void (*Callback_Adc) (u16 data) = NULL_PTR;

ISR(VECTOR_ADC)
{
    if (NULL_PTR != Callback_Adc)
    {
        Callback_Adc(ADC_DATA&0b1111111111);
    }
}

void Adc_Init(void)
{
    /* Reference Selection Bits */
#if (ADC_CFG_REF == ADC_REF_AREF)
    CLR_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
#elif (ADC_CFG_REF == ADC_REF_VCC)
    SET_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
#elif (ADC_CFG_REF == ADC_REF_INT_2_56V)
    SET_BIT(ADMUX, 6);
    SET_BIT(ADMUX, 7);
#else 
    #error ADC: Invalid Voltage Reference 
#endif

    /* ADC Left Adjust Result Off */
    CLR_BIT(ADMUX, 5);

    /* ADC Auto Trigger Enable */
#if (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_OFF)
    CLR_BIT(ADCSRA, 5);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_FREE_RUNNING)
    SET_BIT(ADCSRA, 5);
    CLR_BIT(SFIOR, 5);
    CLR_BIT(SFIOR, 6);
    CLR_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_ANAL_COMP)
    SET_BIT(ADCSRA, 5);
    SET_BIT(SFIOR, 5);
    CLR_BIT(SFIOR, 6);
    CLR_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_EXTINT0)
    SET_BIT(ADCSRA, 5);
    CLR_BIT(SFIOR, 5);
    SET_BIT(SFIOR, 6);
    CLR_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_TIM0_COMP)
    SET_BIT(ADCSRA, 5);
    SET_BIT(SFIOR, 5);
    SET_BIT(SFIOR, 6);
    CLR_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_TIM0_OVF)
    SET_BIT(ADCSRA, 5);
    CLR_BIT(SFIOR, 5);
    CLR_BIT(SFIOR, 6);
    SET_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_TIM1_COMPB)
    SET_BIT(ADCSRA, 5);
    SET_BIT(SFIOR, 5);
    CLR_BIT(SFIOR, 6);
    SET_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_TIM1_OVF)
    SET_BIT(ADCSRA, 5);
    CLR_BIT(SFIOR, 5);
    SET_BIT(SFIOR, 6);
    SET_BIT(SFIOR, 7);
#elif (ADC_CFG_AUTO_TRIGGER == ADC_AUTO_TRIGGER_TIM_CAP)
    SET_BIT(ADCSRA, 5);
    SET_BIT(SFIOR, 5);
    SET_BIT(SFIOR, 6);
    SET_BIT(SFIOR, 7);
#else
    #error ADC: Invalid Auto Trigger Source
#endif

    /* ADC Prescaler Select Bits */
#if (ADC_CFG_PRESCALER == 2)
    CLR_BIT(ADCSRA, 0);
    CLR_BIT(ADCSRA, 1);
    CLR_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 4)
    CLR_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    CLR_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 8)
    SET_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    CLR_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 16)
    CLR_BIT(ADCSRA, 0);
    CLR_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 32)
    SET_BIT(ADCSRA, 0);
    CLR_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 64)
    CLR_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
#elif (ADC_CFG_PRESCALER == 128)
    SET_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
#else 
    #error ADC: Invalid Prescaler
#endif

    /* ADC Enable */
    SET_BIT(ADCSRA, 7);
}
void Adc_StartConversion(Adc_ChannelType channel)
{
    /* Wait until current conversion completes */
    while(GET_BIT(ADCSRA, 6) == 1);
    if (channel <= 31)
    {
        /*  Analog Channel and Gain Selection Bits */
        ADMUX &= 0b11100000;
        ADMUX |= channel;
    }
    /* Start New Conversion */
    SET_BIT(ADCSRA, 6);
}

u16 Adc_GetResult(void)
{
    /* Wait until conversion completes */
    while (GET_BIT(ADCSRA, 4) == 0);
    /* Clear Flag */
    SET_BIT(ADCSRA, 4);
    /* Return Result */
    return (ADC_DATA & 0b1111111111);
    // return ((ADCL | (ADCH<<8)) & 0b1111111111);
}

void Adc_EnableInterrupt(void)
{
    SET_BIT(ADCSRA, 3);
}

void Adc_DisableInterrupt(void)
{
    CLR_BIT(ADCSRA, 3);
}

void Adc_SetCallback(void (*funcPtr) (u16 data))
{   
    Callback_Adc = funcPtr;
}