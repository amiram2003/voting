/*
 * dpush.c
 *
 * Created: 03/05/2024 02:39:37 م
 *  Author: Amira Al-wakeel
 */ 
#include "DIO11.h"
void button_initial(char port , char pin)
{
	DIO_setpindir(port , pin , 0);
}
char button_read(char port , char pin)
{
	char x;
	x=DIO_pinread(port , pin);
	return x;
}