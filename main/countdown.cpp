#include <Arduino.h>
#include "countdown.h"

namespace countdown {

    char cntdwnPin;
    
    unsigned long *cntdwnDuration;

    unsigned long endTime = 0;

    void initialize(char countdownPin, unsigned long *cntdwn) {
        cntdwnDuration = cntdwn;
        pinMode(cntdwnPin = countdownPin, INPUT);
    }

    inline bool isOn() {
        return digitalRead(cntdwnPin);
    }

    inline unsigned long getEndTime() {
        return endTime;
    }

    void tick() {
        if(!isOn()) {
            endTime = millis() + *cntdwnDuration;
        }
    }

    unsigned long getTimeLeft() {
        return getEndTime() - millis();
    }
}