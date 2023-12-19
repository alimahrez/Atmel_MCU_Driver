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

#ifndef MCAL_EXT_INT_EXTINT_INTERFACE_H_
#define MCAL_EXT_INT_EXTINT_INTERFACE_H_

/* Modes */
#define LOW_LEVEL		1
#define LOGICAL_CHANGE	2
#define FALLING_EDGE	3
#define RISING_EDGE		4


void EXTINT_vidInit( U16, U8 );
void EXTINT_vidSetExt0_Callback(void (*Callback)(void));
void EXTINT_vidSetExt1_Callback(void (*Callback)(void));

#endif /* MCAL_EXT_INT_EXTINT_INTERFACE_H_ */
