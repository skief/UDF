#pragma once

#include "output.h"

class PWMLed : public Output{
    private:
        uint8_t pin;
        uint8_t minDuty;
        uint8_t maxDuty;

    protected:
        void set(uint8_t value);

    public:
        PWMLed(uint8_t pin, uint8_t minDuty=0, uint8_t maxDuty=255);
};
