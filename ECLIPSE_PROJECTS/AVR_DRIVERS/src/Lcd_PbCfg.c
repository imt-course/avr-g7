/*
 * Lcd_PbCfg.c
 *
 *  Created on: Oct 28, 2023
 *      Author: ahmad
 */
#include "Lcd.h"

Lcd_ConfigurationType Lcd_Configuration =
{
    .display        = LCD_ON,
    .cursor         = LCD_ON,
    .cursorBlink    = LCD_OFF,
    .lines          = LCD_LINES_2,
    .font           = LCD_FONT_5X7,
};
