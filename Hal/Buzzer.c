/*
 * Buzzer.c
 *
 * Created: 3/21/2024 5:27:31 PM
 *  Author: lenovo
 */ 

#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"
#include "Buzzer.h"


void Buzzer_vTurnON(void)
{
    DIO_WritePin(BUZZER_PIN,HIGH);	
}


void Buzzer_vTurnOFF(void)
{
	DIO_WritePin(BUZZER_PIN,LOW);
}

