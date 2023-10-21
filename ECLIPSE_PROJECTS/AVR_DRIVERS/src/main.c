/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmad
 */


#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"


int main (void)
{
    /* Set Switch pin direction to input */
    CLR_BIT(DDRA, 0);
    /* Activate pull up resistor for switch pin */
    SET_BIT(PORTA, 0);
    /* Set Led pin direction to output */
    SET_BIT(DDRA, 1);
    while (1)
    {
        /* Check if switch is pressed */
        if (GET_BIT(PINA, 0) == 0)
        {
            /* Turn led on */
            SET_BIT(PORTA, 1);
        }
        else
        {
            /* Turn led off */
            CLR_BIT(PORTA, 1);
        }
    }
    
}
