/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 27/11/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void USART_voidInit();
uint8 USART_u8RecieveData();
void USART_voidSendData(uint8 Copy_u8Data);

#endif
