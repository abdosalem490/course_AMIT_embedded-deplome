#include<util/delay.h>

#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "PORT_interface.h"

#include "DIO_interface.h"

#include "GIE_interface.h"

#include "ADC_interface.h"

#include "CLCD_interface.h"

#include "TIMER_interface.h"

#include "UART_interface.h"

#include "SPI_interface.h"

#define WDTCR 		*((volatile uint8*) 0x41)	//Watch dog Timer Control Register
#define WDTCR_WDTOE			4		// Watch dog Turn-off Enable
#define WDTCR_WDE			3		// Watch dog Enable
#define WDTCR_WDP2			2		//Watch dog Timer Prescaler 2
#define WDTCR_WDP1			1		//Watch dog Timer Prescaler 1
#define WDTCR_WDP0			0		//Watch dog Timer Prescaler 0

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidSleep(uint8 Copy_u8Time)
{
	WDTCR &= 0b11111000;
	Copy_u8Time &= 0b00000111;
	WDTCR |= Copy_u8Time;
}
void WDT_voidDisable(void)
{
	WDTCR = (1 << WDTCR_WDE) | (1 << WDTCR_WDTOE);
	WDTCR = 0;
}

static uint16 StartTime = 0;
static uint16 SecondEdgeTime=0;
static uint16 ThirdEdgeTime = 0 ;
static uint8 Global_enable = 0;
void ISR()
{
	volatile static uint8 Local_u8Edge = 0;
	if(Local_u8Edge == 0)
	{
		StartTime = ICU_u16GetCaptureeReading();
		Local_u8Edge++;
	}
	else if(Local_u8Edge == 1)
	{
		SecondEdgeTime = ICU_u16GetCaptureeReading();
		ICU_u8SetTrigger(ICU_FALLING_EDGE);
		Local_u8Edge++;
	}
	else if(Local_u8Edge == 2)
	{
		ThirdEdgeTime = ICU_u16GetCaptureeReading();

		ICU_voidInterruptDisable();
		Global_enable = 1;
	}
}


void main()
{

	uint8 Local_u8RecievedData;
	PORT_voidInit();
	SPI_voidInitSlave();



	while(1)
	{
		Local_u8RecievedData = SPI_u8Transcieve(2);
			if(Local_u8RecievedData == 1)
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_HIGH);
		_delay_ms(1000);
	}

}

