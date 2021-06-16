#include "controlElement.h"

ControlElement::ControlElement(Input* input, Input* muteInput): input(input), muteInput(muteInput){
    numOutputs = 0;
}

void ControlElement::addOutput(Output* output, Effect* effect){
    outputs[numOutputs] = output;
    effects[numOutputs] = effect;
    numOutputs++;
}

void ControlElement::update(uint64_t time){
    value = 0;
    
    if (input != nullptr){
        input->update(time);
        value = input->getValue();
    }

    if (muteInput != nullptr){
        muteInput->update(time);

        if (muteInput->getValue() > 511){
            value = 0;
        }
    }

    for (uint8_t i = 0; i < numOutputs; i++){
        outputs[i]->_set(effects[i]->_getColor(value));
    }
}

uint16_t ControlElement::getValue(){
    return value;
}