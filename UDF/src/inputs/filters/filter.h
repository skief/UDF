#pragma once

#include <inttypes.h>

class Filter{
    public:
        virtual uint16_t filter(uint16_t value) = 0;
};
