
/*
 * LCD_program.c
 *
 * Created: 3/2/2024 9:55:54 AM
 *  Author: lenovo
 */ 
#include "StdType.h"
#include "Utils.h"

#include "LCD_cfg.h"
#include "LCD_interface.h"
#include "DIO_interface.h"




void LCD_vInit(void)
{
	#if LCD_MODE==FOUR_BIT_MODE 
	_delay_ms(40);
	LCD_vSendCommand(0x02);
	LCD_vSendCommand(0x28);
	_delay_ms(1);
	  #if CURSOR_BLINK_MODE ==  NOCURSOR_NOBLINK
	  LCD_vSendCommand(0x0c); 
	  #elif CURSOR_BLINK_MODE ==  CURSOR_NOBLINK
	  LCD_vSendCommand(0x0e);
	  #elif CURSOR_BLINK_MODE   ==  NOCURSOR_BLINK
	  LCD_vSendCommand(0x0d);
	  #else 
	  LCD_vSendCommand(0x0f);
	  #endif
	_delay_ms(1);
	LCD_vSendCommand(0x01); //clear
	_delay_ms(2);
	LCD_vSendCommand(0x06); //on increase DDRAMaddress  shift off
	#else
    _delay_ms(50);
    LCD_vSendCommand(0x38); //8bitmode,2lines 5*7font
    _delay_ms(1);
      #if CURSOR_BLINK_MODE ==  NOCURSOR_NOBLINK
      LCD_vSendCommand(0x0c);
      #elif CURSOR_BLINK_MODE ==  CURSOR_NOBLINK
      LCD_vSendCommand(0x0e);
      #elif CURSOR_BLINK_MODE  ==   NOCURSOR_BLINK
      LCD_vSendCommand(0x0d);
      #else //CURSOR_BLINK
      LCD_vSendCommand(0x0f);
      #endif   
	 _delay_ms(1);
    LCD_vSendCommand(0x01); //clear
    _delay_ms(2);
    LCD_vSendCommand(0x06); //on increase DDRAMaddress  shift off
    #endif
}

void LCD_vSendCommand(u8 inst)
{
	#if LCD_MODE==FOUR_BIT_MODE
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,(DIO_PinVoltage_type)READ_BIT(inst,7));
	DIO_WritePin(D6,(DIO_PinVoltage_type)READ_BIT(inst,6));
	DIO_WritePin(D5,(DIO_PinVoltage_type)READ_BIT(inst,5));
	DIO_WritePin(D4,(DIO_PinVoltage_type)READ_BIT(inst,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	DIO_WritePin(D7,(DIO_PinVoltage_type)READ_BIT(inst,3));
	DIO_WritePin(D6,(DIO_PinVoltage_type)READ_BIT(inst,2));
	DIO_WritePin(D5,(DIO_PinVoltage_type)READ_BIT(inst,1));
	DIO_WritePin(D4,(DIO_PinVoltage_type)READ_BIT(inst,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	#else
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,inst);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	#endif
}

void LCD_vWriteChar(u8 data)
{
	#if LCD_MODE==FOUR_BIT_MODE
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,(DIO_PinVoltage_type)READ_BIT(data,7));
	DIO_WritePin(D6,(DIO_PinVoltage_type)READ_BIT(data,6));
	DIO_WritePin(D5,(DIO_PinVoltage_type)READ_BIT(data,5));
	DIO_WritePin(D4,(DIO_PinVoltage_type)READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	DIO_WritePin(D7,(DIO_PinVoltage_type)READ_BIT(data,3));
	DIO_WritePin(D6,(DIO_PinVoltage_type)READ_BIT(data,2));
	DIO_WritePin(D5,(DIO_PinVoltage_type)READ_BIT(data,1));
	DIO_WritePin(D4,(DIO_PinVoltage_type)READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	#else
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	#endif
}


void LCD_vWriteString(u8* str)
{
	for (int i=0;str[i];i++)
	{
		LCD_vWriteChar(str[i]);
	}
}

void LCD_vSetCGRAM(u8 index )
{
	LCD_vSendCommand(0x40|index*8);
}
void LCD_vSetDDRAM(void)
{
	LCD_vSendCommand(0x80);	
}

void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	u8 iLoop=0;
	LCD_vSendCommand(0x40+(copy_u8ByteNum*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_vWriteChar(copy_u8data[iLoop]); //Pass the bytes of pattern on LCD
	LCD_vSetDDRAM();
}

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum)
{
	LCD_vWriteChar(copy_u8ByteNum);
}

void LCD_vClear(void)
{
	LCD_vSendCommand(0x01);
	_delay_ms(2);
}

void LCD_vGoToCollRow(u8 Copy_u8Coll , u8 Copy_u8Row)
{
	if (Copy_u8Row==0)
	{
		LCD_vSendCommand(0x80|Copy_u8Coll);
	}
	else if (Copy_u8Row==1)
	{
		LCD_vSendCommand(0xc0|Copy_u8Coll);
	}
	else if (Copy_u8Row==2)
	{
		LCD_vSendCommand(0x94|Copy_u8Coll);
	}
	else
	{
	   	LCD_vSendCommand(0xd4|Copy_u8Coll);	
	}
}

void LCD_vWriteInteger(u8 num)     //important
{
	u8 i=0,str[20];
	s8 j;
	if(num==0)
	{
		LCD_vWriteChar('0');
	}
	if (num<0)
	{
		LCD_vWriteChar('-');
		num=num*(-1);
	}
	while (num)
	{
		str[i]='0'+ num%10;
		num/=10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_vWriteChar(str[j]);
	}
}