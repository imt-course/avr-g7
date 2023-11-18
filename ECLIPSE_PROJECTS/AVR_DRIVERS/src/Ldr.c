/*
 * Ldr.c
 *
 *  Created on: Nov 18, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Adc.h"
#include "Fcpu.h"
#include <util/delay.h>
#include "Ldr_Cfg.h"
#include "Ldr.h"

u16 Ldr_GetIntensity(u8 avgCount, u8 delayMs)
{
    u8 loopCounter;
    u32 resultsSum = 0;
    u16 result;
    for(loopCounter=0; loopCounter<avgCount; loopCounter++)
    {
        Adc_StartConversion(LDR_CFG_ADC_CHANNEL);
        result = Adc_GetResult();
        resultsSum += result;
        _delay_ms(delayMs);
    }
    result = resultsSum / avgCount;
    return result;
}
