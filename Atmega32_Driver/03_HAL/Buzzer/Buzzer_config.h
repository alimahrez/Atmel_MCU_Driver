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

#ifndef HAL_BUZZER_BUZZER_CONFIG_H_
#define HAL_BUZZER_BUZZER_CONFIG_H_

/*
        For Atmega 32, Select the port that is connect to the buzzer and Pin
                * (PA,pin0-7) For Port A
                * (PB,pin0-7) For Port B
                * (PC,pin0-7) For Port C
                * (PD,pin0-7) For Port D
*/

#define BUZZER			PC,pin5

#endif /* HAL_BUZZER_BUZZER_CONFIG_H_ */
