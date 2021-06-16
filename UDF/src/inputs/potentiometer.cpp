#include <Arduino.h>

#include "../boards/board.h"
#include "potentiometer.h"

Potentiometer::Potentiometer(uint8_t pin, Filter *filter): pin(pin), filter(filter){
}

void Potentiometer::update(uint64_t time){
    value = analogRead(pin);
    value = filter->filter(value);
    value = map(value, 0, MAXADCVALUE, 0, 1023);
}

uint16_t Potentiometer::getValue(){
    return value;
}
