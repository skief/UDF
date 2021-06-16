#pragma once

#include "effect.h"

class Indicator: public Effect{
    private:
        bool indicateMute;
        Colors::RGB onColor;
        Colors::RGB offColor;

    protected:
        Colors::RGB getColor(uint16_t value);

    public:
        Indicator(bool indicateMute, 
                  Colors::RGB onColor={1.0f, 1.0f, 1.0f}, Colors::RGB offColor={0.0f, 0.0f, 0.0f});
};
