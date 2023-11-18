/*
 * Lm35.h
 *
 *  Created on: Nov 18, 2023
 *      Author: ahmad
 */

#ifndef INC_LM35_H_
#define INC_LM35_H_

#include "StdTypes.h"

u8 Lm35_GetTemperature(u8 avgCount, u8 delayMs);

#endif /* INC_LM35_H_ */
