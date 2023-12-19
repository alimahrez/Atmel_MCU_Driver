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

#ifndef _BITMATH_H_
#define _BITMATH_H_

/*********************************************************************************************************/
/* 			      		  			    Macros for Bit Manipulation							             */
/*********************************************************************************************************/

#define MASK_BIT(BIT)                               ((U8)1 << (BIT))
#define SET_BIT(REG, BIT)                           (REG |= MASK_BIT(BIT))
#define CLR_BIT(REG, BIT)                           (REG &= ~MASK_BIT(BIT))
#define TOG_BIT(REG, BIT)                           (REG ^= MASK_BIT(BIT))
#define GET_BIT(REG, BIT)                           ((REG & (1 << BIT)) >> BIT)
#define UPDATE_BIT(REG, BIT, VALUE)                 ((VALUE) ? SET_BIT(REG, BIT) : CLR_BIT(REG, BIT))

#define GET_BIT_STATUS(REG, BIT)                    (((x) & (MASK_BIT(BIT))) != 0u)
#define IS_BIT_SET(REG, BIT)                        (((x) & (MASK_BIT(BIT))) != 0u)
#define IS_BIT_CLR(REG, BIT)                        (((x) & (MASK_BIT(BIT))) == 0u)
#define SET_BYTE(REG, VALUE)                        (REG = VALUE)

#define CLR_5_BITS(REG)

/*********************************************************************************************************/
/* 			      		  			Macros for important calculation				                     */
/*********************************************************************************************************/

#define MAX(N1, N2)                                 (((N1) > (N2)) ? (N1) : (N2))
#define MIN(N1, N2)                                 (((N1) < (N2)) ? (N1) : (N2))

#define SWAP(A, B)                                  (A ^= B ^= A ^= B)
#define ABSOLUTE(N)                                 (((N) < 0) ? -(N) : (N))

#define GET_MOD_IN_8_BIT(dividend, divisor)         ((u8)(dividend - (divisor * (u8)(dividend / divisor))))
#define GET_MOD_IN_16_BIT(dividend, divisor)        ((u16)(dividend - (divisor * (u16)(dividend / divisor))))
#define GET_MOD_IN_32_BIT(dividend, divisor)        ((u32)(dividend - (divisor * (u32)(dividend / divisor))))

#define GET_DEC_PART(NUM)							((U16) NUM)



/*********************************************************************************************************/
/* 			      	           Macros for Dec , Hec And Ascii conversion    		                     */
/*********************************************************************************************************/

#define DEC_2_ASCII(DEC)                            ((DEC) + 0x30)
#define ASCII_2_DEC(ASC)                            ((ASC)-0x30)
#define HEX_2_ASCII(HEX)                            (((HEX) > 0x09) ? ((HEX) + 0x37) : ((HEX) + 0x30))
#define ASCII_2_HEX(ASC)                            (((ASC) > 0x39) ? ((ASC)-0x37) : ((ASC)-0x30))

/*********************************************************************************************************/
/* 			      		  		Macros to extract the Nibbles And BYTE				                     */
/*********************************************************************************************************/
/*          1 Nibble = 4 Bit 	                                                                         */
/*          1 BYTE   = 8 Bit                                                                             */
/*********************************************************************************************************/

#define Extract_Nibble_0_to_3(VAR)                  ((u8)((VAR)&0x0Fu))
#define Extract_Nibble_4_to_7(VAR)                  ((u8)(((VAR) >> 4) & 0x0Fu))
#define Extract_Nibble_8_to_11(VAR)                 ((u8)(((VAR) >> 8) & 0x0Fu))
#define Extract_Nibble_12_to_15(VAR)                ((u8)(((VAR) >> 12) & 0x0Fu))
#define Extract_Nibble_16_to_19(VAR)                ((u8)(((VAR) >> 16) & 0x0Fu))
#define Extract_Nibble_20_to_23(VAR)                ((u8)(((VAR) >> 20) & 0x0Fu))
#define Extract_Nibble_24_to_27(VAR)                ((u8)(((VAR) >> 24) & 0x0Fu))
#define Extract_Nibble_28_to_31(VAR)                ((u8)(((VAR) >> 28) & 0x0Fu))

#define Extract_Byte_0to7(VAR)                      ((u8)((VAR)&0xFFu))
#define Extract_Byte_8to15(VAR)                     ((u8)(((VAR) >> 8) & 0xFFu))
#define Extract_Byte_16to27(VAR)                    ((u8)(((VAR) >> 16) & 0xFFu))
#define Extract_Byte_28to31(VAR)                    ((u8)(((VAR) >> 28) & 0xFFu))




#endif /* _BIT_MATH_H_ */
