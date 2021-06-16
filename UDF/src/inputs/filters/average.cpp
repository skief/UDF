#include "average.h"

MovingAverage::MovingAverage(uint16_t horizon): horizon(horizon){
    for (uint16_t i = 0; i < horizon; i++){
        values[i] = 0;
    }
    pos = 0;
    sum = 0;
}

uint16_t MovingAverage::filter(uint16_t value){
    sum -= values[pos];
    values[pos] = value;
    pos = (pos + 1) % horizon;
    sum += value;
    
    return sum / horizon;
}
