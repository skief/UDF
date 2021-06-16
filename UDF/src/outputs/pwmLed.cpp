#include <Arduino.h>

#include "pwmLed.h"
#include "../utils/lerp.h"


PWMLed::PWMLed(uint8_t pin, uint8_t minDuty, uint8_t maxDuty): pin(pin), minDuty(minDuty), maxDuty(maxDuty){}

void PWMLed::set(uint8_t value){
    value = (uint8_t) lerp(minDuty, maxDuty, value / 255.0f);
    analogWrite(pin, value);
}
