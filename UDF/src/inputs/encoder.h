#pragma once

#include "input.h"
#include <inttypes.h>

class Encoder : public Input{
    private:
        uint8_t pinA;
        uint8_t pinB;
        uint16_t stepSize;

        uint8_t lastPinA;
        int16_t pos;

    public:
        Encoder(uint8_t pinA, uint8_t pinB, uint16_t stepSize);

        void update(uint64_t time);

        uint16_t getValue();
};
