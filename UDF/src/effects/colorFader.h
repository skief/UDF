#pragma once

#include "effect.h"
#include "../utils/color.h"

class RGBFader : public Effect{
    private:
        Colors::RGB start;
        Colors::RGB end;

    protected:
        Colors::RGB getColor(uint16_t value);

    public:
        RGBFader(Colors::RGB start, Colors::RGB end);

        
};

class HSVFader : public Effect{
    private:
        Colors::HSV start;
        Colors::HSV end;

    protected:
        Colors::RGB getColor(uint16_t value);

    public:
        HSVFader(Colors::HSV start, Colors::HSV end);
};

class LinearFader : public Effect{
    private:
        uint8_t start;
        uint8_t stop;

    protected:
        Colors::RGB getColor(uint16_t value);
    
    public:
        LinearFader(uint8_t start=0, uint8_t stop=255);
};
