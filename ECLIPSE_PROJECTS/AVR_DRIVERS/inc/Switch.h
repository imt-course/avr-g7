/*
 * Switch.h
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */

#ifndef INC_SWITCH_H_
#define INC_SWITCH_H_

#include "Dio.h"
#include "Switch_Cfg.h"

typedef enum 
{
    SWITCH_NOT_PRESSED,
    SWITCH_PRESSED
} Switch_StateType;

void Switch_Init(Dio_PortType port, Dio_PinType pin);
Switch_StateType Switch_GetState(Dio_PortType port, Dio_PinType pin);


#endif /* INC_SWITCH_H_ */
