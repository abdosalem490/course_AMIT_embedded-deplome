/*********************************************************************/
/*********************************************************************/
/**********************		Author: Amgad Samir			**************/
/**********************		Date: 29/10/2021			**************/
/**********************		layer: MCAL					**************/
/**********************		Version: 1.00				**************/
/*********************************************************************/
/*********************************************************************/

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define MCUCR			*((volatile uint8*)0x55)		/*MCU control register*/
#define MCUCR_ISC11		3								/*Int1 sense control bit 1*/
#define MCUCR_ISC10		2                               /*Int1 sense control bit 0*/
#define MCUCR_ISC01		1                               /*Int0 sense control bit 1*/
#define MCUCR_ISC00		0								/*Int0 sense control bit 0*/


#define MCUCSR			*((volatile uint8*)0x54)		/*MCU control and status register*/
#define MCUCSR_ISC2		6								/*Int2 sense control*/

#define GICR			*((volatile uint8*)0x5B)        /*General Interrupt control register*/
#define GICR_INT1		7                               /*INT1 bit PIE*/
#define GICR_INT0		6                               /*INT0 bit PIE*/
#define GICR_INT2		5                               /*INT2 bit PIE*/


#endif