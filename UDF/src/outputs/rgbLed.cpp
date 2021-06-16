#include <Arduino.h>
#include "rgbLed.h"
#include "../utils/lerp.h"


RGBLed::RGBLed(uint8_t pinR, uint8_t pinG, uint8_t pinB, uint8_t minDuty, uint8_t maxDuty): 
    pinR(pinR), pinG(pinG), pinB(pinB), minDuty(minDuty), maxDuty(maxDuty){}

void RGBLed::setRGB(uint8_t r, uint8_t g, uint8_t b){
    analogWrite(pinR, lerp(minDuty, maxDuty, r));
    analogWrite(pinG, lerp(minDuty, maxDuty, g));
    analogWrite(pinB, lerp(minDuty, maxDuty, b));
}
