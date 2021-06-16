#include "effect.h"

uint32_t Effect::_getColor(uint16_t value){
    Colors::RGB rgb = getColor(value);
    uint8_t r = rgb.r * 255.0f;
    uint8_t g = rgb.g * 255.0f;
    uint8_t b = rgb.b * 255.0f;

    return (r << 16) | (g << 8) | b;
}
