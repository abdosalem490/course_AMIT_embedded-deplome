/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 12/11/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef TIMER_REG_H_
#define TIMER_REG_H_


#define TIMSK 	*((volatile uint8*) 0x59)		//Timer_Comter Interrupt Mask Register
#define TIMSK_OCIE2		7		//Timer_Counter2 Output Compare Match Interrupt Enable
#define TIMSK_TOIE2		6		//Timer_Counter2 Overflow Interrupt Enable
#define TIMSK_TICIE1	5		//Timer_Counter1, Input Capture Interrupt Enable
#define TIMSK_OCIE1A	4		//Timer_Counter1, Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B	3		//Timer_Counter1, Output Compare B Match Interrupt Enable
#define TIMSK_TOIE1		2		//Timer_Counter1, Overflow Interrupt Enable
#define TIMSK_OCIE0		1		//Timer_Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0		0		//Timer_Counter0 OverFlow Interrupt Enable

#define TIFR  	*((volatile uint8*) 0x58)		//Timer_Counter Interrupt Register
#define TIFR_OCF2		7		//Output Compare Flag 2
#define TIFR_TOV2		6		//Timer_Counter2 Overflow Flag
#define TIFR_ICF1		5		// Timer_Counter1, Input Capture Flag
#define TIFR_OCF1A		4		//Timer_Counter1, Output Compare A Match Flag
#define TIFR_OCF1B		3		//Timer_Counter1, Output Compare B Match Flag
#define TIFR_TOV1		2		//Timer_Counter1, Overflow Flag
#define TIFR_OCF0		1		//Output Compare Flag0
#define TIFR_TOV0		0		//Timer_Counter0 OverFlow Flag

/*******Timer 0 registers*******/

#define TCCR0 	*((volatile uint8*) 0x53)		//Timer_Counter Control Register
#define TCCR0_FOC0		7		//Force Output Compare
#define TCCR0_WGM00		6		//Wave Generation Mode
#define TCCR0_COM01		5		//Compare Match Output Mode
#define TCCR0_COM00		4		//Compare Match Output Mode
#define TCCR0_WGM01		3		//Wave Generation Mode
#define TCCR0_CS02		2		//Clock Select
#define TCCR0_CS01		1		//Clock Select
#define TCCR0_CS00		0		//Clock Select

#define TCNT0 	*((volatile uint8*) 0x52)		//Timer_Counter Register

#define OCR0  	*((volatile uint8*) 0x5C)		//Output Compare Register

/*******************************/

/*******Timer 1 registers*******/

#define TCCR1A	*((volatile uint8*) 0x4F)		//Timer_Counter1 Control Register A
#define TCCR1A_COM1A1	7		//Compare Output Mode for Channel A
#define TCCR1A_COM1A0	6		//Compare Output Mode for Channel A
#define TCCR1A_COM1B1	5		//Compare Output Mode for Channel B
#define TCCR1A_COM1B0	4		//Compare Output Mode for Channel B
#define TCCR1A_FOC1A	3		//Force Output Compare for Channel A
#define TCCR1A_FOC1B	2		//Force Output Compare for Channel B
#define TCCR1A_WGM11	1		//Waveform Generation Mode
#define TCCR1A_WGM10	0		//Waveform Generation Mode

#define TCCR1B	*((volatile uint8*) 0x4E)		//Timer_Counter1 Control Register B
#define TCCR1B_ICNC1	7		//Input Capture Noise Canceler
#define TCCR1B_ICES1	6		//Input Capture Edge Select
//-------------->bit number 5 is reserved
#define TCCR1B_WGM13	4		//Waveform Generation Mode
#define TCCR1B_WGM12	3		//Waveform Generation Mode
#define TCCR1B_CS12		2		// Clock Select
#define TCCR1B_CS11		1		// Clock Select
#define TCCR1B_CS10		0		// Clock Select

#define TCNT1H	*((volatile uint8*) 0x4D)		//Timer_Counter1 Register high
#define TCNT1L	*((volatile uint8*) 0x4C)		//Timer_Counter1 Register low

#define TCNT1 	*((volatile uint16*) 0x4C)		//Timer_Counter1 Register

#define OCR1AH	*((volatile uint8*) 0x4B)		//Output Compare Register 1 A HIGH
#define OCR1AL	*((volatile uint8*) 0x4A)		//Output Compare Register 1 A LOW

#define OCR1BH 	*((volatile uint8*) 0x49)		//Timer_Counter1 – Output Compare Register B High
#define OCR1BL 	*((volatile uint8*) 0x48)		//Timer_Counter1 – Output Compare Register B Low

#define ICR1H 	*((volatile uint8*) 0x47)		// Timer_Counter1 – Input Capture Register High
#define ICR1L 	*((volatile uint8*) 0x46)		// Timer_Counter1 – Input Capture Register Low

#define ICR1	*((volatile uint16*) 0x46)
#define OCR1A	*((volatile uint16*) 0x4A)


/*******************************/

/*******Timer 2 registers*******/

#define TCCR2	*((volatile uint8*) 0x45)		//Timer_Counter2 Control Register
#define TCCR2_FOC2		7		// Force Output Compare
#define TCCR2_WGM20		6		//Waveform Generation Mode
#define TCCR2_COM21		5		//Compare Match Output Mode
#define TCCR2_COM20		4		//Compare Match Output Mode
#define TCCR2_WGM21		3		//Waveform Generation Mode
#define TCCR2_CS22		2		//Clock Select
#define TCCR2_CS21		1		//Clock Select
#define TCCR2_CS20		0		//Clock Select

#define TCNT2	*((volatile uint8*) 0x44)		//Timer_Counter2 Register

#define OCR2	*((volatile uint8*) 0x43)		//Output Compare Register

#define ASSR	*((volatile uint8*) 0x42)		//Asynchronous Status Register
#define ASSR_AS2		3		//Asynchronous Timer_Counter2
#define ASSR_TCN2UB		2		//Timer_Counter2 Update Busy
#define ASSR_OCR2UB		1		//Output Compare Register2 Update Busy
#define ASSR_TCR2UB		0		//Timer_Counter Control Register2 Update Busy

#define SFIOR	*((volatile uint8*) 0x50)		//Special Function IO Register
#define SFIOR_PSR2		1		// Prescaler Reset Timer_Counter2

/*******************************/
#endif
