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


#define F_CPU 8000000UL
#include <util/delay.h>

int main (void)
{
    Led_Init(LED_PIN);
    Switch_Init(SWITCH_PIN);
    while (1)
    {
        if(SWITCH_PRESSED == Switch_GetState(SWITCH_PIN))
        {
            Led_TurnOn(LED_PIN);
        }
        else
        {
            Led_TurnOff(LED_PIN);
        }
    }
    
    
}
