/*
 * Registers.h
 *
 *  Created on: Oct 21, 2023
 *      Author: ahmad
 */

#ifndef INC_REGISTERS_H_
#define INC_REGISTERS_H_

/******** DIO Registers ********/
#define PINA        *((const volatile u8*)0x39)
#define DDRA        *((volatile u8*)0x3A)
#define PORTA       *((volatile u8*)0x3B)
#define PINB        *((const volatile u8*)0x36)
#define DDRB        *((volatile u8*)0x37)
#define PORTB       *((volatile u8*)0x38)
#define PINC        *((const volatile u8*)0x33)
#define DDRC        *((volatile u8*)0x34)
#define PORTC       *((volatile u8*)0x35)
#define PIND        *((const volatile u8*)0x30)
#define DDRD        *((volatile u8*)0x31)
#define PORTD       *((volatile u8*)0x32)

/******** ExtInt Registers ********/
#define MCUCR       *((volatile u8*)0x55)
#define MCUCSR      *((volatile u8*)0x54)
#define GICR        *((volatile u8*)0x5B)
#define GIFR        *((volatile u8*)0x5A)

/******** SREG Registers ********/
#define SREG        *((volatile u8*)0x5F)

#endif /* INC_REGISTERS_H_ */
