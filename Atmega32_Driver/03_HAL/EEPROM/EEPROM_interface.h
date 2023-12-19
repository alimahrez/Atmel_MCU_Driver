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

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#define ERROR 	0
#define SUCCESS 1


void EEPROM_Init();
U8 EEPROM_WriteByte(U16 Addr,U8 data);
U8 EEPROM_ReadByte(U16 Addr,U8 *data);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
