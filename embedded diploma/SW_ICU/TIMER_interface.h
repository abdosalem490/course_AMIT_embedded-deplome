/*******************************************************************/
/*******************************************************************/
/*****************   Author:  Amgad Samir		********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0_u8_OVF		0
#define TIMER0_u8_COMP		1

void TIMER0_voidInit(void);
void Timer0_voidSetTimerValue(uint8 Copy_u8Val);
uint8 TIMER0_u8SetCallBack(uint8 Copy_u8IntType,void (*Copy_pvCallBackFunc)(void));

void TIMER1_voidInit(void);

void TIMER1_voidSetValue(uint16 Copy_u16Val);

uint16 TIMER1_u16GetTimerReading(void);


#endif
