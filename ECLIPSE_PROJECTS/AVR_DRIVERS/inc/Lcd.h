/*
 * Lcd.h
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "StdTypes.h"

typedef enum
{
    LCD_OFF,
    LCD_ON
} Lcd_StatusType;

typedef enum
{
    LCD_LINES_1,
    LCD_LINES_2
} LCd_LinesType;

typedef enum
{
    LCD_FONT_5X7,
    LCD_FONT_5X10
} Lcd_FontType;

typedef struct 
{
    Lcd_StatusType display;
    Lcd_StatusType cursor;
    Lcd_StatusType cursorBlink;
    LCd_LinesType lines;
    Lcd_FontType font;
} Lcd_ConfigurationType;

extern Lcd_ConfigurationType Lcd_Configuration;

void Lcd_Init(Lcd_ConfigurationType* config);
void Lcd_DisplayCharacter(char data);
void Lcd_DisplayString(char* str);
void Lcd_DisplayNumber(s32 number);
void Lcd_DisplayFloatNumber(f32 number);
void Lcd_SetCursorPosition(u8 row, u8 column);
void Lcd_ShiftDisplayLeft(u8 count);
void Lcd_ShiftDisplayRight(u8 count);
void Lcd_ReturnHome(void);
void Lcd_ClearDisplay(void);

#endif /* INC_LCD_H_ */
