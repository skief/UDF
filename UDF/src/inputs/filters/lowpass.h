#pragma once

#include "filter.h"

class LowPass : public Filter {
    private:
        float rc;
        float dt;
        
        float lastValue;

    public:
        LowPass(float cutoffFreq);

        uint16_t filter(uint16_t value);
};
