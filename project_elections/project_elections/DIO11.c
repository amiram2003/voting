/*
 * DIO11.c
 *
 * Created: 19/04/2024 05:39:35 
 *  Author: Amira Al-wakeel
 */ 
#include <avr/io.h>
#include "STD_Macros1.h"
void DIO_setpindir(unsigned char p , unsigned char pin ,unsigned char dir)
{
	switch (p)
	{
	case 'A':
		if(dir==1)
		{
			SET_BIT(DDRA , pin);
		}
		else
	     {
	       CLR_BIT(DDRA , pin);
	     }
		 break;
	 case 'B':
		 if(dir==1)
		 {
			 SET_BIT(DDRB , pin);
		 }
		 else
		 {
			 CLR_BIT(DDRB , pin);
		 }
		 break;
	 case 'C':
		 if(dir==1)
		 {
			 SET_BIT(DDRC , pin);
		 }
		 else
		 {
			 CLR_BIT(DDRC , pin);
		 }
		 break;
	 case 'D':
		 if(dir==1)
		 {
			 SET_BIT(DDRD , pin);
		 }
		 else
		 {
			 CLR_BIT(DDRD , pin);
		 }
		 break;
	   }
	}
	
	
	void DIO_pinwrite(unsigned char p ,unsigned char pin ,unsigned char val)
	{
		switch(p)
		{
		case 'A':
			if(val==1)
			{
				SET_BIT(PORTA , pin);
			}
			else
			{
				CLR_BIT(PORTA , pin);
			}
			break;
		case 'B':
			if(val==1)
			{
				SET_BIT(PORTB , pin);
			}
			else
			{
				CLR_BIT(PORTB , pin);
			}
			break;
		case 'C':
			if(val==1)
			{
				SET_BIT(PORTC , pin);
			}
			else
			{
				CLR_BIT(PORTC , pin);
			}
			break;
	    case 'D':
			if(val==1)
			{
				SET_BIT(PORTD , pin);
			}
			else
			{
				CLR_BIT(PORTD , pin);
			}
			break;
	    }
}



void DIO_pintoggile(unsigned char p ,unsigned char pin)
{
	switch (p)
	{
	case 'A':
		TOG_BIT(PORTA , pin);
		break;
	case 'B':
		TOG_BIT(PORTB , pin);
		break;
	case 'C':
		TOG_BIT(PORTC , pin);
		break;
	case 'D':
		TOG_BIT(PORTD , pin);
		break;
		
	}
}



char DIO_pinread(unsigned char p ,unsigned char pin)
{
	unsigned char val=0;
	switch(p)
	{
	case 'A':
		val= READ_BIT(PINA , pin);
		break;
	case 'B':
		val= READ_BIT(PINB , pin);
		break;
	case 'C':
		val= READ_BIT(PINC , pin);
		break;
	case 'D':
		val= READ_BIT(PIND , pin);
		break;
		
	}
	return val;
} 


void DIO_setportdir(unsigned char p ,unsigned char dir)
{
	switch(p)
	{
	case 'A':
		DDRA=dir;
		break;
	case 'B':
		DDRB=dir;
		break;
	case 'C':
		DDRC=dir;
		break;
	case 'D':
		DDRD=dir;
		break;
	}
}


void DIO_portwrite(unsigned char p ,unsigned char val)
{
	switch(p)
	{
	case 'A':
		PORTA=val;
		break;
	case 'B':
		PORTB=val;
		break;
	case 'C':
		PORTC=val;
		break;
	case 'D':
		PORTD=val;
		break;
	}
}

char DIO_portread(unsigned char p)
{
	unsigned char result=0;
	switch(p)
	{
	case 'A':
		result=PINA;
		break;
	case 'B':
		result=PINB;
		break;
	case 'C':
		result=PINC;
		break;
	case 'D':
		result=PIND;
		break;
		
	}
	return result;
}



void DIO_porttoggle(unsigned char p)
{
	switch(p)
	{
	case 'A':
		PORTA=~PORTA;
		break;
	case 'B':
		PORTB=~PORTB;
		break;
	case 'C':
		PORTC=~PORTC;
		break;
	case 'D':
		PORTC=~PORTD;
		break;
	}
}
void DIO_connectpullup(unsigned char port ,unsigned char pin ,unsigned char connect_pullup)
{
	switch(port)
	{
		case 'A':
		if(connect_pullup==1)
		{
			SET_BIT(PORTA , pin);
		}
		else
		{
			CLR_BIT(PORTA , pin);
		}
		break;
		case 'B':
		if(connect_pullup==1)
		{
			SET_BIT(PORTB , pin);
		}
		else
		{
			CLR_BIT(PORTB , pin);
		}
		break;
		case 'C':
		if(connect_pullup==1)
		{
			SET_BIT(PORTC , pin);
		}
		else
		{
			CLR_BIT(PORTC , pin);
		}
		break;
		case 'D':
		if(connect_pullup==1)
		{
			SET_BIT(PORTD , pin);
		}
		else
		{
			CLR_BIT(PORTD , pin);
		}
		break;
		

	}
}
void DIO_write_low_nibble(unsigned char port , unsigned char val)
{
	val&=0x0f;
	switch(port)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA=PORTA | val;
		break;
		case 'B':
		PORTB&=0xf0;
		PORTB=PORTB | val;
		break;
		case 'C':
		PORTC&=0xf0;
		PORTC=PORTC | val;
		break;
		case 'D':
		PORTD&=0xf0;
		PORTD=PORTD | val;
		break;
	}
}

void DIO_write_high_nibble(unsigned char port , unsigned char val)
{
	val<<=4;
	switch(port)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA=PORTA | val;
		break;
		case 'B':
		PORTB&=0x0f;
		PORTB=PORTB | val;
		break;
		case 'C':
		PORTC&=0x0f;
		PORTC=PORTC | val;
		break;
		case 'D':
		PORTD&=0x0f;
		PORTD=PORTD | val;
		break;
	}
}
