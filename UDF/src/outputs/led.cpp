#include <Arduino.h>
#include "led.h"

Led::Led(uint8_t pin): pin(pin){
    pinMode(pin, OUTPUT);
}

void Led::set(uint8_t value){
    if (value > 127){
        digitalWrite(pin, HIGH);
    } else {
        digitalWrite(pin, LOW);
    }
}
