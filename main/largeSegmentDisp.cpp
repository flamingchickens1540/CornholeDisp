#include "largeSegmentDisp.h"
#include <Arduino.h>

// This is yet to support multiple digits. Support for multiple digits might be coming

namespace large_segment_display {
    char lat;
    char clk;
    char ser;

    void initialize(char latPin, char clkPin, char serPin) {
        startPin(lat = latPin);
        startPin(clk = clkPin);
        startPin(ser = serPin);    }

    inline void startPin(char pin) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    void nextDigit() {
        digitalWrite(lat, LOW);
        digitalWrite(lat, HIGH);
    }

    void writeDigit(char segs) {
        shiftOut(ser, clk, LSBFIRST, segs);
    }
}