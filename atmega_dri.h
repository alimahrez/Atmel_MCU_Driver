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
#ifndef ATMEGA_DRI_H_
#define ATMEGA_DRI_H_

/*
 ***********  LIB APIs *****************
 */
#include "Atmega32_Driver/02_LIB/stdtypes.h"
#include "Atmega32_Driver/02_LIB/bitmath.h"
#include "Atmega32_Driver/02_LIB/atmega32_Registers.h"

/*
 ***********  MCAL APIs *****************
 */
#include "Atmega32_Driver/04_MCAL/DIO/DIO_interface.h"
#include "Atmega32_Driver/04_MCAL/Timer/Timer_interface.h"
#include "Atmega32_Driver/04_MCAL/ADC/ADC_interface.h"
#include "Atmega32_Driver/04_MCAL/EXT_INT/EXTINT_interface.h"
#include "Atmega32_Driver/04_MCAL/UART/UART_interface.h"
#include "Atmega32_Driver/04_MCAL/I2C/I2C_interface.h"

/*
 ***********  HAL APIs *****************
 */
#include "Atmega32_Driver/03_HAL/Buzzer/Buzzer_interface.h"
#include "Atmega32_Driver/03_HAL/Relay/Relay_interface.h"
#include "Atmega32_Driver/03_HAL/LCD/LCD_interface.h"
#include "Atmega32_Driver/03_HAL/Keypad/Keypad_interface.h"
#include "Atmega32_Driver/03_HAL/Seven Segment/SevenSeg_interface.h"
#include "Atmega32_Driver/03_HAL/EEPROM/EEPROM_interface.h"

#endif /* ATMEGA_DRI_H_ */
