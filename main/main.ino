#include "largeSegmentDisp.h"
#include "countdown.h"

#define lgSegLat 8
#define lgSegClk 9
#define lgSegSer 10

#define countdownPin 11

using namespace large_segment_display;
using namespace countdown;

unsigned long countdownDuration = 10999;

char digits[]{
    0b11011110,
    0b00000110,
    0b10111010,
    0b10101110,
    0b01100110,
    0b11101100,
    0b11111100,
    0b10000110,
    0b11111110,
    0b11101110,
    0b11110110,
    0b01111100,
    0b11011000,
    0b00111110,
    0b11111000,
    0b11110000
};

void setup()
{
	large_segment_display::initialize(lgSegLat, lgSegClk, lgSegSer);
    countdown::initialize(countdownPin, &countdownDuration);
    updateDisplay(0);
}

void loop()
{
    countdown::tick();

    unsigned long timeLeft = countdown::getTimeLeft() / 100; // count in deciseconds

    updateTime(timeLeft);
}


inline void updateTime(char timeLeft) {

    char secs = digits[timeLeft / 10 % 10 & 0xf] | 1; // 0b1 because of the decimal point. 

    if(timeLeft > 100) {
        updateLargeDisplay(secs, digits[timeLeft / 100 % 10 & 0xf]);
    } else {
        updateLargeDisplay(digits[timeLeft % 10 & 0xf], secs);
    }
    large_segment_display::nextDigit();
}


char lastDisplayDigit1 = -1;
char lastDisplayDigit2 = -1;
void updateLargeDisplay(char displayDigit1, char displayDigit2) {
    if(lastDisplayDigit1 == displayDigit1 && lastDisplayDigit2 == displayDigit2) {
        return;
    }

    large_segment_display::writeDigit(lastDisplayDigit1 = displayDigit1);
    large_segment_display::writeDigit(lastDisplayDigit2 = displayDigit2);
}