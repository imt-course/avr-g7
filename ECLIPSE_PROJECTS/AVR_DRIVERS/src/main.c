/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */


#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"
#include "Fcpu.h"
#include <util/delay.h>
#include "Dio.h"
#include "Switch.h"
#include "Ssd.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Gie.h"
#include "ExtInt.h"
#include "Adc.h"

u16 reading;

void Adc_Handler(u16 data)
{
    reading = data;
}

int main (void)
{
    Lcd_Init(&Lcd_Configuration);
    Adc_Init();
    Adc_EnableInterrupt();
    Adc_SetCallback(Adc_Handler);
    GIE_ENABLE();
    while (1)
    {
        Adc_StartConversion(ADC_CHANNEL_ADC0);
        Lcd_ClearDisplay();
        Lcd_DisplayNumber(((u32)reading*5000)/1024);
        _delay_ms(500);
    }
}
