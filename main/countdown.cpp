#include <Arduino.h>
#include "countdown.h"

namespace countdown {
    
    unsigned long *cntdwnDuration;

    unsigned long endTime = 0;

    void initialize(unsigned long *cntdwn) {
        cntdwnDuration = cntdwn;
    }

    inline unsigned long getEndTime() {
        return endTime;
    }

    void reset() {
        endTime = millis() + *cntdwnDuration;
    }

    unsigned long getTimeLeft() {
        unsigned long timeLeft = getEndTime() - millis();
        unsigned long duration = *cntdwnDuration;
        
        return timeLeft / duration & 0b1 ? duration - timeLeft % duration : timeLeft % duration; // bounces countdown instead of rolling into the *hex negatives*
    }
}