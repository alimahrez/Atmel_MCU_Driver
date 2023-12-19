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
################################## Register File Address #########################################
##################################################################################################*/

#ifndef _ATMEGA_32_REGISTERS_H_
#define _ATMEGA_32_REGISTERS_H_

#define AddressReferance    0x20

#define SREG_REG                 (*((volatile U8 *const)(AddressReferance + 0x3F)))

#define SPH_REG                  (*((volatile U8 *const)(AddressReferance + 0x3E)))
#define SPL_REG                  (*((volatile U8 *const)(AddressReferance + 0x3D)))
#define OCR0_REG                 (*((volatile U8 *const)(AddressReferance + 0x3C)))
#define GICR_REG                 (*((volatile U8 *const)(AddressReferance + 0x3B)))
#define GIFR_REG                 (*((volatile U8 *const)(AddressReferance + 0x3A)))
#define TIMSK_REG                (*((volatile U8 *const)(AddressReferance + 0x39)))
#define TIFR_REG                 (*((volatile U8 *const)(AddressReferance + 0x38)))
#define SPMCR_REG                (*((volatile U8 *const)(AddressReferance + 0x37)))
#define TWCR_REG                 (*((volatile U8 *const)(AddressReferance + 0x36)))
#define MCUCR_REG                (*((volatile U8 *const)(AddressReferance + 0x35)))
#define MCUCSR_REG               (*((volatile U8 *const)(AddressReferance + 0x34)))
#define TCCR0_REG                (*((volatile U8 *const)(AddressReferance + 0x33)))
#define TCNT0_REG                (*((volatile U8 *const)(AddressReferance + 0x32)))

#define OCSCCAL_REG              (*((volatile U8 *const)(AddressReferance + 0x31)))
#define OCDR_REG                 (*((volatile U8 *const)(AddressReferance + 0x31)))

#define SFIOR_REG                (*((volatile U8 *const)(AddressReferance + 0x30)))

#define TCCR1A_REG               (*((volatile U8 *const)(AddressReferance + 0x2F)))
#define TCCR1B_REG               (*((volatile U8 *const)(AddressReferance + 0x2E)))
#define TCNT1H_REG               (*((volatile U8 *const)(AddressReferance + 0x2D)))
#define TCNT1L_REG               (*((volatile U8 *const)(AddressReferance + 0x2C)))
#define OCR1AH_REG               (*((volatile U8 *const)(AddressReferance + 0x2B)))
#define OCR1AL_REG               (*((volatile U8 *const)(AddressReferance + 0x2A)))
#define OCR1BH_REG               (*((volatile U8 *const)(AddressReferance + 0x29)))
#define OCR1BL_REG               (*((volatile U8 *const)(AddressReferance + 0x28)))
#define ICR1H_REG                (*((volatile U8 *const)(AddressReferance + 0x27)))
#define ICR1L_REG                (*((volatile U8 *const)(AddressReferance + 0x26)))
#define TCCR2_REG                (*((volatile U8 *const)(AddressReferance + 0x25)))
#define TCNT2_REG                (*((volatile U8 *const)(AddressReferance + 0x24)))
#define OCR2_REG                 (*((volatile U8 *const)(AddressReferance + 0x23)))
#define ASSR_REG                 (*((volatile U8 *const)(AddressReferance + 0x22)))
#define WDTCR_REG                (*((volatile U8 *const)(AddressReferance + 0x21)))

#define UBRRH_REG                (*((volatile U8 *const)(AddressReferance + 0x20)))
#define UCSRC_REG                (*((volatile U8 *const)(AddressReferance + 0x20)))

