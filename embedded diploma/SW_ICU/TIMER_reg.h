/*******************************************************************/
/*******************************************************************/
/*****************   Author:  Amgad Samir		********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile uint8*)0x53)	/*Timer/counter 0 control register*/
#define TCCR0_WGM00		6							/*Waveform generation mode bit 0*/
#define TCCR0_COM01		5							/*Compare output mode bit 1*/
#define TCCR0_COM00		4							/*Compare output mode bit 0*/
#define TCCR0_WGM01		3                           /*Waveform generation mode bit 1*/
#define TCCR0_CS02		2
#define TCCR0_CS01		1
#define TCCR0_CS00		0


#define TCNT0			*((volatile uint8*)0x52)	/*Timer/counter 0 register*/

#define TCNT1			*((volatile uint16*)0x4C)	/*Timer/counter 1 register*/

#define OCR0			*((volatile uint8*)0x5C)

#define TIMSK			*((volatile uint8*)0x59)	/*Timer mask register*/
#define TIMSK_TOIE0		0							/*Timer0 overflow interrupt enable*/
#define TIMSK_OCIE0		1

#define TCCR1A			*((volatile uint8*)0x4F)		/*Timer1 Control registerA*/
#define TCCR1A_COM1A1	7                               /*ChannelA compare match output mode bit1*/
#define TCCR1A_COM1A0	6                               /*ChannelA compare match output mode bit0*/
#define TCCR1A_WGM11	1                               /*Waveform generation mode bit1*/
#define TCCR1A_WGM10	0                               /*Waveform generation mode bit1*/


#define TCCR1B			*((volatile uint8*)0x4E)         /*Timer1 control registerB*/
#define TCCR1B_WGM13	4                                /*Waveform generation mode bit3*/
#define TCCR1B_WGM12	3                                /*Waveform generation mode bit2*/
#define TCCR1B_CS12		2                                /*Prescaler bit 2*/
#define TCCR1B_CS11		1                                /*Prescaler bit 1*/
#define TCCR1B_CS10		0								 /*Prescaler bit 0*/

#define OCR1A			*((volatile u16*)0x4A)			/*ChannelA Output compare match register*/

#define ICR1			*((volatile u16*)0x46)			/*Input capture register*/


#endif
