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

#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

void Relay_VidInit();
void Relay_VidTurnOn(Relay_No);
void Relay_VidTurnOff(Relay_No);
void Relay_VidOnDelay(Relay_No , U16 );
void Relay_VidOffDelay(Relay_No , U16 );


#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */
