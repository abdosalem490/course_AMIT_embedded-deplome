/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 30/10/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX			(*((volatile uint8*) 0x27))		/*ADC multiplexer selection register*/
#define ADMUX_REFS1		7								/*REferenec selection bit 1*/
#define ADMUX_REFS0		6								/*REferenec selection bit 0*/
#define ADMUX_ADLAR		5								/*left adjust result*/

#define ADCSRA			(*((volatile uint8*) 0x26))		/*ADC control and status register A*/
#define ADCSRA_ADEN		7								/*ADC enable*/
#define ADCSRA_ADSC		6								/*ADC start conversion*/
#define ADCSRA_ADATE	5								/*Auto trigger enable*/
#define ADCSRA_ADIF		4								/*ADC interrupt flag*/
#define ADCSRA_ADIE		3								/*ADC interrupt enable*/


#define ADCH			(*((volatile uint8*) 0x25))		/*Data high register*/
#define ADCL			(*((volatile uint8*) 0x24))		/*Data low register*/

#define ADC				(*((volatile uint16*) 0x24))		/*Data all register in right adjust mode*/


#endif
