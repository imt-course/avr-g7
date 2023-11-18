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
#include "Lm35.h"
#include "Ldr.h"


int main (void)
{
    u8 temperature;
    u16 light;
    Lcd_Init(&Lcd_Configuration);
    Adc_Init();
    while (1)
    {
        temperature = Lm35_GetTemperature(10, 2);
        light = Ldr_GetIntensity(10, 2);
        Lcd_ClearDisplay();
        Lcd_DisplayString("Light = ");
        Lcd_DisplayNumber(light);
        Lcd_SetCursorPosition(1,0);
        Lcd_DisplayString("Temp = ");
        Lcd_DisplayNumber(temperature);
        _delay_ms(500);
    }
}
