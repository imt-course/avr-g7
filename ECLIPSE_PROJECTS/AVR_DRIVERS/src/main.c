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
#include "Keypad.h"

int main (void)
{
    Keypad_ButtonType buttonCounter;
    boolean printFlag[16] = {0};
    Keypad_Init();
    Lcd_Init(&Lcd_Configuration);
    Lcd_DisplayString("Hello");
    _delay_ms(500);
    Lcd_ClearDisplay();
    while (1)
    {
        for (buttonCounter=KEYPAD_B00; buttonCounter<=KEYPAD_B15; buttonCounter++)
        {
            if (KEYPAD_PRESSED == Keypad_GetButtonState(buttonCounter))
            {
                if (printFlag[buttonCounter] == FALSE)
                {
                    Lcd_DisplayNumber(buttonCounter);
                    printFlag[buttonCounter] = TRUE;
                }
                else 
                {
                    /* Do Nothing. */
                }
            }
            else
            {
                printFlag[buttonCounter] = FALSE;
            }
        }
    }
}
