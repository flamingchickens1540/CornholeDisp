#include "largeSegmentDisp.h"

#define lgSegLat 0
#define lgSegClk 0
#define lgSegSer 0

#define powerlvlPin 0

#define countdownPin 0

using namespace large_segment_display;

void setup()
{
	large_segment_display::initialize(lgSegLat, lgSegClk, lgSegSer);
}

void loop()
{
	int powerlvl = analogRead(powerlvlPin);

    // the value of 6 in powerlvl is variable to the resolution based on the bit resolution of the board being used. The board I am using uses 10 bits, and I want to use the last 4 bits, so 10 - 4 is 6. See this link to get the bit resolution of your board. https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
    large_segment_display::writeDigit(powerlvl >> 6);

    large_segment_display::nextDigit();
}