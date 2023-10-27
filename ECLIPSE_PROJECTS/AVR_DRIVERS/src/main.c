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


#define F_CPU 8000000UL
#include <util/delay.h>

int main (void)
{
    u8 number = 0;
    boolean printFlag = FALSE;
    Ssd_Init();
    Switch_Init(SWITCH_PIN);
    Ssd_Clear();
    while (1)
    {
        if (SWITCH_PRESSED == Switch_GetState(SWITCH_PIN))
        {
            if (FALSE == printFlag)
            {
                Ssd_DisplayNumber(number);
                number++;
                number = (number==10)? 0 : number;
                printFlag = TRUE;
            }
        }
        else 
        {
            printFlag = FALSE;
        }
    }
    

}
