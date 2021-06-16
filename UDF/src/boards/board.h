#pragma once

#ifdef ARDUINO_GENERIC_STM32F103C
    #pragma message ( "Using Generic STM32F103 Board" ) 
    #define BOARDFOUND
    #include "stm32f103.h"
#endif

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO)
    #pragma message ( "Using AVR Atmega328 board" )
    #define BOARDFOUND
    #include "atmega328.h"
#endif

#if defined(ARDUINO_AVR_LEONARDO)
    #pragma message ( "Using AVR Atmega32u4 board" )
    #define BOARDFOUND
    #include "atmega32u4.h"
#endif

// error handling
#ifndef BOARDFOUND
    #error Unknown board selected
#endif

/*#ifndef DEBUGLED
    #error Missing DEBUGLED definition in board
#endif*/

#ifndef ADCRESOLUTION
    #error Missing ADCRESOLUTION definition in board
#endif

// do some calculations needed in other parts of the program
#define MAXADCVALUE (1 << ADCRESOLUTION)

typedef void (*voidF)(void);

void startTimer(voidF func);
