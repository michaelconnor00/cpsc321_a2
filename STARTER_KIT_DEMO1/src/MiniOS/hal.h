/*
 * hal.h
 *
 */ 

#ifndef HAL_H_
#define HAL_H_

typedef uint32_t tLedNum;
typedef uint32_t tLedState;

typedef struct{
	uint32_t seconds;
	uint32_t minutes;
	uint32_t hours;
	uint32_t day;
	uint32_t month;
	uint32_t year;
}tTime;

enum tLedState{ LedOff=false, LedOn };
enum tLedNum{ Led0 = 0, Led1, Led2, Led3 };

void hal_led_set( tLedNum, tLedState );
void hal_time_set( tTime* );
void hal_time_get( tTime* );
	
#endif /* HAL_H_ */