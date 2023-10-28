/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */


#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"
#include "Dio.h"
#include "Led.h"
#include "Switch.h"
#include "Ssd.h"
#include "Lcd.h"


#define F_CPU 8000000UL
#include <util/delay.h>

int main (void)
{
    Lcd_Init();
    while (1)
    {
        Lcd_SendData('A');
        Lcd_SendData('h');
        Lcd_SendData('m');
        Lcd_SendData('e');
        Lcd_SendData('d');
        _delay_ms(1000);
        Lcd_SendCommand(0b00000001);
        _delay_ms(1000);
    }
    
}
