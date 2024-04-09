/*
 * LDR.c
 *
 * Created: 3/7/2024 10:01:42 AM
 *  Author: lenovo
 */ 
#include "LDR.h"
#include "ADC_interface.h"

void LDR_vLDRInit(void)
{
	
}


//vref 2.56
//resistance voltage divider 25kohm
//at dark resistance of LDR 10kohm , ADC: 572 , percentage  0%
//at light resistance of LDR 1kohm , ADC: 78  , percentage 100%
u8 LDR_vLDRPrecentage(void)
{
	u16 ADCREAD = ADC_vReadDigitalValueSingleConversionBlocking(LDR_CH);
	return (142900-(250*(u32)ADCREAD))/1236;
}