#define EEARH_REG                (*((volatile U8 *const)(AddressReferance + 0x1F)))
#define EEARL_REG                (*((volatile U8 *const)(AddressReferance + 0x1E)))
#define EEDR_REG                 (*((volatile U8 *const)(AddressReferance + 0x1D)))
#define EECR_REG                 (*((volatile U8 *const)(AddressReferance + 0x1C)))
#define PORTA_REG                (*((volatile U8 *const)(AddressReferance + 0x1B)))
#define DDRA_REG                 (*((volatile U8 *const)(AddressReferance + 0x1A)))
#define PINA_REG                 (*((volatile U8 *const)(AddressReferance + 0x19)))
#define PORTB_REG                (*((volatile U8 *const)(AddressReferance + 0x18)))
#define DDRB_REG                 (*((volatile U8 *const)(AddressReferance + 0x17)))
#define PINB_REG                 (*((volatile U8 *const)(AddressReferance + 0x16)))
#define PORTC_REG                (*((volatile U8 *const)(AddressReferance + 0x15)))
#define DDRC_REG                 (*((volatile U8 *const)(AddressReferance + 0x14)))
#define PINC_REG                 (*((volatile U8 *const)(AddressReferance + 0x13)))
#define PORTD_REG                (*((volatile U8 *const)(AddressReferance + 0x12)))
#define DDRD_REG                 (*((volatile U8 *const)(AddressReferance + 0x11)))
#define PIND_REG                 (*((volatile U8 *const)(AddressReferance + 0x10)))

#define SPDR_REG                 (*((volatile U8 *const)(AddressReferance + 0x0F)))
#define SPSR_REG                 (*((volatile U8 *const)(AddressReferance + 0x0E)))
#define SPCR_REG                 (*((volatile U8 *const)(AddressReferance + 0x0D)))
#define UDR_REG                  (*((volatile U8 *const)(AddressReferance + 0x0C)))
#define UCSRA_REG                (*((volatile U8 *const)(AddressReferance + 0x0B)))
#define UCSRB_REG                (*((volatile U8 *const)(AddressReferance + 0x0A)))

#define UBRRL_REG				 (*((volatile U8 *const)(AddressReferance + 0x09)))
#define ACSR_REG                 (*((volatile U8 *const)(AddressReferance + 0x08)))
#define ADMUX_REG                (*((volatile U8 *const)(AddressReferance + 0x07)))
#define ADCSRA_REG               (*((volatile U8 *const)(AddressReferance + 0x06)))
#define ADCH_REG                 (*((volatile U8 *const)(AddressReferance + 0x05)))
#define ADCL_REG                 (*((volatile U8 *const)(AddressReferance + 0x04)))
#define TWDR_REG                 (*((volatile U8 *const)(AddressReferance + 0x03)))
#define TWAR_REG                 (*((volatile U8 *const)(AddressReferance + 0x02)))
#define TWSR_REG                 (*((volatile U8 *const)(AddressReferance + 0x01)))
#define TWBR_REG                 (*((volatile U8 *const)(AddressReferance + 0x00)))


/*#################################################################################################
##################################### Register Bits Name ##########################################
##################################################################################################*/

/*###################################### SPEG Register ###########################################*/
#define I               7
#define T               6
#define H               5
#define S               4
#define V               3
#define N               2
#define Z               1
#define C               0

/*###################################### SPL Register ############################################*/

#define SPL11           11
#define SPL10           10
#define SPL9            9
#define SPL8            8

#define SPL7            7
#define SPL6            6
#define SPL5            5
#define SPL4            4
#define SPL3            3
#define SPL2            2
#define SPL1            1
#define SPL0            0

/*#################################### GICR Register ############################################*/
#define INT1            7
#define INT0            6
#define INT2            5
#define IVSEL           1
#define IVCE            0

/*#################################### GIFR Register #############################################*/
#define INTF1           7
#define INTF0           6
#define INTF2           5

/*################################### TIMSK Register #############################################*/
#define OCIE2           7
#define TOIE2           6
#define TICIE1          5
#define OCIE1A          4
#define OCIE1B          3
#define TOIE1           2
#define OCIE0           1
#define TOIE0           0

/*################################### TIFR Register ##############################################*/
#define OCF2            7
#define TOV2            6
#define ICF1            5
#define OCF1A           4
#define OCF1B           3
#define TOV1            2
#define OCF0            1
#define TOV0            0

/*################################### SPMCR Register ##############################################*/
#define SPMIE           7
#define RWWSB           6
#define RWWSRE          4
#define BLBSET          3
#define PGWRT           2
#define PGERS           1
#define SPMEN           0

/*################################### TWCR Register ##############################################*/
#define TWINT           7
#define TWEA            6 
#define TWSTA           5
#define TWSTO           4
#define TWWC            3
#define TWEN            2
#define TWIE            0

/*################################### MCUCR Register ##############################################*/
#define SE              7
#define SM2             6
#define SM1             5
#define SM0             4
#define ISC11           3
#define ISC10           2
#define ISC01           1
#define ISC00           0

