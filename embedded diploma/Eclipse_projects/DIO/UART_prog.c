#include "ERR_TYPE.h"
#include "BTT_MATH.h"
#include "STD_TYPES.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_reg.h"

void USART_voidInit()
{

	//Open the Transmitter & the  reciever
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	//Disable interrupt
	CLR_BIT(UCSRB,UCSRB_RXCIE);
	CLR_BIT(UCSRB,UCSRB_TXCIE);

	//8 bits data
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	//register select to be 1
	//make it Asynchronous
	//no parity
	UCSRC = 0b10000110;

	//9600 bps
	UBRRL = 103;
}
uint8 USART_u8RecieveData()
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
	return UDR;

}
void USART_voidSendData(uint8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = Copy_u8Data;
	//while(GET_BIT(UCSRA,UCSRA_TXC) == 0);
}
