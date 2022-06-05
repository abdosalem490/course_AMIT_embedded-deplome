/*********************************************************************/
/*********************************************************************/
/**********************		Author: Amgad Samir			**************/
/**********************		Date: 29/10/2021			**************/
/**********************		layer: MCAL					**************/
/**********************		Version: 1.00				**************/
/*********************************************************************/
/*********************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Configure your INT0 sense, options: 1- LOW_LEVEL	
									  2- ON_CHANGE
									  3- FALLING_EDGE	
									  4- RISING_EDGE	
															*/
#define EXTI_u8_INT0_SENSE_CONTROL		RISING_EDGE



/*Configure your INT1 sense, options: 1- LOW_LEVEL	
									  2- ON_CHANGE
									  3- FALLING_EDGE	
									  4- RISING_EDGE	
															*/
#define EXTI_u8_INT1_SENSE_CONTROL		RISING_EDGE



/*Configure your INT2 sense, options: 1- FALLING_EDGE	
									  2- RISING_EDGE	
															*/
#define EXTI_u8_INT2_SENSE_CONTROL		RISING_EDGE


/*Configure INT0 Initial state, options: 1- ENABLED	
										 2- DISABLED		*/
#define EXTI_u8_INT0_INIT_STATE			ENABLED

/*Configure INT1 Initial state, options: 1- ENABLED	
										 2- DISABLED		*/
#define EXTI_u8_INT1_INIT_STATE			DISABLED

/*Configure INT2 Initial state, options: 1- ENABLED	
										 2- DISABLED		*/
#define EXTI_u8_INT2_INIT_STATE			DISABLED


#endif
