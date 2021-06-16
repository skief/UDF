#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO)

#include <Arduino.h>
#include "../../defaults.h"
#include "board.h"
#include <TimerOne.h>

voidF callback;

void timerIt(){
    callback();
}

void startTimer(voidF func){
    callback = func;

    Timer1.initialize(1000000 / UPDATEFREQ);
    Timer1.attachInterrupt(timerIt);
}

#endif
