#include <Arduino.h>

bool debug = false;

void set_debug(bool _debug) {
    debug = _debug;
}

void debug_init(int baudrate) {
    Serial.begin(baudrate);
}