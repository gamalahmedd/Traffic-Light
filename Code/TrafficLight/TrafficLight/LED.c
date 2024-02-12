#include "DIO.h"

void LED_vInit(unsigned char portname, unsigned char pinnumber)
{
	DIO_vsetPinDir(portname, pinnumber, 1);
}

void LED_vInitPort(unsigned char portname)
{
	DIO_vSetPortDirection(portname, 0xFF);
}

void LED_vTurnOn(unsigned char portname, unsigned char pinnumber)
{
	DIO_vWritePin(portname, pinnumber, 1);
}

void LED_vTurnOff(unsigned char portname, unsigned char pinnumber)
{
	DIO_vWritePin(portname, pinnumber, 0);
}

void LED_vToggle(unsigned char portname, unsigned char pinnumber)
{
	DIO_vTogglePin(portname, pinnumber);
}

unsigned char LED_u8ReadStatus(unsigned char portname, unsigned char pinnumber)
{
	unsigned char return_value = 0;
	return_value = DIO_u8ReadPin(portname, pinnumber);
	return return_value;
}