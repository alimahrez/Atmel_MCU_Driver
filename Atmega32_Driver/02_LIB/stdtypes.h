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

#ifndef STDTYPES_H_
#define STDTYPES_H_

#ifndef NULL
#define NULL                0
#endif

#define ENABLE				1
#define DISABLE				0


#define U8_MAX              255
#define U8_MIN              0

#define U16_MAX             65535
#define U16_MIN             0

#define U32_MAX             4294967296
#define U32_MIN             0

#define S8_MAX              127
#define S8_MIN              -128

#define S16_MAX             32767
#define S16_MIN             -32768

#define S32_MAX             2147483647
#define S32_MIN             -2147483648

typedef unsigned char 			U8;
typedef unsigned short int 		U16;
typedef unsigned long int 		U32;

typedef signed char 			S8;
typedef signed short int 		S16;
typedef signed long int 		S32;

typedef float 					F32;

typedef enum 
{
    Off,
    On
}TurnState;


typedef enum
{
    LOW,
    HIGH
}PinState;

typedef enum
{
    False,
    True
}Bool;

typedef enum
{
    IS_FALSE,
    IS_TRUE
} ResultType;

typedef enum
{
    IS_FAILED,
    IS_SUCCESS,
    IS_BUSY,
    IS_TIMEOUT
} StatusAsk;


typedef enum
{
    FAILED,
    SUCCESS,
    BUSY,
    TIMEOUT
} StatusType;

typedef enum
{
    BINARY_Sys = 2,
    OCTA_Sys = 8,
    DECIMAL_Sys = 10,
    HEX_Sys = 16
} NumericSystemType;

typedef enum
{
    INPUT,
    OUTPUT
} Port_Direction;

typedef enum
{
    PA,
    PB,
    PC,
    PD
}Port_Name;

typedef enum
{
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
}Pin_Number;

typedef enum
{
    N0,
    N1,
    N2,
    N3,
    N4,
    N5,
    N6,
    N7,
	N8,
	N9
}Seg_Number;


typedef enum
{
    INTERNAL_PULLUP,
	EXTERNAL_PULLUP,
	EXTERNAL_PULLDONE
}Pull_State;


typedef enum
{
	ch0,
	ch1,
	ch2,
	ch3,
	ch4,
	ch5,
	ch6,
	ch7
}channel;

typedef enum
{
    R0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7
} Relay_No;

#endif /* STDTYPES_H_ */
