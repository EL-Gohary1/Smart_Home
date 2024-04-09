#include "Utils.h"
#include "StdType.h"
#include "Mem_Map32.h"
/***************************MCAL INC****************************************/
#include "DIO_interface.h"
#include "TMR1_interface.h"
#include "UART_Interface.h"
#include "USART_SERVICE.h"
/***************************HAL INC****************************************/
#include "LCD_interface.h"
#include "LED.h"
#include "Servo.h"
/***************************APP INC****************************************/
#include "Control_System_Using_Uart.h"
#include "SmartLigthControlSystem.h"
#include "FireAlarmSystem.h"

int main(void)
{
   DIO_Init();
   LCD_vInit();
   USART_vInit(UART_BAUDRATE_9600);
   Servo_voidInit();
   Control_System_vInit();
   FIREALARMSYSTEM_voidAlarmSystemIntit();
   SmartLigthControlSystem_vSmartLigthInit();
   sei();
   USART_SERVICE_vSendStringAsynchronous((u8*)"hello");
    while (1) 
    {
		Control_System_vRunnable();    
	    FIREALARMSYSTEM_voidAlarmSystemRunnable();
		SmartLigthControlSystem_vSmartLigthRunnable();
    }
}

