#include <Arduino.h>
#include "countdown.h"

namespace countdown {

    char cntdwnPin;
    unsigned long cntdwnTime = 0;

    void initialize(char countdownPin) {
        pinMode(cntdwnPin = countdownPin, INPUT);
    }

    inline bool isOff() {
        return digitalRead(cntdwnPin);
    }

    inline unsigned long startTime() {
        return cntdwnTime;
    }

    unsigned long getTimeLeft() {
        unsigned long currentTime = millis();

        if(isOff()) {
            cntdwnTime = currentTime;
        }
        
        return currentTime - cntdwnTime;
    }
}