#include "adv-config.h"

#ifndef DEEJ
    #define DEEJ
#endif

#ifndef BAUDRATE
    #define BAUDRATE 9600
#endif

#ifndef PUBLISHFREQ
    #define PUBLISHFREQ 100
#endif

#ifndef UPDATEFREQ
    #define UPDATEFREQ 1000
#endif

#ifndef MAX_CONTROL_ELEMENTS 
    #define MAX_CONTROL_ELEMENTS 20
#endif

#ifndef MAX_OUTPUTS
    #define MAX_OUTPUTS 20
#endif

#ifndef ADDRESSABLE_LED_PIN
    #define ADDRESSABLE_LED_PIN 0
#endif

#ifndef MAX_ADDR_LEDS
    #define MAX_ADDR_LEDS 100
#endif

#ifndef MAX_FILTER_HORIZON
    #define MAX_FILTER_HORIZON 100
#endif

#define PUB_SLEEP_TIME 1000 / PUBLISHFREQ
#define UPD_SLEEP_TIME 1000 / UPDATEFREQ
