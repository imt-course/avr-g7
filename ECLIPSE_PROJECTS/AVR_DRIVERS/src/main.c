/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */


#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"


#define F_CPU 8000000UL
#include <util/delay.h>

int main (void)
{
    u8 i;
    u8 ssdValues[10] = {
        0b11000000,
        0b11111001,
        0b10100100,
        0b10110000,
        0b10011001,
        0b10010010,
        0b10000011,
        0b11111000,
        0b10000000,
        0b10010000
    };
    DDRA = 0xFF;
    while (1)
    {
        for (i=0; i<10; i++)
        {
            PORTA = ssdValues[i];
            _delay_ms(1000);
        }
    }
    
}
