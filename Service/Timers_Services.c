#include "Utils.h"
#include "StdType.h"
#include "Mem_Map32.h"
#include "TMR1_interface.h"
#include "Timers_Services.h"



/**********************************************PWM Timer1*********************************************************/
void PWM_Init(OC1A_Mode_type oc1a_mode, OC1B_Mode_type oc1b_mode )
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_64);
	Timer1_OCRA1Mode(oc1a_mode);
	Timer1_OCRB1Mode(oc1b_mode);
}

void PWM_Freq_KHZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 Ttotal=1000/freq;
		if (Ttotal>=1)
		{
			ICR1=Ttotal/4-1;
		}
		else ICR1=0;
		
	}
}
void PWM_Freq_HZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 Ttotal=(u32)1000000/freq;
		if (Ttotal>=1)
		{
			ICR1=Ttotal/4-1;
		}
		else ICR1=0;
	}



}
void PWM_vOCRA1Duty(u16 duty100)
{
	 if (duty100<=10000)
	{
		u16 Ton=((u32)duty100*(ICR1+1))/10000;
		if (Ton>1)
		{
			OCR1A=Ton-1;	
		}
		else
		OCR1A=0;	
	}
}

void PWM_vOCRB1Duty(u16 duty)
{
	if (duty<=100)
	{
		u16 Ton=((u32)duty*(ICR1+1))/100;
		if (Ton>1)
		{
			OCR1B=Ton-1;
		}
		else
		OCR1B=0;
	}
}

