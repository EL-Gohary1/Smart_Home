/*
 * LDR.h
 *
 * Created: 3/7/2024 10:02:01 AM
 *  Author: lenovo
 */ 
#ifndef LDR_H_
#define LDR_H_

#include "Utils.h"
#include "StdType.h"

/*Select Channel of LDR
ADC0
ADC1
ADC2
ADC3
ADC4
ADC5
ADC6
ADC7
*/
#define LDR_CH ADC0

void LDR_vLDRInit(void);
u8 LDR_vLDRPrecentage(void);


#endif