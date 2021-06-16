#include "output.h"


void Output::_set(uint32_t color){
    uint8_t r = (color >> 16) & 0xff;
    uint8_t g = (color >> 8) & 0xff;
    uint8_t b = color & 0xff;

    setRGB(r, g, b);
    uint8_t max = r;
    if (g > max){
        max = g;
    }
    if (b > max){
        max = b;
    }

    set(max);
};

void Output::setRGB(uint8_t r, uint8_t g, uint8_t b){

}

void Output::set(uint8_t value){

}
