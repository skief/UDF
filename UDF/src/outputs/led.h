#pragma once

#include "output.h"

class Led : public Output{
    private:
        uint8_t pin;

    protected:
        void set(uint8_t value);

    public:
        Led(uint8_t pin);
};
