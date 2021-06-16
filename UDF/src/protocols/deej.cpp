#include "../boards/board.h"

#ifdef SUPPORTSDEEJ

#include <Arduino.h>

#include "deej.h"
#include "../../defaults.h"

void Deej::setup(){
    Serial.begin(BAUDRATE);
}

void Deej::update(uint16_t* values, uint16_t len){
    String msg;
    for (uint16_t i = 0; i < len; i++){
        msg += String(values[i]);
        if (i < len - 1){
            msg += "|";
        }
    }
    msg += "\n";

    Serial.print(msg);
}

#endif
