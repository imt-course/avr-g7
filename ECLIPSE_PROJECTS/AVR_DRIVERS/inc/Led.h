/*
 * Led.h
 *
 *  Created on: Oct 27, 2023
 *      Author: ahmad
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "Dio.h"
#include "Led_Cfg.h"

void Led_Init(Dio_PortType port, Dio_PinType pin);
void Led_TurnOn(Dio_PortType port, Dio_PinType pin);
void Led_TurnOff(Dio_PortType port, Dio_PinType pin);

#endif /* INC_LED_H_ */
