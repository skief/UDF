#pragma once

#include <inttypes.h>

class Protocol{
    public:
        virtual void setup() = 0;

        virtual void update(uint16_t* values, uint16_t len) = 0;
};
