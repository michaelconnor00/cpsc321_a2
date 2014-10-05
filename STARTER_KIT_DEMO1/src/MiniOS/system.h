/*
 * system.h
 *
 * Details:
 *		system.h must be included before any other header file, as it 
 *		has #includes required by other source code.
 *
 */ 

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <asf.h>		//The Atmel Software Framework Drivers 
#include <stdint-gcc.h>	//defs for size-specific primitive data types 
#include <stdbool.h>	//defs for true and false 

void system_init(void);

#endif