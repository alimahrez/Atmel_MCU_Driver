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

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/*#############################################################################################*/

// Select the type of KEYPAD that you Used
// 1- KEYPAD_4X3
// 2- KEYPAD_4X4

#define     KEYBAD_TYPE     KEYPAD_4X4

/*#############################################################################################*/

//  Connfigure The connection 
//  In case you use the 4*3 KEYPAD, the KEY_COL_3 Is ignored by the software

#define 	KEY_ROW_PORT	PB
#define 	KEY_COL_PORT	PD

#define 	KEY_ROW_0		pin4
#define 	KEY_ROW_1		pin5
#define 	KEY_ROW_2		pin6
#define 	KEY_ROW_3		pin7

#define 	KEY_COL_0		pin2
#define 	KEY_COL_1		pin3
#define 	KEY_COL_2		pin4
#define 	KEY_COL_3		pin5


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
