#pragma once

#include <inttypes.h>
#include "input.h"

class Switch : public Input {
    public:
        enum SwitchType {
            Latching,
            Momentary
        };

    private:
        uint8_t pin;
        SwitchType switchType;
        uint8_t highState;
        uint8_t lastState;

        uint64_t lastChange;
        uint64_t debounceTime;
        
        bool currentState;

    public:
        Switch(uint8_t pin, SwitchType switchType, uint8_t highState, uint64_t debounce);
        
        void update(uint64_t time);

        uint16_t getValue();
};
