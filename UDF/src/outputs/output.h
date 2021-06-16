#pragma once

#include <stdint.h>

class Output{
    protected:
        virtual void setRGB(uint8_t r, uint8_t g, uint8_t b);
        virtual void set(uint8_t value);
        
    public:
        void _set(uint32_t color);
};
