
/*
 * ADC_SERVICE.C
 *
 * Created: 3/7/2024 9:23:32 AM
 *  Author: lenovo
 */ 

#include "ADC_SERVICE.h"

u16 ADC_SERVICE_u16ReadVoltmv(ADC_Channel_t ch, ADC_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv)
{
	u16 Local_u16Resolution=1;
	ADC_vSetVoltReference(copy_enumVref);
	u16 Local_u16ADCRead=ADC_vReadDigitalValueSingleConversionBlocking(ch);	
	for (u8 i=0 ;i<RESO;i++)
	{
		Local_u16Resolution*=2;
	}
	return ((u32)Local_u16ADCRead*Copy_u16VoltRefmv)/Local_u16Resolution;
}