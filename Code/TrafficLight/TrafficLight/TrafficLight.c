#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "LED.h"
#include "TIMER_TWO.h"
#include "TrafficLight_Config.h"
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned char seconds = 0;
int main(void)
{
	signed char green_time = 10;
	signed char yellow_time =3;
	signed char red_time = 7;
	LED_vInit(LED_PORT, LED_RED);
	LED_vInit(LED_PORT, LED_YELLOW);
	LED_vInit(LED_PORT, LED_GREEN);
	LCD_vInit();
	TIMER_TWO_vInitNormalMode(256, 1);
	LCD_vSendString("Remaining Time ");
    while(1)
    {
		LED_vTurnOn(LED_PORT, LED_GREEN);
		while(green_time >= 0)
		{
			LCD_vMoveCursor(1, 16);
			LCD_vSendChar((green_time / 10) + 48);
			LCD_vSendChar((green_time % 10) + 48);
			if(seconds >= 1)
			{
				green_time--;
				seconds = 0;
			}
		}			  
		LED_vTurnOff(LED_PORT, LED_GREEN);
		green_time = 10;
		LED_vTurnOn(LED_PORT, LED_YELLOW);
		while(yellow_time >= 0)
		{
			LCD_vMoveCursor(1, 16);
			LCD_vSendChar((yellow_time / 10) + 48);
			LCD_vSendChar((yellow_time % 10) + 48);
			if(seconds >= 1)
			{
				yellow_time--;
				seconds = 0;
			}
		}
		LED_vTurnOff(LED_PORT, LED_YELLOW);
		yellow_time = 3;
		LED_vTurnOn(LED_PORT, LED_RED);
		while(red_time >= 0)
		{
			LCD_vMoveCursor(1, 16);
			LCD_vSendChar((red_time / 10) + 48);
			LCD_vSendChar((red_time % 10) + 48);
			if(seconds >= 1)
			{
				red_time--;
				seconds = 0;
			}
		}
		LED_vTurnOff(LED_PORT, LED_RED);
		red_time = 7; 
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds++;
}

