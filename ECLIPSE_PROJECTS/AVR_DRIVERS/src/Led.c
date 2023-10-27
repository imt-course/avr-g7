/*
 * Led.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Led.h"

void Led_Init(Dio_PortType port, Dio_PinType pin)
{
    Dio_SetPinMode(port, pin, DIO_MODE_OUTPUT);
}

void Led_TurnOn(Dio_PortType port, Dio_PinType pin)
{
    Dio_SetPinLevel(port, pin, DIO_HIGH);
}

void Led_TurnOff(Dio_PortType port, Dio_PinType pin)
{
    Dio_SetPinLevel(port, pin, DIO_LOW);
}
