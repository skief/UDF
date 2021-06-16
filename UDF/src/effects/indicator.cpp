#include "indicator.h"

Indicator::Indicator(bool indicateMute, Colors::RGB onColor, Colors::RGB offColor): 
    indicateMute(indicateMute), onColor(onColor), offColor(offColor){}

Colors::RGB Indicator::getColor(uint16_t value){
    if ((indicateMute && value == 0) || (!indicateMute && value > 0)){
        return onColor;
    }

    return offColor;
}
