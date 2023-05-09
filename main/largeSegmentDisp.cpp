#include "largeSegmentDisp.h"
#include <Arduino.h>

// This is yet to support multiple digits. Support for multiple digits might be coming

namespace large_segment_display {
    char lat;
    char clk;
    char ser;

    char segPos = 0;

    void initialize(char latPin, char clkPin, char serPin) {
        startPin(lat = latPin);
        startPin(clk = clkPin);
        startPin(ser = serPin);
    }

    inline void startPin(char pin) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    inline void tickPin(char pin) {
        digitalWrite(pin, LOW);
        digitalWrite(pin, HIGH);
    }

    void nextDigit() {
        tickPin(lat);
    }

    void nextSeg() {
        tickPin(clk);
        segPos++;
    }

    void writeSeg(bool on) {
        digitalWrite(ser, on);
        nextSeg();
    }

    void writeDigit(char segs) {
        /**
         * The reason why a while loop is being used instead of a for loop is for a much simpler incrementation.
         * For those not into bitwise operators yet, pos & 0b111 gets the result of pos % 8, however
         * pos & 0b111 will always give a positive integer while pos % 8 does not. If I am still in robotics
         * at the time of reading this, I'd be happy to give a quick explanation of bits and bitwises.
         */
        do {
            writeSeg(segs >> segPos & 1);
        } while(segPos & 0b111);
    }
}