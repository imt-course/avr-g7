/*
 * Dio.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Registers.h"
#include "Macros.h"
#include "Dio.h"

void Dio_SetPinMode(Dio_PortType port, Dio_PinType pin, Dio_ModeType mode)
{
    switch (port)
    {
    case DIO_PORTA:
        if (DIO_MODE_INPUT_FLOATING == mode)
        {
            CLR_BIT(DDRA, pin);
            CLR_BIT(PORTA, pin);
        }
        else if (DIO_MODE_INPUT_PULLUP == mode)
        {
            CLR_BIT(DDRA, pin);
            SET_BIT(PORTA, pin);
        }
        else if (DIO_MODE_OUTPUT == mode)
        {
            SET_BIT(DDRA, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTB:
        if (DIO_MODE_INPUT_FLOATING == mode)
        {
            CLR_BIT(DDRB, pin);
            CLR_BIT(PORTB, pin);
        }
        else if (DIO_MODE_INPUT_PULLUP == mode)
        {
            CLR_BIT(DDRB, pin);
            SET_BIT(PORTB, pin);
        }
        else if (DIO_MODE_OUTPUT == mode)
        {
            SET_BIT(DDRB, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTC:
        if (DIO_MODE_INPUT_FLOATING == mode)
        {
            CLR_BIT(DDRC, pin);
            CLR_BIT(PORTC, pin);
        }
        else if (DIO_MODE_INPUT_PULLUP == mode)
        {
            CLR_BIT(DDRC, pin);
            SET_BIT(PORTC, pin);
        }
        else if (DIO_MODE_OUTPUT == mode)
        {
            SET_BIT(DDRC, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTD:
        if (DIO_MODE_INPUT_FLOATING == mode)
        {
            CLR_BIT(DDRD, pin);
            CLR_BIT(PORTD, pin);
        }
        else if (DIO_MODE_INPUT_PULLUP == mode)
        {
            CLR_BIT(DDRD, pin);
            SET_BIT(PORTD, pin);
        }
        else if (DIO_MODE_OUTPUT == mode)
        {
            SET_BIT(DDRD, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    default:
        break;
    }
}

void Dio_SetPinLevel(Dio_PortType port, Dio_PinType pin, Dio_LevelType level)
{
    switch (port)
    {
    case DIO_PORTA:
        if (DIO_HIGH == level)
        {
            SET_BIT(PORTA, pin);
        }
        else if (DIO_LOW == level)
        {
            CLR_BIT(PORTA, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTB:
        if (DIO_HIGH == level)
        {
            SET_BIT(PORTB, pin);
        }
        else if (DIO_LOW == level)
        {
            CLR_BIT(PORTB, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTC:
        if (DIO_HIGH == level)
        {
            SET_BIT(PORTC, pin);
        }
        else if (DIO_LOW == level)
        {
            CLR_BIT(PORTC, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    case DIO_PORTD:
        if (DIO_HIGH == level)
        {
            SET_BIT(PORTD, pin);
        }
        else if (DIO_LOW == level)
        {
            CLR_BIT(PORTD, pin);
        }
        else
        {
            /* Do Nothing. */
        }
        break;
    default:
        break;
    }
}

Dio_LevelType Dio_FlipPinLevel(Dio_PortType port, Dio_PinType pin)
{
    Dio_LevelType level = DIO_LOW;
    switch (port)
    {
    case DIO_PORTA:
        TOG_BIT(PORTA, pin);
        if (GET_BIT(PINA, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTB:
        TOG_BIT(PORTB, pin);
        if (GET_BIT(PINB, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTC:
        TOG_BIT(PORTC, pin);
        if (GET_BIT(PINC, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTD:
        TOG_BIT(PORTD, pin);
        if (GET_BIT(PIND, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    default:
        break;
    }
    return level;
}

Dio_LevelType Dio_ReadPinLevel(Dio_PortType port, Dio_PinType pin)
{
    Dio_LevelType level = DIO_LOW;
    switch (port)
    {
    case DIO_PORTA:
        if (GET_BIT(PINA, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTB:
        if (GET_BIT(PINB, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTC:
        if (GET_BIT(PINC, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    case DIO_PORTD:
        if (GET_BIT(PIND, pin) == 1)
        {
            level = DIO_HIGH;
        }
        else 
        {
            level = DIO_LOW;
        }
        break;
    default:
        break;
    }
    return level;
}
