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

#include "../../02_LIB/stdtypes.h"
#include "../../02_LIB/bitmath.h"
#include "../../02_LIB/atmega32_Registers.h"
#include "../../02_LIB/interrupt.h"

#include "Timer_interface.h"
#include "Timer_config.h"
#include "../DIO/DIO_interface.h"


void static delay_ASM_loop_1(U8 __count)
{
	__asm__ volatile (
		"1: dec %0" "\n\t"
		"brne 1b"
		: "=r" (__count)
		: "0" (__count)
	);
}

void static delay_ASM_loop_2(U16 __count)
{
	__asm__ volatile (
		"1: sbiw %0,1" "\n\t"
		"brne 1b"
		: "=w" (__count)
		: "0" (__count)
	);
}

void TIM_vidDelay_ms(double __ms)
{
	U16 __ticks;
	double __tmp = ((F_CPU) / 4e3) * __ms;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 65535)
	{
		//	__ticks = requested delay in 1/10 ms
		__ticks = (U16) (__ms * 10.0);
		while(__ticks)
		{
			// wait 1/10 ms
			delay_ASM_loop_2(((F_CPU) / 4e3) / 10);
			__ticks --;
		}
		return;
	}
	else
		__ticks = (U16)__tmp;
	delay_ASM_loop_2(__ticks);
}

void TIM_vidDelay_us(double __us)
{
	U8 __ticks;
	double __tmp = ((F_CPU) / 3e6) * __us;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 255)
	{
		TIM_vidDelay_ms(__us / 1000.0);
		return;
	}
	else
		__ticks = (U8)__tmp;
	delay_ASM_loop_1(__ticks);
}

void TIM_vidPWM_PB3_Init(void)
{
	if(PWM_OC0_MODE == NON_INVERTING_PWM)
	{

		CLR_BIT(TCCR0_REG,WGM01);
		SET_BIT(TCCR0_REG,WGM00);

		CLR_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);

		SET_BIT(TCCR0_REG,CS00);

	}

	else
	{
		CLR_BIT(TCCR0_REG,WGM01);
		SET_BIT(TCCR0_REG,WGM00);

		SET_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);

		SET_BIT(TCCR0_REG,CS00);

	}

	DIO_vidPinDirection(PB,pin3,OUTPUT);
}

void TIM_vidPWM_PD7_Init(void)
{
	if(PWM_OC2_MODE == NON_INVERTING_PWM)
	{

		CLR_BIT(TCCR2_REG,WGM21);
		SET_BIT(TCCR2_REG,WGM20);

		CLR_BIT(TCCR2_REG,COM20);
		SET_BIT(TCCR2_REG,COM21);

		SET_BIT(TCCR2_REG,CS20);

	}

	else
	{
		CLR_BIT(TCCR0_REG,WGM21);
		SET_BIT(TCCR0_REG,WGM20);

		SET_BIT(TCCR0_REG,COM20);
		SET_BIT(TCCR0_REG,COM21);

		SET_BIT(TCCR0_REG,CS20);

	}

	DIO_vidPinDirection(PD,pin7,OUTPUT);
}

void TIM_vidPWM_PB3_Generate(U16 Local_Percent)
{
	U8 Local_dutyCy;

	if(Local_Percent < 0 || Local_Percent > 100 )
		return;

	Local_dutyCy = (U8)((Local_Percent*255)/100);

	OCR0_REG = Local_dutyCy;
}

void TIM_vidPWM_PD7_Generate(U16 Local_Percent)
{
	U8 Local_dutyCy;

	if(Local_Percent < 0 || Local_Percent > 100 )
		return;

	Local_dutyCy = (U8)((Local_Percent*255)/100);

	OCR2_REG = Local_dutyCy;
}




























