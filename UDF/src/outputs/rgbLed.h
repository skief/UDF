#pragma once

#include "output.h"
#include "pwmLed.h"


class RGBLed : public Output{
    private:
        uint8_t pinR;
        uint8_t pinG;
        uint8_t pinB;

        uint8_t minDuty;
        uint8_t maxDuty;

    protected:
        void setRGB(uint8_t r, uint8_t g, uint8_t b);

    public:
        RGBLed(uint8_t pinR, uint8_t pinG, uint8_t pinB, uint8_t minDuty=0, uint8_t maxDuty=255);
};
