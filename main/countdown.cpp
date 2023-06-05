#include <Arduino.h>
#include "countdown.h"

namespace countdown {
    
    long *cntdwnDuration;

    long endTime = 0;

    void initialize(long *cntdwn) {
        cntdwnDuration = cntdwn;
    }

    inline long getEndTime() {
        return endTime;
    }

    void reset() {
        endTime = millis() + *cntdwnDuration;
    }

    long getTimeLeft() {
        long timeLeft = getEndTime() - millis();
        long duration = *cntdwnDuration;

        return timeLeft / duration & 0b1 ? duration - timeLeft % duration : timeLeft % duration; // bounces countdown instead of rolling into the *hex negatives*
    }
}
