/*
 * hal.c
 */ 
#include "system.h"
#include "hal.h"

void hal_led_set( tLedNum  lednum, tLedState state ){
	
	int IOLine = 0;
	
	switch(lednum){
		case Led0: IOLine = IOPORT_CREATE_PIN(PIOC, 20); break;
		case Led1: IOLine = IOPORT_CREATE_PIN(PIOA, 16); break;
		case Led2: IOLine = IOPORT_CREATE_PIN(PIOC, 22); break;
		case Led3: IOLine = IOPORT_CREATE_PIN(PIOC, 23); break;
	}
	
	//set pin
	ioport_set_pin_level( IOLine, !state );
	
}

void hal_led_get(tLedNum lednum){
	
	int IOLine = 0;
	
	switch(lednum){
		case Led0: IOLine = IOPORT_CREATE_PIN(PIOC, 20); break;
		case Led1: IOLine = IOPORT_CREATE_PIN(PIOA, 16); break;
		case Led2: IOLine = IOPORT_CREATE_PIN(PIOC, 22); break;
		case Led3: IOLine = IOPORT_CREATE_PIN(PIOC, 23); break;
	}
	
	return IOLine; //Return pin number for getting state of Led.
}

void hal_time_set( tTime* t ){
	
	rtc_set_date( RTC, t->year, t->month, t->day, 0 );
	rtc_set_time( RTC, t->hours, t->minutes, t->seconds );
	
}

void hal_time_get( tTime* t ){
	
	uint32_t dummy_week = 0;
	
	rtc_get_time(RTC, &(t->hours), &(t->minutes), &(t->seconds));
	rtc_get_date(RTC, &(t->year), &(t->month), &(t->day), &dummy_week);
	
}

void hal_led_toggle(tLedNum lednum){
	
	if(ioport_get_pin_level(hal_led_get(lednum))){
		hal_led_set(lednum, LedOn);
	}
	else {
		hal_led_set(lednum, LedOff);
	}
	
}