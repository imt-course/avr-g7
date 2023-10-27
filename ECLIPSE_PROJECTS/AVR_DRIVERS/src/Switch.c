/*
 * Switch.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Switch.h"

void Switch_Init(Dio_PortType port, Dio_PinType pin)
{
    Dio_SetPinMode(port, pin, DIO_MODE_INPUT_PULLUP);
}

Switch_StateType Switch_GetState(Dio_PortType port, Dio_PinType pin)
{
    Switch_StateType state;
    if (DIO_LOW == Dio_ReadPinLevel(port, pin))
    {
        state = SWITCH_PRESSED;
    }
    else
    {
        state = SWITCH_NOT_PRESSED;
    }
    return state;
}
