/*
 * ExtInt.h
 *
 *  Created on: Nov 4, 2023
 *      Author: ahmad
 */

#ifndef INC_EXTINT_H_
#define INC_EXTINT_H_

#include "Dio.h"

#define EXTINT_PIN_INT0     DIO_PORTD,DIO_PIN2
#define EXTINT_PIN_INT1     DIO_PORTD,DIO_PIN3
#define EXTINT_PIN_INT2     DIO_PORTB,DIO_PIN2

typedef enum 
{
    EXTINT_EDGE_LOW_LEVEL,
    EXTINT_EDGE_ON_CHANGE,
    EXTINT_EDGE_FALLING,
    EXTINT_EDGE_RISING,
} ExtInt_SenseEdgeType;

typedef enum 
{
    EXTINT_INT0,
    EXTINT_INT1,
    EXTINT_INT2,
} ExtInt_ChannelType;

void ExtInt_SetSenseEdge(ExtInt_ChannelType channel, ExtInt_SenseEdgeType edge);
void ExtInt_EnableInterrupt(ExtInt_ChannelType channel);
void ExtInt_DisableInterrupt(ExtInt_ChannelType channel);


#endif /* INC_EXTINT_H_ */
