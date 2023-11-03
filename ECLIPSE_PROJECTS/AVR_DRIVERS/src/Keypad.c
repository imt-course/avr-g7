/*
 * Keypad.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Fcpu.h"
#include <util/delay.h>
#include "Keypad_Cfg.h"
#include "Keypad.h"

 Dio_LevelType Keypad_ReadColumnLevel(u8 column);
 void Keypad_SetRowLevel(u8 row, Dio_LevelType level);

void Keypad_Init(void)
{
    Dio_SetPinMode(KEYPAD_PIN_R0, DIO_MODE_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_R1, DIO_MODE_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_R2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_R3, DIO_MODE_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C0, DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_C1, DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_C2, DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_C3, DIO_MODE_INPUT_PULLUP);
    Dio_SetPinLevel(KEYPAD_PIN_R0, DIO_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_R1, DIO_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_R2, DIO_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_R3, DIO_HIGH);
}

Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button)
{
    u8 row = button / 4;
    u8 column = button % 4;
    Keypad_ButtonStateType state;
    /* Set row to LOW */
    Keypad_SetRowLevel(row, DIO_LOW);
    /* Read Column Level */
    if (DIO_LOW == Keypad_ReadColumnLevel(column))
    {
        _delay_ms(5);
        if (DIO_LOW == Keypad_ReadColumnLevel(column))
        {
            state = KEYPAD_PRESSED;
        }
        else
        {
            state = KEYPAD_NOT_PRESSED;
        }
    }
    else
    {
        state = KEYPAD_NOT_PRESSED;
    }
    /* Reset row to HIGH */
    Keypad_SetRowLevel(row, DIO_HIGH);
    return state;
}


 void Keypad_SetRowLevel(u8 row, Dio_LevelType level)
{
    switch (row)
    {
    case 0:
        Dio_SetPinLevel(KEYPAD_PIN_R0, level);
        break;
    case 1:
        Dio_SetPinLevel(KEYPAD_PIN_R1, level);
        break;
    case 2:
        Dio_SetPinLevel(KEYPAD_PIN_R2, level);
        break;
    case 3:
        Dio_SetPinLevel(KEYPAD_PIN_R3, level);
        break;
    default:
        break;
    }
}

 Dio_LevelType Keypad_ReadColumnLevel(u8 column)
{
    Dio_LevelType level;
    switch (column)
    {
    case 0:
        level = Dio_ReadPinLevel(KEYPAD_PIN_C0);
        break;
    case 1:
        level = Dio_ReadPinLevel(KEYPAD_PIN_C1);
        break;
    case 2:
        level = Dio_ReadPinLevel(KEYPAD_PIN_C2);
        break;
    case 3:
        level = Dio_ReadPinLevel(KEYPAD_PIN_C3);
        break;
    default:
        level = DIO_HIGH;
        break;
    }
    return level;
}