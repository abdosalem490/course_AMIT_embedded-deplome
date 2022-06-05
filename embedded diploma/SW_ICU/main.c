#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"

#include "CLCD_interface.h"

void SW_ICU(void);

static uint16 PeriodTicks=0;
static uint16 OnTicks=0;

void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	EXTI_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	EXTI_u8SetCallBack(EXTI_u8_INT0,&SW_ICU);

	GIE_voidEnableGlobal();
	while(1)
	{
		while((PeriodTicks == 0) || (OnTicks == 0));
		CLCD_u8GoToXY(0,0);
		CLCD_voidSendNumber(PeriodTicks);
		CLCD_u8GoToXY(0,1);
		CLCD_voidSendNumber(OnTicks);
	}
}

void SW_ICU(void)
{
	volatile static uint8 Local_u8Counter;
	uint16 Local_u16Temp;

	Local_u8Counter++;

	if(Local_u8Counter==1)
	{
		/*Clear timer 1*/
		TIMER1_voidSetValue(0);
	}
	else if(Local_u8Counter==2)
	{
		/*Get number of ticks of period time*/
		PeriodTicks= TIMER1_u16GetTimerReading();
		EXTI_u8SetSenseControl(EXTI_u8_INT0,FALLING_EDGE);
	}
	else if(Local_u8Counter==3)
	{
		Local_u16Temp = TIMER1_u16GetTimerReading();
		OnTicks= Local_u16Temp- PeriodTicks;
		EXTI_u8DisableInt(EXTI_u8_INT0);
	}
}
