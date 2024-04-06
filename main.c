#include "Utils.h"
#include "StdType.h"
#include "Mem_Map32.h"
#include "DIO_interface.h"
#include "TMR1_interface.h"
#include "UART_Interface.h"
#include "USART_SERVICE.h"

#include "LCD_interface.h"
#include "LED.h"
#include "Servo.h"

#include "Control_System.h"



int main(void)
{
   DIO_Init();
   LCD_vInit();
   sei();
   USART_vInit(UART_BAUDRATE_9600);
   Servo_voidInit();
   USART_SERVICE_vSendStringAsynchronous((u8*)"hello");
   LCD_vWriteString((u8*)"Welcome!");
   Control_System_vInit();
    while (1) 
    {
		//password
		Control_System_vRunnable();
    
    }
}

