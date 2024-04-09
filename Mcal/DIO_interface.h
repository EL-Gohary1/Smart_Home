
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinMode_type;
typedef enum{
	PA=0,
	PB,
	PC,
	PD
	}DIO_Port_type;
	
typedef enum{
	LOW=0,
	HIGH
    }DIO_PinVoltage_type;
	
typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;
	
	

/******************************************************************************************************************************
* \Syntax			: DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
* \Description		: this function write on pin that configure as output by write on port register
*
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	: @ pin: Specified Pin
*                       This parameter can be One of  DIO_Pin_type Enum Values to Select Prescaler:
*                        @ PINA0 to PINA7 
*                        @ PINB0 to PINB0
*                        @ PINC0 to PINC0
*                        @ PIND0 to PIND0 
*                     @ volt: This parameter can be One of  DIO_Pin_type Enum Values to Specified the volt write on pin
*                       This parameter can be high or low
*
* \Return value     : None
******************************************************************************************************************************/	
extern void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);

/******************************************************************************************************************************
* \Syntax			: DIO_TogglePin(DIO_Pin_type pin)
* \Description		: this function to toggle pin that is configured as output
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	: @ pin: Specified Pin
*                       This parameter can be One of  DIO_Pin_type Enum Values to Select Prescaler:
*                        @ PINA0 to PINA7 
*                        @ PINB0 to PINB0
*                        @ PINC0 to PINC0
*                        @ PIND0 to PIND0 
*                        
* \Return value     : None
******************************************************************************************************************************/
extern void DIO_TogglePin(DIO_Pin_type pin);

/******************************************************************************************************************************
* \Syntax			: u8  DIO_ReadPort(DIO_Port_type port)
* \Description		: This function to read input on port by read on pin Register for this port
*
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	:  @ port: Specified port number
*                       This parameter can be One of  DIO_Port_type:
*                        @ PA : PORTA
*                        @ PB : PORTB
*                        @ PC : PORTC
*                        @ PD : PORTD
*                        
* \Return value     : u8 : Value of input on port can be from 0x00 to 0xFF
******************************************************************************************************************************/
extern u8   DIO_ReadPort(DIO_Port_type port);

/******************************************************************************************************************************
* \Syntax			: void DIO_WritePort(DIO_Port_type port,u8 value)
* \Description		: This function to write output on port by write on port Register  
*
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	: @ port: Specified port number
*                       This parameter can be One of  DIO_Port_type:
*                        @ PA : PORTA
*                        @ PB : PORTB
*                        @ PC : PORTC
*                        @ PD : PORTD
*                     @ value: Specified the value is writen on port 
*                       This parameter can be from 0x00 to 0xFF
*                        
* \Return value     : None
******************************************************************************************************************************/
extern void DIO_WritePort(DIO_Port_type port,u8 value);

/******************************************************************************************************************************
* \Syntax			: DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
* \Description		: This function to Read input from PINX Register 
*
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	: @ pin: Specified Pin
*                       This parameter can be One of  DIO_Pin_type Enum Values to Select Prescaler:
*                        @ PINA0 to PINA7 
*                        @ PINB0 to PINB0
*                        @ PINC0 to PINC0
*                        @ PIND0 to PIND0            
*         
* \Return value     : DIO_PinVoltage_type : can be low or high
******************************************************************************************************************************/
extern DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin);

/******************************************************************************************************************************
* \Syntax			: void DIO_Init(void)
* \Description		: DIO Initialization by take configured array on configration file
*                     
*
*
* \Sync\Async		: Synchronous
* \Reenrancy    	: None Reentrant
* \Parameters (in)	: None
*                        
* \Return value     : None
******************************************************************************************************************************/
extern void DIO_Init(void);


#endif /* DIO_INTERFACE_H_ */