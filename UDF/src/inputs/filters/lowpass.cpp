#include "lowpass.h"

#include "../../../defaults.h"

#ifndef M_PI
    #define M_PI 3.1415926535f
#endif

// Todo replace floats by integer arithmetic...

LowPass::LowPass(float cutoffFreq){
    rc = 1.0f / (2.0f * M_PI * cutoffFreq);
    dt = 1.0f / UPDATEFREQ;

    lastValue = 0.0f;
}

uint16_t LowPass::filter(uint16_t value){
    float alpha = dt / (rc + dt);

    lastValue = alpha * value + (1 - alpha) * lastValue;

    return (uint16_t)lastValue;
}