/*################################### MCUCSR Register ##############################################*/
#define JTD             7
#define ISC2            6
#define JTRF            4
#define WDRF            3        
#define BORF            2
#define EXTRF           1
#define PORF            0

/*################################### TCCR0 Register ##############################################*/
#define FOC0            7
#define WGM00           6
#define COM01           5
#define COM00           4
#define WGM01           3
#define CS02           	2
#define CS01           	1
#define CS00           	0

/*################################### SFIOR Register ##############################################*/
#define ADTS2           7
#define ADTS1           6
#define ADTS0           5
#define ACME           	3
#define PUD           	2
#define PSR2           	1
#define PSR10          	0

/*################################### TCCR1A Register ##############################################*/
#define COM1A1          7
#define COM1A0          6
#define COM1B1          5
#define COM1B0          4
#define FOC1A           3
#define FOC1B           2
#define WGM11           1
#define WGM10           0

/*################################### TCCR1B Register ##############################################*/
#define ICNC1          	7
#define ICES1          	6
#define WGM13          	4
#define WGM12           3
#define CS12           	2
#define CS11           	1
#define CS10           	0

/*################################### TCCR2 Register ##############################################*/
#define FOC2          	7
#define WGM20          	6
#define COM21          	5
#define COM20          	4
#define WGM21           3
#define CS22           	2
#define CS21           	1
#define CS20           	0

/*################################### ASSR Register ##############################################*/
#define AS2           	3
#define TCN2UB          2
#define OCR2UB          1
#define TCR2UB          0

/*################################### WDTCR Register ##############################################*/
#define WDTOE          	4
#define WDE           	3
#define WDP2           	2
#define WDP1           	1
#define WDP0           	0

/*################################### UCSRC / UBRRH Register ##############################################*/
#define URSEL          	7
#define UMSEL          	6
#define UPM1          	5
#define UPM0          	4
#define USBS           	3
#define UCSZ1           2
#define UCSZ0           1
#define UCPOL           0

/*################################### EEARH Register ##############################################*/
#define EEAR9           1
#define EEAR8           0

/*################################### EECR Register ##############################################*/
#define EERIE           3
#define EEMWE           2
#define EEWE           	1
#define EERE           	0

/*################################### SPSR Register ##############################################*/
#define SPIF          	7
#define WCOL          	6
#define SPI2X           0

/*################################### SPCR Register ##############################################*/
#define SPIE          	7
#define SPE          	6
#define DORD          	5
#define MSTR          	4
#define CPOL           	3
#define CPHA           	2
#define SPR1           	1
#define SPR0           	0

/*################################### UCSRA Register ##############################################*/
#define RXC          	7
#define TXC          	6
#define UDRE          	5
#define FE          	4
#define DOR           	3
#define PE           	2
#define U2X           	1
#define MPCM           	0

/*################################### UCSRB Register ##############################################*/
#define RXCIE          	7
#define TXCIE          	6
#define UDRIE          	5
#define RXEN          	4
#define TXEN           	3
#define UCSZ2           2
#define RXB8           	1
#define TXB8           	0

/*################################### ACSR Register ##############################################*/
#define ACD          	7
#define ACBG          	6
#define ACO          	5
#define ACI          	4
#define ACIE           	3
#define ACIC           	2
#define ACIS1           1
#define ACIS0           0

/*################################### ADMUX Register ##############################################*/
#define REFS1          	7
#define REFS0          	6
#define ADLAR          	5
#define MUX4          	4
#define MUX3           	3
#define MUX2           	2
#define MUX1           	1
#define MUX0           	0

/*################################### ADCSRA Register ##############################################*/
#define ADEN          	7
#define ADSC          	6
#define ADATE          	5
#define ADIF          	4
#define ADIE           	3
#define ADPS2           2
#define ADPS1           1
#define ADPS0           0

/*################################### TWAR Register ##############################################*/
#define TWA6          	7
#define TWA5          	6
#define TWA4          	5
#define TWA3          	4
#define TWA2           	3
#define TWA1           	2
#define TWA0           	1
#define TWGCE          	0

/*################################### TWSR Register ##############################################*/
#define TWS7          	7
#define TWS6          	6
#define TWS5          	5
#define TWS4          	4
#define TWS3           	3
#define TWPS1           1
#define TWPS0           0







#endif /*_ATMEGA_32_REGISTERS_H_*/
