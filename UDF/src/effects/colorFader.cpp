#include "colorFader.h"
#include "../utils/lerp.h"


RGBFader::RGBFader(Colors::RGB start, Colors::RGB end): start(start), end(end){}

Colors::RGB RGBFader::getColor(uint16_t value){
    float t = value / 1023.0f;

    float r = lerp(start.r, end.r, t);
    float g = lerp(start.g, end.g, t);
    float b = lerp(start.b, end.b, t);
    return Colors::RGB(r, g, b);
}


HSVFader::HSVFader(Colors::HSV start, Colors::HSV end): start(start), end(end){}

Colors::RGB HSVFader::getColor(uint16_t value){
    float t = value / 1023.0f;

    float h = lerp(start.h, end.h, t);
    float s = lerp(start.s, end.s, t);
    float v = lerp(start.v, end.v, t);
    return Colors::HSV(h, s, v).toRGB();
}

LinearFader::LinearFader(uint8_t start, uint8_t stop): start(start), stop(stop){}

Colors::RGB LinearFader::getColor(uint16_t value){
    float val = lerp(start/255.0f, stop/255.0f, value / 1023.0f);
    return {val, val, val};
}
