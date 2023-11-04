/*
 * Interrupts.h
 *
 *  Created on: Nov 4, 2023
 *      Author: ahmad
 */

#ifndef INC_INTERRUPTS_H_
#define INC_INTERRUPTS_H_

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#define VECTOR_INT0     __vector_1
#define VECTOR_INT1     __vector_2
#define VECTOR_INT2     __vector_3



#endif /* INC_INTERRUPTS_H_ */
