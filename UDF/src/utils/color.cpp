#include <math.h>

#include "color.h"

Colors::RGB::RGB(){}
Colors::RGB::RGB(float r, float g, float b): r(r), g(g), b(b){}

Colors::HSV Colors::RGB::toHSV(){
    Colors::HSV out;
    float min = r < g ? r : g;
    min = min  < b ? min  : b;

    float max = r > g ? r : g;
    max = max  > b ? max  : b;

    out.v = max;
    float delta = max - min;
    
    if (delta < 0.00001){
        out.s = 0;
        out.h = 0;
        return out;
    }
    if( max > 0.0){
        out.s = (delta / max);
    }else{
        out.s = 0.0;
        out.h = NAN;
        return out;
    }
    if(r >= max){
        out.h = (g - b) / delta;
    }else if(g >= max){
        out.h = 2.0 + (b - r) / delta;
    }else{
        out.h = 4.0 + (r - g) / delta;
    }
    out.h *= 60.0;

    if(out.h < 0.0){
        out.h += 360.0;
    }

    return out;
}


Colors::HSV::HSV(){}
Colors::HSV::HSV(float h, float s, float v): h(h), s(s), v(v){}

Colors::RGB Colors::HSV::toRGB(){
    float hh, p, q, t, ff;
    long i;
    Colors::RGB out;

    if(s <= 0.0){
        out.r = v;
        out.g = v;
        out.b = v;
        return out;
    }
    hh = h;
    if(hh >= 360.0){
        hh = 0.0;
    }

    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch(i) {
    case 0:
        out.r = v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = v;
        out.b = t;
        break;

    case 3:
        out.r = p;
        out.g = q;
        out.b = v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = v;
        break;
    case 5:
    default:
        out.r = v;
        out.g = p;
        out.b = q;
        break;
    }

    return out;
}