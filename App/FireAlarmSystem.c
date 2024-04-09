/*
 * FireAlarmSystem.c
 *
 * Created: 3/10/2024 3:56:38 PM
 *  Author: lenovo
 */ 

#include "StdType.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LED.h"
#include "Buzzer.h"
#include "Switch.h"
#include "SmokeSensor.h"
#include "FireAlarmSystem.h"
#include "LM35.h"

static u8 flagheat=0;
static u8 flagFire=0;

void FIREALARMSYSTEM_voidDisplayTemp(u8 local_u8Temp)
{
	LCD_vGoToCollRow(4,2);
	LCD_vWriteString((u8*)"Temp:");
	LCD_vWriteInteger(local_u8Temp);
}


void FIREALARMSYSTEM_voidAlarmSystemIntit(void)
{
	LCD_vGoToCollRow(4,3);
	LCD_vWriteString((u8*)"FINE");
	u8 local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
	FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
}

void FIREALARMSYSTEM_voidAlarmSystemRunnable(void)
{
    u8 local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
	FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
    if (local_u8Temp>=50 && flagFire==0)
    {
		LCD_vGoToCollRow(4,3);
		LCD_vWriteString((u8*)"HEAT");
		LED_vTurnON(YELLOW_LED); //turn on yellow led
		flagheat=1;//set flagheat
		//read smoke
		if (SmokeSensor_vReadPresentage()>=35)
		{
			LED_vTurnON(RED_LED);  //turn on red led
			Buzzer_vTurnON();      //turn on buzzer
			Switch_vEN();          //turn on pump
			LCD_vGoToCollRow(4,3);
			LCD_vWriteString((u8*)"FIRE"); //display fire
			flagFire=1;
		}
		else
		{
			//nothing
		}
    }
    else
	{
		//temp<50
		if (flagFire==1) //if flagfire is set  display temp
		{
			//update display temp
			local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
			FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
		}
		else
		{
			if (flagheat==1) 
			{
				//if flagheat set && flagfire clear && temp<50   
				if (local_u8Temp>45)  
				{
					//if temp>45  display temp
					local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
					FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
				}
				else  
				{
					//if temp<45 display fine and temp and clear flagheat
					LCD_vGoToCollRow(4,3);
					LCD_vWriteString((u8*)"FINE");
					LED_vTurnOFF(YELLOW_LED);
					local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
					FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
					flagheat=0;
				}
			}
			else
			{
				   //flagheat clear && flagfire clear
				   local_u8Temp=LM35_u8ReadTemp(LVref_AVCC,5000);
				   FIREALARMSYSTEM_voidDisplayTemp(local_u8Temp);
			}
		}
	}	
}