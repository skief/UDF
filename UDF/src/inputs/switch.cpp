#include "switch.h"

#include <Arduino.h>
#include "../boards/board.h"
#include "../../defaults.h"

Switch::Switch(uint8_t pin, SwitchType switchType, uint8_t highState, uint64_t debounce) : pin(pin), switchType(switchType), highState(highState){
    if (highState == LOW){
        // enable pullup
        #ifdef HASPULLUP
        pinMode(pin, INPUT_PULLUP);
        #endif
        #ifndef HASPULLUP
        pinMode(pin, INPUT);
        #endif
    } else {
        // enable pulldown
        #ifdef HASPULLDOWN
        pinMode(pin, INPUT_PULLDOWN);
        #endif
        #ifndef HASPULLDOWN
        pinMode(pin, INPUT);
        #endif
    }

    currentState = false;
    lastState = LOW;

    lastChange = 0;
    
    debounceTime = debounce * (1000 / UPDATEFREQ);
}

void Switch::update(uint64_t time){
    bool state = digitalRead(pin) == highState;

    if (switchType == Latching){
        currentState = state;
    } else {
        if (state && lastState != state && time - lastChange > debounceTime){
            currentState = !currentState;
            lastChange = time;
        }
    }

    lastState = state;
}
        
uint16_t Switch::getValue(){
    return currentState ? 1023 : 0;
}
