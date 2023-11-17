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
    while (1)
    {
        Adc_StartConversion();
        data = Adc_GetResult();
        Lcd_ClearDisplay();
        Lcd_DisplayNumber(data);
        _delay_ms(500);
    }
}
