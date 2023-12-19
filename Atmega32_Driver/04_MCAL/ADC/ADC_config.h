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
##################################################################################################*/

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*
 	 ****** ADC Voltage Reference Configuration *******
 	 ****** 1- FROM_AVRF_PIN
 	 ****** 2- FROM_VCC_PIN
 	 ****** 3- INTERNAL_2_56_VOLTAGE
*/
#define	ANALOG_VOLTAGE_REFERENCE	FROM_VCC_PIN


/*
 	 ******  Voltage Reference Value *******
 	 ******	1- FROM_AVRF_PIN_Based on your applied Voltage on AVRF Pin (3.0f)
 	 ****** 2- FROM_VCC_PIN_Based on Microcontroler  VCC operation (5.0f volt)
 	 ****** 3- INTERNAL_2_56_VOLTAGE - Set Value to be 2.56f
*/

#define  VOLT_REF_VALUE			5.0f

/*
 	 ****** ADC Channels Used *******
 	 ****** ENABLE
 	 ****** DISABLE
*/

#define	CHANNEL_0			ENABLE
#define	CHANNEL_1			DISABLE
#define	CHANNEL_2			DISABLE
#define	CHANNEL_3			DISABLE
#define	CHANNEL_4			DISABLE
#define	CHANNEL_5			DISABLE
#define	CHANNEL_6			DISABLE
#define	CHANNEL_7			DISABLE
#define	CHANNEL_8			DISABLE



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
