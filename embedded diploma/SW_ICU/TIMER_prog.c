/*******************************************************************/
/*******************************************************************/
/*****************   Author:  Amgad Samir		********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "TIMER_reg.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"


static void (*Timer0Ovf_pvCallBackFunc)(void)=NULL;

static void (*Timer0Comp_pvCallBackFunc)(void)=NULL;


void TIMER0_voidInit(void)
{
	/*Fast PWM Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	/*Set on top clear on compare*/
	SET_BIT(TCCR0, TCCR0_COM01);
	CLR_BIT(TCCR0, TCCR0_COM00);

	/*Prescaler: divison by 64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	/*Compare value = 64 for Duty cycle = 25%*/
	OCR0 = 64;
	
}

void Timer0_voidSetTimerValue(uint8 Copy_u8Val)
{
	TCNT0= Copy_u8Val;
}

uint8 TIMER0_u8SetCallBack(uint8 Copy_u8IntType,void (*Copy_pvCallBackFunc)(void))
{
	uint8 Local_u8ErrorState= OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		if(Copy_u8IntType == TIMER0_u8_OVF)
		{
			Timer0Ovf_pvCallBackFunc= Copy_pvCallBackFunc;
		}
		else if(Copy_u8IntType == TIMER0_u8_COMP)
		{
			Timer0Comp_pvCallBackFunc= Copy_pvCallBackFunc;
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void TIMER1_voidInit(void)
{
	/*1- Normal Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*2- Prescaler: Division by 64*/
	SET_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void TIMER1_voidSetValue(uint16 Copy_u16Val)
{
	TCNT1= Copy_u16Val;
}

uint16 TIMER1_u16GetTimerReading(void)
{
	return TCNT1;
}

/*Timer0 Overflow ISR*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(Timer0Ovf_pvCallBackFunc != NULL)
	{
		Timer0Ovf_pvCallBackFunc();
	}		
	else
	{
		/*Do nothing*/
	}
}

/*Timer0 Compare Match ISR*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Timer0Comp_pvCallBackFunc != NULL)
	{
		Timer0Comp_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}
