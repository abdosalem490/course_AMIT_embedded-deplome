/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 30/10/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#include "BTT_MATH.h"
#include "STD_TYPES.h"
#include "ERR_TYPE.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_reg.h"

/*Pointer to function to hold notification function address*/
static void (*ADC_pvNotificationFunc)(void) = NULL;

/*Pointer to u16 to hold the conversion result*/
static uint16* ADC_pu16Result = NULL;

/*global variable to hold the ADC peripheral busy state*/
static uint8 ADC_u8BusyState = IDLE;

void ADC_voidInit(void)
{
#if ADC_u8_REF_SELECTION == AREF
	CLR_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif ADC_u8_REF_SELECTION == AVCC
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#elif ADC_u8_REF_SELECTION == INTERNAL_2560mV
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error "Wrong ADC_u8_REF_SELECTION Configuration option"
#endif

#if ADC_u8_RESOLUTION == EIGHT_BIT
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8_RESOLUTION == TEN_BIT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong ADC_u8_REF_RESOLUTION Configuration option"
#endif

ADCSRA &= PRESCALAR_BIT_MASK;
ADCSRA |= ADC_u8_PRESCALER;

#if ADC_u8_ENABLE_INIT_STATE == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_u8_ENABLE_INIT_STATE == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error "Wrong ADC_u8_ENABLE_INIT_STATE Configuration option"
#endif
}
void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
void ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}
uint8 ADC_u16StartConversionSync(uint8 Copy_u8Channel,uint16* Copy_pu16Result)
{
	uint8 local_u8ErrorState = OK;
	uint32 Local_u32Countfer = 0;

	if(Copy_pu16Result != NULL)
	{
		if(ADC_u8BusyState == IDLE)
		{
			/*ADC is now busy*/
			ADC_u8BusyState = BUSY;
			/*select channel ADC0*/
			ADMUX &= CHANNEL_BIT_MASK;
			ADMUX |= Copy_u8Channel;

			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*wait (polling) for the conversion complete flag or wait until timeout passes*/
			while((GET_BIT(ADCSRA,ADCSRA_ADIF) == 0) && (Local_u32Countfer != ADC_u32_TIMEOUT_VALUE))
			{
				Local_u32Countfer++;
			}
			if(Local_u32Countfer == ADC_u32_TIMEOUT_VALUE)
			{
				/*loop is broken because timeout passed without flag*/
				local_u8ErrorState = TIMEOUT_ERR;
			}
			else
			{
				/*flag is raised before timeout*/
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);

			#if ADC_u8_RESOLUTION == EIGHT_BIT
				*Copy_pu16Result = ADCH;
			#elif ADC_u8_RESOLUTION == TEN_BIT
				*Copy_pu16Result = ADC;
			#endif

				/*ADC is now IDLE*/
				ADC_u8BusyState = IDLE;
			}
		}
		else
		{
			local_u8ErrorState = BUSY_ERR;
		}
	}
	else
	{
		local_u8ErrorState = NULL_POINTER;
	}
	return local_u8ErrorState;
}
uint8 ADC_u16StartConversionAsync(uint8 Copy_u8Channel,uint16* Copy_pu16Result,void (*Copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK;
	if((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if(ADC_u8BusyState == IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8BusyState = BUSY;

			/*store the address of the notification function globally*/
			ADC_pvNotificationFunc = Copy_pvNotificationFunc;

			/*store the result variable address globally*/
			ADC_pu16Result = Copy_pu16Result;

			/*select channel ADC0*/
			ADMUX &= CHANNEL_BIT_MASK;
			ADMUX |= Copy_u8Channel;

			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

/*ADC ISR*/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/*Get the Conversion Result*/
#if ADC_u8_RESOLUTION == EIGHT_BIT
	*ADC_pu16Result = ADCH;
#elif ADC_u8_RESOLUTION == TEN_BIT
	*ADC_pu16Result = ADC;
#endif
	/*Disable the ADC interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*ADC is now IDLE*/
	ADC_u8BusyState = IDLE;

	/*Invoke the callback notification function*/
	if(ADC_pvNotificationFunc != NULL)
	{
		ADC_pvNotificationFunc();
	}
	else
	{
		/*Do nothing*/
	}
}
