#include "largeSegmentDisp.h"
#include "countdown.h"

#define lgSegLat 8
#define lgSegClk 9
#define lgSegSer 10

#define countPin 11 // This pin tells whether the countdown or powerselection should be actively counting and updating numbers.
#define displayCountdownPin 12 // Displays the countdown or powerselection

using namespace large_segment_display;
using namespace countdown;

bool displayedCountdown = false;

long cntdwn = 5005; // Added time to round the countdown to prevent flickering from 5.0 to 4.9. round(x) = floor(x + 0.5)

long powerselection = 10000;

long countdownDuration = powerselection;

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
    countdown::initialize(&countdownDuration);
}
 
void loop()
{
    bool displayCountdown = digitalRead(displayCountdownPin);

    if(displayCountdown ^ displayedCountdown) { // I used XOR to make people confused. XOR is !=
        countdownDuration = displayCountdown ? cntdwn : powerselection; // changes the countdownDuration
        displayedCountdown = displayCountdown;
        countdown::reset();
    }   


    if(digitalRead(countPin)) { // The countdown/powerselection freezes when the countdown pin is on
        countdown::reset();
        if(displayCountdown) { // Since the countdown will never stop counting down, when the count pin is on and the countdown needs to be display, pictures will be displayed instead
            if(millis() % 20 > 10) // Every 10 seconds, the countdown switches what it displays
                updateLargeDisplay(0b11011000, 0b01110110); // Display CH (Corn Hole on idle)
            else
                updateLargeDisplay(0b00011011, 0b01001100); // displays a smiley face
        }
    } else {
        updateDisplayNumber(
            displayCountdown ? 
            countdown::getTimeLeft() / 100 : 
            10 - 10 * countdown::getTimeLeft() / powerselection  // time in deciseconds
        );
    }
}


inline void updateDisplayNumber(char timeLeft) {
    char secs = digits[timeLeft / 10 % 10 & 0xf] | 1; // 0b1 because of the decimal point. 

    if(timeLeft > 100) {
        updateLargeDisplay(secs, digits[timeLeft / 100 % 10 & 0xf]);
    } else {
        updateLargeDisplay(digits[timeLeft % 10 & 0xf], secs);
    }

    large_segment_display::nextDigit();
}

char lastDisplayDigit1 = -1, lastDisplayDigit2 = -1; // -1 because it is the display's default
void updateLargeDisplay(char displayDigit1, char displayDigit2) {
    if(lastDisplayDigit1 == displayDigit1 && lastDisplayDigit2 == displayDigit2) {
        return;
    }

    large_segment_display::writeDigit(lastDisplayDigit1 = displayDigit1);
    large_segment_display::writeDigit(lastDisplayDigit2 = displayDigit2);
}
