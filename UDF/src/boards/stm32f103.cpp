#ifdef ARDUINO_GENERIC_STM32F103C

#include <Arduino.h>
#include "../../defaults.h"
#include "board.h"
#include <USBComposite.h>

HardwareTimer timer(1);
voidF callback;

void timerIt(){
    callback();
}

void startTimer(voidF func){
    callback = func;

    timer.pause();

    timer.setMode(TIMER_CH1, TIMER_OUTPUT_COMPARE);
    timer.setPeriod(1000000 / UPDATEFREQ);

    timer.attachCompare1Interrupt(timerIt);

    timer.refresh();

    timer.resume();
}

#endif
