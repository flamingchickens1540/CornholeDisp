#include <Arduino.h>
#include "countdown.h"

namespace countdown {
    
    long cntdwnDuration; 

    long cnt;

    int direction = 0; // 0 is down, 1 is up

    void initialize(long cntdwn) 
    {
        cntdwnDuration = cntdwn;
        cnt = cntdwnDuration;
    }

    int tick()
    {
        if (direction == cntdwnDuration)
        {
            direction = 0;
        }
        else if (direction == 0) 
        {
            durection = 1;
        }
        if (direction = 0)
        {
            cnt--;
        }
        else
        {
            cnt++;
        }
        
        return cnt;
    }
}