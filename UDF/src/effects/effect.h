#pragma once

#include "../utils/color.h"
#include <inttypes.h>

class Effect{
    protected:
        virtual Colors::RGB getColor(uint16_t value) = 0;
    
    public:
        uint32_t _getColor(uint16_t value);
};
