#include "largeSegmentDisp.h"
#include "countdown.h"

#define lgSegLat 8
#define lgSegClk 9
#define lgSegSer 10

#define countdownPin 11

using namespace large_segment_display;
using namespace countdown;

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

unsigned long countdownDuration = 10999;

void setup()
{
	large_segment_display::initialize(lgSegLat, lgSegClk, lgSegSer);
    countdown::initialize(countdownPin, &countdownDuration);
}

void loop()
{
    countdown::tick();

    unsigned long timeLeft = countdown::getTimeLeft() / 1000;

    

    updateLargeDisplay(digits[timeLeft % 10 & 0xf], digits[timeLeft / 10 % 10 & 0xf]);
}


char lastDisplayDigit1;
char lastDisplayDigit2;
void updateLargeDisplay(char displayDigit1, char displayDigit2) {
    if(lastDisplayDigit1 == displayDigit1 && lastDisplayDigit2 == displayDigit2) {
        return;
    }

    large_segment_display::writeDigit(lastDisplayDigit1 = displayDigit1);
    large_segment_display::nextDigit();
    large_segment_display::writeDigit(lastDisplayDigit2 = displayDigit2);
    large_segment_display::nextDigit();
}