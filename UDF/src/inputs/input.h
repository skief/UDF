#pragma once

#include <stdint.h>

class Input {
    public:
        virtual void update(uint64_t time) = 0;

        virtual uint16_t getValue() = 0;
};