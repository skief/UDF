#pragma once

#include "filter.h"

#include "../../../defaults.h"

class MovingAverage : public Filter {
    private:
        uint16_t values[MAX_FILTER_HORIZON];
        uint16_t pos;
        uint16_t horizon;
        int32_t sum;

    public:
        MovingAverage(uint16_t horizon);

        uint16_t filter(uint16_t value);
};
