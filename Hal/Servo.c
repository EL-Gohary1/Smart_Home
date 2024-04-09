


#include "StdType.h"
#include "Utils.h"
#include "TMR1_interface.h"
#include "Timers_Services.h"
#include "Servo.h"

void Servo_voidInit(void)
{
    PWM_Freq_HZ(50);
	PWM_Init(OCRA_DISCONNECTED,OCRB_NON_INVERTING);
}

void Servo_voidOn(u8 Copy_u8angle)
{
	
	 u16 local_u8Duty = (((u32)Copy_u8angle*500)/180)+500;
	 PWM_vOCRB1Duty(local_u8Duty);
}

void Servo_voidOff(void)
{
	
}
