/*
 * Switch.c
 *
 * Created: 3/21/2024 5:33:15 PM
 *  Author: lenovo
 */ 



#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"
#include "Switch.h"




void Switch_vEN(void)
{
    DIO_WritePin(SWITCH1,HIGH);
}

void Switch_vDisable(void)
{
	DIO_WritePin(SWITCH1,LOW);
}