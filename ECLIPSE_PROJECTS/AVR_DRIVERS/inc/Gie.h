/*
 * Gie.h
 *
 *  Created on: Nov 4, 2023
 *      Author: ahmad
 */

#ifndef INC_GIE_H_
#define INC_GIE_H_

#include "StdTypes.h"

/* Set Bit 7 in SREG Register */
#define GIE_ENABLE()  *((volatile u8*)0x5F)|=0x80
/* Clear Bit 7 in SREG Register */
#define GIE_DISABLE() *((volatile u8*)0x5F)&=0x7F


#endif /* INC_GIE_H_ */
