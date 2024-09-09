/*
 * project_elections.c
 *
 * Created: 23/07/2024 05:19:18 م
 * Author : Amira Al-wakeel
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "dLCD.h"
#include "dpush.h"

 unsigned char counter1;
 unsigned char counter2;
 unsigned char counter3;
 unsigned char counter4;
 
int main(void)
{
   lcd_init();
   button_initial('B',3);
   button_initial('B',4);
   button_initial('B',5);
   button_initial('B',6);
   button_initial('B',7);
	
	lcd_send_string("A=0");
	lcd_movecursor(1,12);
	lcd_send_string("B=0");
	lcd_movecursor(2,1);
	lcd_send_string("C=0");
	lcd_movecursor(2,12);
	lcd_send_string("D=0");
	
    while (1) 
    {
		if(button_read('B',3)==1)
		{
			counter1++;
			lcd_movecursor(1,3);
			if(counter1<10)
			{
				lcd_senddata(counter1+48);
			}
			else
			{
				lcd_senddata(counter1/10+48);
				lcd_senddata(counter1%10+48);
			}
		}
		
		else if(button_read('B',4)==1)
		{
			counter2++;
			lcd_movecursor(1,14);
			if(counter2<10)
			{
				lcd_senddata(counter2+48);
			}
			else
			{
				lcd_senddata(counter2/10+48);
				lcd_senddata(counter2%10+48);
			}
		}
		
		else if(button_read('B',5)==1)
		{
			counter3++;
			lcd_movecursor(2,3);
			if(counter3<10)
			{
				lcd_senddata(counter3+48);
			}
			else
			{
				lcd_senddata(counter3/10+48);
				lcd_senddata(counter3%10+48);
			}
		}
		
		else if(button_read('B',6)==1)
		{
			counter4++;
			lcd_movecursor(2,14);
			if(counter4<10)
			{
				lcd_senddata(counter4+48);
			}
			else
			{
				lcd_senddata(counter4/10+48);
				lcd_senddata(counter4%10+48);
			}
		}
		
		else if(button_read('B',7)==1)
		{
			counter1=counter2=counter3=counter4=0;
			lcd_movecursor(1,1);
			lcd_send_string("A=0");
			lcd_movecursor(1,12);
			lcd_send_string("B=0");
			lcd_movecursor(2,1);
			lcd_send_string("C=0");
			lcd_movecursor(2,12);
			lcd_send_string("D=0");
			lcd_movecursor(1,1);
			
		}
		_delay_ms(200);
    }
}

