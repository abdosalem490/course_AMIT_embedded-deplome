/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 30/10/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	uint8 Size;
	uint8* ChannelArr;
	uint16* ResultArr;
	void(*Notification)(void);
}Chain_Config_t;

#define ADC_u8_SINGLE_ENDED_CH0		0
#define ADC_u8_SINGLE_ENDED_CH1		1
#define ADC_u8_SINGLE_ENDED_CH2		2
#define ADC_u8_SINGLE_ENDED_CH3		3
#define ADC_u8_SINGLE_ENDED_CH4		4
#define ADC_u8_SINGLE_ENDED_CH5		5
#define ADC_u8_SINGLE_ENDED_CH6		6
#define ADC_u8_SINGLE_ENDED_CH7		7


void ADC_voidInit(void);
uint8 ADC_u16StartConversionSync(uint8 Copy_u8Channel,uint16* Copy_pu16Result);

/*NOTE: Enable the Global interrupts enable to use this function*/
uint8 ADC_u16StartConversionAsync(uint8 Copy_u8Channel,uint16* Copy_pu16Result,void (*Copy_pvNotificationFunc)(void));

void ADC_voidEnable(void);
void ADC_voidDisable(void);

uint8 ADC_u8StartChainConversionAsynch(const Chain_Config_t* Copy_ChainObj);

#endif
