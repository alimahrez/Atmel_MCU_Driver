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

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define	FROM_AVRF_PIN			0
#define	FROM_VCC_PIN			1
#define	INTERNAL_2_56_VOLTAGE 	3


void ADC_vidInit(void);
void ADC_vidGetValue(channel,F32*);






#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
