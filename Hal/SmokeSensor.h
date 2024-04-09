/*
 * SmokeSensor.h
 *
 * Created: 3/10/2024 3:55:14 PM
 *  Author: lenovo
 */ 


#ifndef SMOKESENSOR_H_
#define SMOKESENSOR_H_

#define  SMOKE_SENSOR_CH   ADC7

void SmokeSensor_vInit(void);

u8 SmokeSensor_vReadPresentage(void);

#endif /* SMOKESENSOR_H_ */