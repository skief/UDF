#pragma once

#include <inttypes.h>
#include "input.h"
#include "filters/filter.h"

class Potentiometer : public Input {
    private:
        uint8_t pin;
        Filter *filter;

        uint16_t value;
    public:
        Potentiometer(uint8_t pin, Filter *filter);

        void update(uint64_t time);

        uint16_t getValue();
};