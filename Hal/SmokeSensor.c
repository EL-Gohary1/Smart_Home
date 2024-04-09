
/*
 * SmokeSensor.c
 *
 * Created: 3/10/2024 3:54:52 PM
 *  Author: lenovo
 */ 
#include "Utils.h"
#include "StdType.h"
#include "ADC_interface.h"
#include "ADC_SERVICE.h"
#include "SmokeSensor.h"

void SmokeSensor_vInit(void)
{
	
}

u8 SmokeSensor_vReadPresentage(void)
{ 
	u16 SmokeVoltOut=ADC_SERVICE_u16ReadVoltmv(SMOKE_SENSOR_CH,Vref_AVCC,5000);
	return (SmokeVoltOut)/50;
}