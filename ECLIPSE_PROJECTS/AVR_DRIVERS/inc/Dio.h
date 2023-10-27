/*
 * Dio.h
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_

typedef enum
{
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} Dio_PortType;

typedef enum 
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
} Dio_PinType;

typedef enum 
{
    DIO_LOW,
    DIO_HIGH
} Dio_LevelType;

typedef enum 
{
    DIO_MODE_INPUT_FLOATING,
    DIO_MODE_INPUT_PULLUP,
    DIO_MODE_OUTPUT
} Dio_ModeType;

void Dio_SetPinMode(Dio_PortType port, Dio_PinType pin, Dio_ModeType mode);
void Dio_SetPinLevel(Dio_PortType port, Dio_PinType pin, Dio_LevelType level);
Dio_LevelType Dio_FlipPinLevel(Dio_PortType port, Dio_PinType pin);
Dio_LevelType Dio_ReadPinLevel(Dio_PortType port, Dio_PinType pin);

#endif /* INC_DIO_H_ */
