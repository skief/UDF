#pragma once

#include "../../defaults.h"
#include "../inputs/input.h"
#include "../outputs/output.h"
#include "../effects/effect.h"

class ControlElement{
    private:
        Input* input;
        Input* muteInput;

        Output* outputs[MAX_OUTPUTS];
        Effect* effects[MAX_OUTPUTS];
        uint8_t numOutputs;

        uint16_t value;

    public:
        ControlElement(Input* input, Input* muteInput=nullptr);
        void addOutput(Output* output, Effect* effect);

        void update(uint64_t time);
        uint16_t getValue();
};

