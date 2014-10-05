/*
 * system.c
 */ 

#include "system.h"

static const int PiocDirIn = 0;		//Parallel IO Controller Input
static const int PiocDirOut = 1;	//Parallel IO Controller Output

/*
 * Initializes MiniOS
 */
static void rtc_setup(void);

void system_init(){ 	
	
	sysclk_init();  //initialize clocks
	ioport_init();	//initialize IO port 
	rtc_setup();	//initialize RTC
	
	//initialize LED pins directions
	ioport_set_pin_dir( IOPORT_CREATE_PIN(PIOC, 20), PiocDirOut );
	ioport_set_pin_dir( IOPORT_CREATE_PIN(PIOA, 16), PiocDirOut );
	ioport_set_pin_dir( IOPORT_CREATE_PIN(PIOC, 22), PiocDirOut );
	ioport_set_pin_dir( IOPORT_CREATE_PIN(PIOC, 23), PiocDirOut );

	//LEDs start off
	ioport_set_pin_level( IOPORT_CREATE_PIN(PIOC, 20), true );
	ioport_set_pin_level( IOPORT_CREATE_PIN(PIOA, 16), true );
	ioport_set_pin_level( IOPORT_CREATE_PIN(PIOC, 22), true );
	ioport_set_pin_level( IOPORT_CREATE_PIN(PIOC, 23), true ); 
	
}

static void rtc_setup(void)
{
	pmc_switch_sclk_to_32kxtal(PMC_OSC_XTAL);
	while (!pmc_osc_is_ready_32kxtal());
	rtc_set_hour_mode(RTC, 0); //24-hrs mode by default
}