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
#include "Ssd.h"


#define F_CPU 8000000UL
#include <util/delay.h>

int main (void)
{
    u8 i;
    Ssd_Init();
    while (1)
    {
        for (i=0; i<10; i++)
        {
            Ssd_DisplayNumber(i);
            _delay_ms(1000);
        }
    }
}
