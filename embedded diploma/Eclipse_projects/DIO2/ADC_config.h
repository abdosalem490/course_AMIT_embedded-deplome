/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 30/10/2021	********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*Choose your reference voltage options are : 1- AREF
 * 											  2- AVCC
 * 											  3- INTERNAL_2560mV*/
#define ADC_u8_REF_SELECTION		AVCC

/*Choose your resolution options are : 		  1- EIGHT_BIT
 * 											  2- TEN_BIT*/
#define ADC_u8_RESOLUTION			EIGHT_BIT


/*Choose your ADC initial state options are : 1- ENABLED
 * 											  2- DISABLED*/
#define ADC_u8_ENABLE_INIT_STATE	ENABLED

/*Choose your ADC prescalar division factor, options are : 1- DIVIDE_BY_2
 * 											 			   2- DIVIDE_BY_4
 * 											  			   3- DIVIDE_BY_8
 * 											  			   4- DIVIDE_BY_16
 * 											  			   5- DIVIDE_BY_32
 * 											  			   6- DIVIDE_BY_64
 * 											  			   7- DIVIDE_BY_128*/
#define ADC_u8_PRESCALER			DIVIDE_BY_2

#define ADC_u32_TIMEOUT_VALUE			500UL

#endif
