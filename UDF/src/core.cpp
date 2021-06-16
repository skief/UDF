// #define DEBUG

#include <Arduino.h>

#include "boards/board.h"

#include "../adv-config.h"
#include "../defaults.h"

#include "inputs/encoder.h"
#include "inputs/potentiometer.h"
#include "inputs/switch.h"

#include "inputs/filters/nofilter.h"
#include "inputs/filters/average.h"
#include "inputs/filters/lowpass.h"

#include "outputs/led.h"
#include "outputs/pwmLed.h"
#include "outputs/rgbLed.h"

#include "effects/indicator.h"
#include "effects/colorFader.h"

#include "controlElements/controlElement.h"

#ifdef DEEJ
    #include "protocols/deej.h"

    Deej backend;
#endif

ControlElement* controlElements[MAX_CONTROL_ELEMENTS];
uint16_t controlElementValues[MAX_CONTROL_ELEMENTS];
uint8_t numControlElements = 0;

void addControlElement(ControlElement* controlElement){
    controlElements[numControlElements] = controlElement;
    numControlElements++;
}

#include "../config.h"

uint64_t time = 0;
#ifndef USE_HW_TIMER
    unsigned long lastUpdate = 0;
    unsigned long lastPublish = 0;
#endif

void update(){
    #ifdef DEBUG
        digitalWrite(DEBUGLED, HIGH);
    #endif

    time += 1;
    for (uint8_t i = 0; i < numControlElements; i++){
        controlElements[i]->update(time);
        controlElementValues[i] = controlElements[i]->getValue();
    }

    #ifdef DEBUG
        digitalWrite(DEBUGLED, LOW);
    #endif
}

void setup() {
    backend.setup();
    #ifdef USE_HW_TIMER
        startTimer(update);
    #endif

    config();

    #ifdef DEBUG
    pinMode(DEBUGLED, OUTPUT);
    #endif
}

void loop() {
    #ifdef USE_HW_TIMER
        backend.update(controlElementValues, numControlElements);
        delay(PUB_SLEEP_TIME);
    #else
        unsigned long now = millis();
        if (now - lastUpdate >= UPD_SLEEP_TIME){
            update();
            lastUpdate = now;
        }
        if (now - lastPublish >= PUB_SLEEP_TIME){
            backend.update(controlElementValues, numControlElements);
            lastPublish = now;
        }
    #endif
}
