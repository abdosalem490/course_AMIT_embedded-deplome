/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 30/10/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AREF				1
#define AVCC				2
#define INTERNAL_2560mV		3

#define EIGHT_BIT			1
#define TEN_BIT				2

#define ENABLED				1
#define DISABLED			2

#define DIVIDE_BY_2			0
#define DIVIDE_BY_4			2
#define DIVIDE_BY_8			3
#define DIVIDE_BY_16		4
#define DIVIDE_BY_32		5
#define DIVIDE_BY_64		6
#define DIVIDE_BY_128		7

#define PRESCALAR_BIT_MASK  0b11111000
#define CHANNEL_BIT_MASK	0b11100000

#define IDLE				0
#define BUSY				1
#endif
