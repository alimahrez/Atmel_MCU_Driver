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

#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_

void SevenSeg_vidinit();
void SevenSeg_1_Control(Bool );
void SevenSeg_2_Control(Bool );
void SevenSeg_3_Control(Bool );
void SevenSeg_4_Control(Bool );
void SevenSeg_vidDisplay(Seg_Number );
void SevenSeg_vidCountUp(U8 );
void SevenSeg_vidConutDown(U8 );

#endif /* SEVENSEG_INTERFACE_H_ */
