#include "STD_TYPES.h"
#include "ERR_TYPE.h"
#include "BTT_MATH.h"

#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_reg.h"

static void (*TimerOvF_pvCallBackFunc)(void) = NULL;
static void (*TimerCompareOvF_pvCallBackFunc)(void) = NULL;
static void (*ICU_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit()
{
#if Mode == COMPARE_MODE
	/*Set Wave Form Generation Mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif Mode == NORMAL_MODE
	/*Normal Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif Mode == PWM_Mode
	/*Pulse Wait Modulation*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set on Top Clear on Compare*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	//compare value = 64 for duty cycle = 25%
	OCR0 = 64;
#endif

	/*Prescalar: division by 64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	/*overflow interrupt enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

}
uint8 TIMER_Ovf_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),uint8 Copy_u8IsCompareMode)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		if(Copy_u8IsCompareMode == NORMAL_MODE)
			TimerOvF_pvCallBackFunc = Copy_pvCallBackFunc;
		else if(Copy_u8IsCompareMode == COMPARE_MODE)
			TimerCompareOvF_pvCallBackFunc = Copy_pvCallBackFunc;
		else if(Copy_u8IsCompareMode == ICU_INT)
			ICU_pvCallBackFunc = Copy_pvCallBackFunc;
		else
			Local_u8ErrorState = NOK;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
void Timer0_voidSetTimerValue(uint8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

void Timer0_voidSetCompareValue(uint8 Copy_u8Val)
{
	/*Enable Compare Interrupt Mode*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	OCR0 = Copy_u8Val;
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TimerOvF_pvCallBackFunc != NULL)
	{
		TimerOvF_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}

}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TimerCompareOvF_pvCallBackFunc != NULL)
	{
		TimerCompareOvF_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}

/*----------------Timer 1-------------------*/
//timer 1 initialization
void TIMER1_voidInit()
{
	// set normal mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

	// set prescalar to be 64
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}

//timer 1 ISR
// timer 1 Capture Event
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}
// timer 1 Compare Match A
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{

}
// timer 1 Compare Match B
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{

}
// timer 1 OverFlow
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{

}

void Timer1_voidSetTimerValue(uint16 Copy_u8Value)
{
	TCNT1 = Copy_u8Value;
}

uint16 Timer1_u16GetTimerValue()
{
	return TCNT1;
}



/************** ICU **************/
void ICU_voidINit(void)
{
	//set rising edge as trigger
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	//ICU interrupt enable
	SET_BIT(TIMSK,TIMSK_TICIE1);

}
uint8 ICU_u8SetTrigger(uint8 Copy_u8Trigger)
{
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8Trigger)
	{
	case ICU_RISING_EDGE : SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	default : Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
uint16 ICU_u16GetCaptureeReading(void)
{
	return ICR1;
}
void ICU_voidInterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
/*********************************/
