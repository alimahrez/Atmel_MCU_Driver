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

#ifndef LIB_INTERRUPT_H_
#define LIB_INTERRUPT_H_

#define EXT_INT_0				__vector_1	//	External Interrupt Request 0
#define EXT_INT_1				__vector_2	// External Interrupt Request 1
#define EXT_INT_2				__vector_3	// External Interrupt Request 2
//#define TIMER2_COMP			__vector_4	// Timer/Counter2 Compare Match
//#define TIMER2_OVF			__vector_5	// Timer/Counter2 Overflow
//#define TIMER1_CAPT			__vector_6	// Timer/Counter1 Capture Event
//#define TIMER1_COMP_A			__vector_7	// Timer/Counter1 Compare Match A
//#define TIMER1_COMP_B			__vector_8	// Timer/Counter1 Compare Match B
//#define TIMER1_OVF			__vector_9	// Timer/Counter1 Overflow
//#define TIMER0_COMP			__vector_10	// Timer/Counter0 Compare Match A
//#define TIMER0_OVF			__vector_11	// Timer/Counter0 Overflow
//#define SPI_STC				__vector_12	// Serial Transfer Complete
//#define USART_RXC				__vector_13	// USART, Rx Complete
//#define USART_UDRE			__vector_14	// USART Data Register Empty
//#define USART_TXC				__vector_15	// USART, Tx Complete
//#define ADC					__vector_16	// ADC Conversion Complete
//#define EE_RDY				__vector_17	// EEPROM Ready
//#define ANA_COMP				__vector_18	// Analog Comparator
//#define TWI					__vector_19	// 2-wire Serial Interface
//#define SPM_RDY				__vector_20	// Store Program Memory Ready


# define setGeneralInterrupt()  __asm__ __volatile__ ("sei" ::: "memory");
# define clearGeneralInterrupt()  __asm__ __volatile__ ("cli" ::: "memory");

#  define ISR(vector)            \
    void vector (void) __attribute__ ((signal,used)) ; \
    void vector (void)


#endif /* LIB_INTERRUPT_H_ */
