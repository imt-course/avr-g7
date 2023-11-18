/*
 * Lm35.c
 *
 *  Created on: Nov 18, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Adc.h"
#include "Fcpu.h"
#include <util/delay.h>
#include "Lm35_Cfg.h"
#include "Lm35.h"

u8 Lm35_GetTemperature(u8 avgCount, u8 delayMs)
{
    u8 loopCounter;
    u32 resultsSum = 0;
    u8 result;
    for(loopCounter=0; loopCounter<avgCount; loopCounter++)
    {
        Adc_StartConversion(LM35_CFG_ADC_CHANNEL);
        result = Adc_GetResult();
        result = ((u32)result*500) / 1024;
        resultsSum += result;
        _delay_ms(delayMs);
    }
    result = resultsSum / avgCount;
    return result;
}
