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

#define LED_PIN     DIO_PORTA,DIO_PIN0

void SwitchHandler (void)
{
    if (Dio_ReadPinLevel(EXTINT_PIN_INT0) == DIO_LOW)
    {
        Dio_SetPinLevel(LED_PIN, DIO_HIGH);
    }
    else
    {
        Dio_SetPinLevel(LED_PIN, DIO_LOW);
    }
}

int main (void)
{
    Dio_SetPinMode(EXTINT_PIN_INT0, DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(LED_PIN, DIO_MODE_OUTPUT);
    ExtInt_SetSenseEdge(EXTINT_INT0, EXTINT_EDGE_ON_CHANGE);
    ExtInt_EnableInterrupt(EXTINT_INT0);
    ExtInt_SetCallback(EXTINT_INT0, SwitchHandler);
    GIE_ENABLE();
    if (Dio_ReadPinLevel(EXTINT_PIN_INT0) == DIO_LOW)
    {
        Dio_SetPinLevel(LED_PIN, DIO_HIGH);
    }
    while (1)
    {
    }
}
