/*
 * dLCD.c
 *
 * Created: 19/07/2024 01:33:54 م
 *  Author: Amira Al-wakeel
 */ 
#include "dLCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void lcd_init(void)
{
	_delay_ms(200);
	#if defined eight_bitmode
	DIO_setpindir('A',0,1);
	DIO_setpindir('A',1,1);
	DIO_setpindir('A',2,1);
	DIO_setpindir('A',3,1);
	DIO_setpindir('A',4,1);
	DIO_setpindir('A',5,1);
	DIO_setpindir('A',6,1);
	DIO_setpindir('A',7,1);
	DIO_setpindir('B',EN,1);
	DIO_setpindir('B',RW,1);
	DIO_setpindir('B',RS,1);
	DIO_pinwrite('B',RW,0);
	lcd_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_setpindir('A',4,1);
	DIO_setpindir('A',5,1);
	DIO_setpindir('A',6,1);
	DIO_setpindir('A',7,1);
	DIO_setpindir('B',EN,1);
	DIO_setpindir('B',RW,1);
	DIO_setpindir('B',RS,1);
	DIO_pinwrite('B',RW,0);
	lcd_send_cmd(FOUR_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	lcd_send_cmd(RETURN_HOME);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif

}

 static void enable(void)
{
	DIO_pinwrite('B',EN,1);
	_delay_ms(2);
	DIO_pinwrite('B',EN,0);
	_delay_ms(2);
}
void lcd_send_cmd(unsigned char com)
{
	
	#if defined eight_bitmode
	DIO_portwrite('A',com);
	DIO_pinwrite('B',RS,0);
	enable();
	
	#elif defined four_bit_mode
	DIO_write_high_nibble('A',com>>4);
	DIO_pinwrite('B',RS,0);
	enable();
	DIO_write_high_nibble('A',com);
	DIO_pinwrite('B',RS,0);
	enable();
	#endif
	_delay_ms(1);
	
}
void lcd_senddata(unsigned char data)
{
	#if defined eight_bitmode
	DIO_portwrite('A',data);
	DIO_pinwrite('B',RS,1);
	enable();
	
	#elif defined four_bit_mode
	DIO_write_high_nibble('A',data>>4);
	DIO_pinwrite('B',RS,1);
	enable();
	DIO_write_high_nibble('A',data);
	DIO_pinwrite('B',RS,1);
	enable();
	#endif
	_delay_ms(1);
	
}


void lcd_clearscreen(void)
{
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void lcd_movecursor(char row,char col)
{
    char cmd;
	if(row>2||row<1||col>16||col<1)
	{
		cmd=0x80;
	}
	else if(row==1)
	{
		cmd=0x80+col-1;
	}
	else if(row==2)
	{
		cmd=0xc0+col-1;
	}
	lcd_send_cmd(cmd);
	_delay_ms(1);
}

void lcd_send_string(const char *ptr)
{
	while((*ptr)!='\0')
	{
		lcd_senddata(*ptr);
		ptr++;
	}
}
