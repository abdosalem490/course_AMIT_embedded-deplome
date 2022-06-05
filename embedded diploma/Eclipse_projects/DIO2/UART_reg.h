/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 27/11/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR		*((volatile uint8*) 0x2C)		//USART I/O Data Register


#define UCSRA	*((volatile uint8*) 0x2B)		//USART Control and Status Register A
#define UCSRA_RXC		7		//USART Receive Complete
#define UCSRA_TXC		6		//USART Transmit Complete
#define UCSRA_UDRE		5		//USART Data Register Empty
#define UCSRA_FE		4		//Frame Error
#define UCSRA_DOR		3		//Data OverRun
#define UCSRA_PE		2		//Parity Error
#define UCSRA_U2X		1		//Double the USART Transmission Speed
#define UCSRA_MPCM		0		//Multi-processor Communication Mode

#define UCSRB	*((volatile uint8*) 0x2A)		//USART Control and Status Register B
#define UCSRB_RXCIE		7		//RX Complete Interrupt Enable
#define UCSRB_TXCIE		6		//TX Complete Interrupt Enable
#define UCSRB_UDRIE		5		//USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN		4		//Receiver Enable
#define UCSRB_TXEN		3		//Transmitter Enable
#define UCSRB_UCSZ2		2		//Character Size
#define UCSRB_RXB8		1		//Receive Data Bit 8
#define UCSRB_TXB8		0		//Transmit Data Bit 8


#define UCSRC	*((volatile uint8*) 0x40)		//USART Control and Status Register C
#define UCSRC_URSEL		7		//Register Select
#define UCSRC_UMSEL		6		//USART Mode Select
#define UCSRC_UPM1		5		//Parity Mode
#define UCSRC_UPM0		4		//Parity Mode
#define UCSRC_USBS		3		//Stop Bit Select
#define UCSRC_UCSZ1		2		//Character Size
#define UCSRC_UCSZ0		1		//Character Size
#define UCSRC_UCPOL		0		//Clock Polarity

#define UBRRH	*((volatile uint8*) 0x40)		//USART Baud Rate Registers	High
#define UBRRL	*((volatile uint8*) 0x29)		//USART Baud Rate Registers	Low
#define UBRRH_URSEL		15		//Register Select
#define UBRRH_UBRRL_UBRR11_0		0		//USART Baud Rate Register (from bit 11 to 0)
#endif
