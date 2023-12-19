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

#include "../../02_LIB/stdtypes.h"
#include "../../02_LIB/bitmath.h"
#include "../../02_LIB/atmega32_Registers.h"
#include "../DIO/DIO_interface.h"
#include "../Timer/Timer_interface.h"
#include "ADC_interface.h"
#include "ADC_config.h"

void static ADC_vidChannelSelect(channel AX)
{
	switch (AX)
	{
		case ch0 :
			CLR_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch1 :
			SET_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch2 :
			CLR_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch3 :
			SET_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch4 :
			CLR_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch5 :
			SET_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch6 :
			CLR_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;

		case ch7 :
			SET_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			TIM_vidDelay_us(10);
		break;
	}
}

void ADC_vidInit()
 {
	#if	(ANALOG_VOLTAGE_REFERENCE == FROM_AVRF_PIN)

		CLR_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
		CLR_BIT(ADMUX_REG,ADLAR);

	#elif (ANALOG_VOLTAGE_REFERENCE == FROM_VCC_PIN)

		SET_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
		CLR_BIT(ADMUX_REG,ADLAR);

	#else
		SET_BIT(ADMUX_REG,REFS0);
		SET_BIT(ADMUX_REG,REFS1);

	#endif

	#if	(CHANNEL_0 == ENABLE)
		DIO_vidPinDirection(PA,pin0 ,INPUT);
	#endif
	#if	(CHANNEL_1 == ENABLE)
		DIO_PinDirection(PA,pin1 ,INPUT);
	#endif
	#if	(CHANNEL_2 == ENABLE)
		DIO_PinDirection(PA,pin2 ,INPUT);
	#endif
	#if	(CHANNEL_3 == ENABLE)
		DIO_PinDirection(PA,pin3 ,INPUT);
	#endif
	#if	(CHANNEL_4 == ENABLE)
		DIO_PinDirection(PA,pin4 ,INPUT);
	#endif
	#if	(CHANNEL_5 == ENABLE)
		DIO_PinDirection(PA,pin5 ,INPUT);
	#endif
	#if	(CHANNEL_6 == ENABLE)
		DIO_PinDirection(PA,pin6 ,INPUT);
	#endif
	#if	(CHANNEL_7 == ENABLE)
		DIO_PinDirection(PA,pin7 ,INPUT);
	#endif

	SET_BIT(ADCSRA_REG,ADEN);

	SET_BIT(ADCSRA_REG,2);
	SET_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,0);

	CLR_BIT(ADMUX_REG,3);
	CLR_BIT(ADMUX_REG,4);

	TIM_vidDelay_us(10);

 }

void ADC_vidGetValue(channel CH, F32 * Value)
 {
	U8 Local_ReadL;
	U8 Local_ReadH;
	U16 Local_ADC_Value;
	F32 Local_Volt;

	ADC_vidChannelSelect(CH);
	TIM_vidDelay_ms(100);

	SET_BIT(ADCSRA_REG,ADSC);
	while(GET_BIT(ADCSRA_REG,ADIF));

	Local_ReadL = ADCL_REG ;
	Local_ReadH = ADCH_REG;

	Local_ADC_Value = (Local_ReadH<<8)|(Local_ReadL);
//	Local_Volt =((F32)Local_ADC_Value * VOLT_REF_VALUE)/(1024.0f);
	Local_Volt =(F32)Local_ADC_Value * (VOLT_REF_VALUE/(1023.0f));
	* Value = Local_Volt;

 }



