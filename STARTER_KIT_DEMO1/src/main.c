
/*
 * Assignment #2 
 * Michael Connor 
 */

#include "MiniOS/system.h"
#include "MiniOS/hal.h"
uint32_t seconds = 0;
uint32_t bool button_was_pressed = false;
uint64_t times_fired = 0;
void button_callback(){
	button_was_pressed = true;
}
void timer_callback(){
	seconds++;
	hal_led_toggle(Led1);
}
void ms_to_ticks(uint32_t time_in_ms ){
	//Do some arithmetic to create a value that can be passed
	//to the systick so that it fires in exactly
	//time_in_ms milliseconds
}
void systick_callback(){
	//make led1 toggle
	hal_led_toggle(Led1);
	times_fired++;
}
int main(void)
{
	system_init();
	//sets up button1 and systick
	hal_button_start(Button1, &button_callback);
	hal_systick_start(ms_to_ticks(90), &systick_callback);
	//prints message
	hal_lcd_clear();
	hal_lcd_write( " --- Demo App --- \n\n" );
	hal_lcd_write( "Press any button to continue" );
	hal_lcd_putchar(".");
	hal_lcd_putchar(".");
	hal_lcd_putchar(".");
	//wait until button 1 is pressed
	while( !button_was_pressed );
	while(true){
		hal_lcd_clear();
		hal_lcd_write( "The light level is %d out of 100\n", hal_light_read(LightScale1To100) );
		hal_lcd_write( "The light level is %d out of 10\n", hal_light_read(LightScale1To10) );
		10
		hal_lcd_write("\n");
		hal_lcd_write( "The systick has been fired %d times", times_fired );
		hal_delay(50); //update every 50ms
	}
}

