#ifndef LED_H_
#define LED_H_
/*
	Function Name        : LED_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Set the direction of the given pin 1 = output to initialize for led
*/
void LED_vInit(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : LED_vInitPort
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : Set the direction of the given port 1 = output to initialize for led
*/
void LED_vInitPort(unsigned char portname);
/*
	Function Name        : LED_vTurnLedOn
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Set 1 to the given port to turn the led on
*/
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : LED_vTurnLedOff
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Set 0 to the given port to turn the led off
*/
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : LED_vToggleLed
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Set 0 or 1 to the given pin to toggle the led
*/
void LED_vToggle(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : LED_u8ReadStatus
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : To read the status of the led
*/
unsigned char LED_u8ReadStatus(unsigned char portname, unsigned char pinnumber);
#endif