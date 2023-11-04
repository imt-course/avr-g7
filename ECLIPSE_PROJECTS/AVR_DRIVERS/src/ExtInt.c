/*
 * ExtInt.c
 *
 *  Created on: Nov 4, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Registers.h"
#include "Macros.h"
#include "ExtInt.h"

void ExtInt_SetSenseEdge(ExtInt_ChannelType channel, ExtInt_SenseEdgeType edge)
{
    if (EXTINT_INT0 == channel)
    {
        switch (edge)
        {
        case EXTINT_EDGE_LOW_LEVEL:
            CLR_BIT(MCUCR, 0);
            CLR_BIT(MCUCR, 1);
            break;
        case EXTINT_EDGE_ON_CHANGE:
            SET_BIT(MCUCR, 0);
            CLR_BIT(MCUCR, 1);
            break;
        case EXTINT_EDGE_FALLING:
            CLR_BIT(MCUCR, 0);
            SET_BIT(MCUCR, 1);
            break;
        case EXTINT_EDGE_RISING:
            SET_BIT(MCUCR, 0);
            SET_BIT(MCUCR, 1);
            break;
        
        default:
            break;
        }
    }
    else if (EXTINT_INT1 == channel)
    {
        switch (edge)
        {
        case EXTINT_EDGE_LOW_LEVEL:
            CLR_BIT(MCUCR, 2);
            CLR_BIT(MCUCR, 3);
            break;
        case EXTINT_EDGE_ON_CHANGE:
            SET_BIT(MCUCR, 2);
            CLR_BIT(MCUCR, 3);
            break;
        case EXTINT_EDGE_FALLING:
            CLR_BIT(MCUCR, 2);
            SET_BIT(MCUCR, 3);
            break;
        case EXTINT_EDGE_RISING:
            SET_BIT(MCUCR, 2);
            SET_BIT(MCUCR, 3);
            break;
        
        default:
            break;
        }
    }
    else if (EXTINT_INT2 == channel)
    {
        switch (edge)
        {
        case EXTINT_EDGE_FALLING:
            CLR_BIT(MCUCSR, 6);
            break;
        case EXTINT_EDGE_RISING:
            SET_BIT(MCUCSR, 6);
            break;
        
        default:
            break;
        }
    }
    else
    {
        /* Do Nothing. */
    }
}

void ExtInt_EnableInterrupt(ExtInt_ChannelType channel)
{
    switch (channel)
    {
    case EXTINT_INT0:
        SET_BIT(GICR, 6);
        break;
    case EXTINT_INT1:
        SET_BIT(GICR, 7);
        break;
    case EXTINT_INT2:
        SET_BIT(GICR, 5);
        break;
    default:
        break;
    }
}

void ExtInt_DisableInterrupt(ExtInt_ChannelType channel)
{
    switch (channel)
    {
    case EXTINT_INT0:
        CLR_BIT(GICR, 6);
        break;
    case EXTINT_INT1:
        CLR_BIT(GICR, 7);
        break;
    case EXTINT_INT2:
        CLR_BIT(GICR, 5);
        break;
    default:
        break;
    }
}
