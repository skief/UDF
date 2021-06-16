#pragma once

#include "../boards/board.h"

#ifdef SUPPORTSDEEJ

#include "protocol.h"

class Deej : public Protocol{
    public:
        void setup();

        void update(uint16_t* values, uint16_t len);
};

#endif
