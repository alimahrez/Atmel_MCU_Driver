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

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_


#define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_W_ACK  0x18
#define I2C_MT_SLA_R_ACK  0x40
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_DATA_NACK  0x58



void I2C_vidInit();
void I2C_vidStart();
void I2C_vidStop();
void I2C_vidWrite(U8 data);
U8 I2C_u8_ACK();
U8 I2C_u8_NO_ACK();
U8 I2C_u8Status();



#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
