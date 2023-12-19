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

#ifndef HAL_RELAY_RELAY_CONFIG_H_
#define HAL_RELAY_RELAY_CONFIG_H_

/*
        For Atmega 32, Select the port that is connect to the Relay and Pin
                * (PA,pin0-7) For Port A
                * (PB,pin0-7) For Port B
                * (PC,pin0-7) For Port C
                * (PD,pin0-7) For Port D
        For more than one relay ENABLE OR DISABLE the Relay Channel
*/

#define RELAY_0_STATE                   ENABLE
#define RELAY_0_CONNE			        PC,pin4

#define RELAY_1_STATE                   DISABLE
#define RELAY_1_CONNE			        PC,pin5

#define RELAY_2_STATE                   DISABLE
#define RELAY_2_CONNE			        PC,pin6

#define RELAY_3_STATE                   DISABLE
#define RELAY_3_CONNE			        PC,pin7

#define RELAY_4_STATE                   DISABLE
#define RELAY_4_CONNE			        PB,pin0

#define RELAY_5_STATE                   DISABLE
#define RELAY_5_CONNE			        PB,pin1

#define RELAY_6_STATE                   DISABLE
#define RELAY_6_CONNE			        PB,pin2

#define RELAY_7_STATE                   DISABLE
#define RELAY_7_CONNE			        PB,pin3


#endif /* HAL_RELAY_RELAY_CONFIG_H_ */
