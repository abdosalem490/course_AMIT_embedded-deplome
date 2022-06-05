/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 12/11/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



#define COMPARE_MODE	0
#define NORMAL_MODE		1
#define ICU_INT			2

#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE	0


void TIMER0_voidInit();
void TIMER1_voidInit();
void TIMER2_voidInit();

uint8 TIMER_Ovf_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),uint8 Copy_u8IsCompareMode);
uint8 TIMER1_Ovf_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),uint8 Copy_u8IsCompareMode);
uint8 TIMER2_Ovf_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),uint8 Copy_u8IsCompareMode);

void Timer0_voidSetTimerValue(uint8 Copy_u8Value);
void Timer1_voidSetTimerValue(uint16 Copy_u8Value);
void Timer2_voidSetTimerValue(uint8 Copy_u8Value);

void Timer0_voidSetCompareValue(uint8 Copy_u8Val);
void Timer1_voidSetCompareValue(uint8 Copy_u8Val);
void Timer2_voidSetCompareValue(uint8 Copy_u8Val);

uint16 Timer1_u16GetTimerValue();

void ICU_voidINit(void);
uint8 ICU_u8SetTrigger(uint8 Copy_u8Trigger);
uint16 ICU_u16GetCaptureeReading(void);
void ICU_voidInterruptDisable(void);

#endif
