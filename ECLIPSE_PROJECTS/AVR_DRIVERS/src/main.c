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


int main (void)
{
    u16 data;
    Lcd_Init(&Lcd_Configuration);
    Adc_Init();
    Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_MODE_INPUT_FLOATING);
    while (1)
    {
        Adc_StartConversion(ADC_CHANNEL_ADC0);
        data = Adc_GetResult();
        Lcd_ClearDisplay();
        Lcd_DisplayNumber(((u32)data*5000)/1024);
        _delay_ms(500);
    }
}
