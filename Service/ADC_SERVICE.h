/*
 * ADC_SERVICE.h
 *
 * Created: 3/7/2024 9:24:03 AM
 *  Author: lenovo
 */ 
#ifndef  ADC_SERVICE_H_
#define  ADC_SERVICE_H_
#include "Utils.h"
#include "StdType.h"

#include "ADC_interface.h"

#define RESO     10


u16 ADC_SERVICE_u16ReadVoltmv(ADC_Channel_t ch, ADC_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv);

 
#endif