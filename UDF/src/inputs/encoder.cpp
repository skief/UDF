#include <Arduino.h>

#include "encoder.h"
#include "../boards/board.h"

Encoder::Encoder(uint8_t pinA, uint8_t pinB, uint16_t stepSize): pinA(pinA), pinB(pinB), stepSize(stepSize){
    lastPinA = LOW;
    pos = 0;

    #ifdef HASPULLUP
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    #endif
    #ifndef HASPULLUP
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    #endif
}

void Encoder::update(uint64_t time){
    // todo maybe debounce

    int now = digitalRead(pinA);
    if (lastPinA == HIGH && now == LOW){
        if (digitalRead(pinB) == HIGH){
            pos += stepSize;
            if (pos > 1023){
                pos = 1023;
            }
        } else {
            pos -= stepSize;
            if (pos < 0){
                pos = 0;
            }
        }
    }
    lastPinA = now;
}

uint16_t Encoder::getValue(){
    return pos;
}
