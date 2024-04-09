/*
 * Control_System.h
 *
 * Created: 3/28/2024 8:25:10 PM
 *  Author: lenovo
 */ 


#ifndef CONTROL_SYSTEM_H_
#define CONTROL_SYSTEM_H_

typedef struct
{
	u8 Command[20];
	void (*PtrF)(u8);
}Control_System_Command_t;




void Control_System_vInit(void);

void Control_System_vRunnable(void);



#endif /* CONTROL_SYSTEM_H_ */