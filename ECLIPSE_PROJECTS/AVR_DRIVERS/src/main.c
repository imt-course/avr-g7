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
#include "Led.h"
#include "Switch.h"
#include "Ssd.h"
#include "Lcd.h"
 



int main (void)
{
    Lcd_Init(&Lcd_Configuration);
    Lcd_DisplayString("Hassan");

    //u8 counter = 0;
    //Lcd_Init(&Lcd_Configuration);
    //Lcd_DisplayString("My name is Ahmed Hassan");
    //while (1)
    //{
    //    _delay_ms(500);
    //    Lcd_ShiftDisplayLeft(1);
    //    counter++;
    //    if (counter >= 8)
    //    {
    //        counter = 0;
    //        Lcd_ReturnHome();
    //    }
    //}
}
