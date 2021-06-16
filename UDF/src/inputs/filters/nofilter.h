#pragma once

#include "filter.h"

class NoFilter: public Filter{
    public:
        uint16_t filter(uint16_t value);
};
