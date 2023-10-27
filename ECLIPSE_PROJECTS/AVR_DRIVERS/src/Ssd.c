/*
 * Ssd.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Dio.h"
#include "Ssd_Cfg.h"
#include "Ssd.h"

#if (SSD_TYPE==SSD_COM_ANODE)
    #define SSD_ON   DIO_LOW
    #define SSD_OFF  DIO_HIGH
#elif (SSD_TYPE==SSD_COM_CATHODE)
    #define SSD_ON   DIO_HIGH
    #define SSD_OFF  DIO_LOW
#else
    #define SSD_ON   DIO_HIGH
    #define SSD_OFF  DIO_HIGH
    #error Invalid SSD Type
#endif

void Ssd_Init(void)
{
    Dio_SetPinMode(SSD_PIN_A  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_B  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_C  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_D  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_E  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_F  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_G  , DIO_MODE_OUTPUT);
    Dio_SetPinMode(SSD_PIN_DOT, DIO_MODE_OUTPUT);
}

void Ssd_DisplayNumber(u8 number)
{

    switch (number)
    {
    case 0:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_OFF);
        break;
    case 1: 
        Dio_SetPinLevel(SSD_PIN_A  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_OFF);
        break;
    case 2:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 3:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 4:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 5:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 6:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 7:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_OFF);
        break;
    case 8:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    case 9:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_ON);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_ON);
        break;
    default:
        Dio_SetPinLevel(SSD_PIN_A  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_B  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_C  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_D  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
        Dio_SetPinLevel(SSD_PIN_G  , SSD_OFF);
        break;
    }
}

void Ssd_Clear(void)
{
    Dio_SetPinLevel(SSD_PIN_A  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_B  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_C  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_D  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_E  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_F  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_G  , SSD_OFF);
    Dio_SetPinLevel(SSD_PIN_DOT  , SSD_OFF);
}

void Ssd_DisplayDot(void)
{
    Dio_SetPinLevel(SSD_PIN_DOT, SSD_ON);
}

void Ssd_ClearDot(void)
{
    Dio_SetPinLevel(SSD_PIN_DOT, SSD_OFF);
}

