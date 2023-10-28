/*
 * Lcd.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Macros.h"
#include "Fcpu.h"
#include <util/delay.h>
#include "Lcd_Cfg.h"
#include "Lcd.h"

static void Lcd_SendCommand(u8 command);
static void Lcd_SendData(u8 data);

void Lcd_Init(Lcd_ConfigurationType* config)
{
    u8 command;
    /* Set LCD Pins to Output */
    Dio_SetPinMode(LCD_PIN_RS, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_RW, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_EN, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D0, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D1, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D2, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D3, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D4, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D5, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D6, DIO_MODE_OUTPUT);
    Dio_SetPinMode(LCD_PIN_D7, DIO_MODE_OUTPUT);
    /* Function Set */
    command = 0b00110000;
    if (LCD_LINES_2 == config->lines)
    {
        SET_BIT(command, 3);
    }
    if (LCD_FONT_5X10 == config->font)
    {
        SET_BIT(command, 2);
    }
    Lcd_SendCommand(command);
    /* Display Control */
    command = 0b00001000;
    if (LCD_ON == config->display)
    {
        SET_BIT(command, 2);
    }
    if (LCD_ON == config->cursor)
    {
        SET_BIT(command, 1);
    }
    if (LCD_ON == config->cursorBlink)
    {
        SET_BIT(command, 0);
    }
    Lcd_SendCommand(command);
    /* Display Clear */
    Lcd_SendCommand(0b00000001);
}

void Lcd_ClearDisplay(void)
{
    Lcd_SendCommand(0b00000001);
}

static void Lcd_SendCommand(u8 command)
{
    Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(command, 0));
    Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(command, 1));
    Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(command, 2));
    Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(command, 3));
    Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(command, 4));
    Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(command, 5));
    Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(command, 6));
    Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(command, 7));
    Dio_SetPinLevel(LCD_PIN_RS, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_HIGH);
    _delay_ms(2);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_LOW);
}

void Lcd_DisplayCharacter(char data)
{
    Lcd_SendData(data);
}

void Lcd_DisplayString(char* str)
{
    while (*str != 0)
    {
        Lcd_SendData(*str);
        str++;
    }
}

void Lcd_DisplayNumber(s32 number)
{
    u32 reversed = 0;
    u8 digitsCounter = 0;
    if (number < 0)
    {
        number *= -1;
        Lcd_SendData('-');
    }
    do
    {
        reversed = (reversed*10) + (number%10);
        number /= 10;
        digitsCounter++;
    } while (number > 0);
    do
    {
        Lcd_SendData((reversed%10) + '0');
        reversed /= 10;
        digitsCounter--;
    } while (digitsCounter > 0);
}

void Lcd_DisplayFloatNumber(f32 number)
{
    if (number < 0)
    {
        number *= -1;
        Lcd_SendData('-');
    }
    Lcd_DisplayNumber((u32)number);
    number = (number - (u32)number)*100;
    Lcd_SendData('.');
    Lcd_DisplayNumber((u32)number);
}

void Lcd_SetCursorPosition(u8 row, u8 column)
{
    u8 address;
    address = column + 0x40*row;
    #if 0
    if (row == 0)
    {
        address = column;
    }
    else
    {
        address = column + 0x40;
    }
    #endif
    SET_BIT(address, 7);
    Lcd_SendCommand(address);
}

void Lcd_ShiftDisplayLeft(u8 count)
{
    while (count > 0)
    {
        Lcd_SendCommand(0b00011000);
        count--;
    }
}
void Lcd_ShiftDisplayRight(u8 count)
{
    while (count > 0)
    {
        Lcd_SendCommand(0b00011100);
        count--;
    }
}

void Lcd_ReturnHome(void)
{
    Lcd_SendCommand(0b00000010);
}

static void Lcd_SendData(u8 data)
{
    Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(data, 0));
    Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(data, 1));
    Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(data, 2));
    Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(data, 3));
    Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(data, 4));
    Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(data, 5));
    Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(data, 6));
    Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(data, 7));
    Dio_SetPinLevel(LCD_PIN_RS, DIO_HIGH);
    Dio_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_HIGH);
    _delay_ms(2);
    Dio_SetPinLevel(LCD_PIN_EN, DIO_LOW);
}



