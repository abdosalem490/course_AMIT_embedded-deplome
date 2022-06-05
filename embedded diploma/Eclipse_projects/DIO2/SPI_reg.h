/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 3/12/2021		********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR		*((volatile uint8*) 0x2D)	//SPI Control Register
#define SPCR_SPIE		7	//SPI Interrupt Enable
#define SPCR_SPE		6	//SPI Enable
#define SPCR_DORD		5	//Data Order
#define SPCR_MSTR 		4	//Master/Slave Select
#define SPCR_CPOL		3	//Clock Polarity
#define SPCR_CPHA		2	// Clock Phase
#define SPCR_SPR1		1	//Clock Rate Select 1
#define SPCR_SPR0		0	//Clock Rate Select 0

#define SPSR		*((volatile uint8*) 0x2E)	//SPI Status Register
#define SPSR_SPIF		7	//SPI Interrupt Flag
#define SPSR_WCOL		6	//Write COLlision Flag
#define SPSR_Res5		5	//Reserved Bits
#define SPSR_Res4		4	//Reserved Bits
#define SPSR_Res3		3	//Reserved Bits
#define SPSR_Res2		2	//Reserved Bits
#define SPSR_Res1		1	//Reserved Bits
#define SPSR_SPI2X		0	//Double SPI Speed Bit

#define SPDR		*((volatile uint8*) 0x2F)	//SPI Data Register



#endif
