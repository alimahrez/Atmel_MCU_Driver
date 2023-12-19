/*###############################################################################################
####################################### VECCHIATRON #############################################
#################################################################################################
		$ Title             :   Atmega32 Registers
		$ Author            :   A.Ali Mahrez
		$ Author contact    :   a.alimahrez@gmx.com
		$ Target            :   AVR Atmega32
		$ Date              :   Oct 25th, 2022
		$ Version           :   V005.22
		$ Description       :   None
		$ Notes             :   None
##################################################################################################
##################################################################################################
##################################################################################################*/

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/*
	Configuer Puls Width Modultion Signal type
		1- INVERTING_PWM
		2- NON_INVERTING_PWM
 */

#define PWM_OC0_MODE	NON_INVERTING_PWM		// For PWM on Port B Pin 3
#define PWM_OC2_MODE	NON_INVERTING_PWM		// For PWM on Port D pin 7



#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
