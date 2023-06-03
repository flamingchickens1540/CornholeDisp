# CornholeDisp
This is code for an arduino that controls the display.

If you would like to recreate the setup used, here is the list of items used :
 - 2x 7-Segment large display the one used can be found [here](https://www.sparkfun.com/products/8530)
 - 5x female-male jumper wires
 - 12v power supply (I used a VRM)

### main
This file defines all of the constants such as pins and countdown duration.
The array called digits contains information on how a hexa-numerical digit should be displayed (0-f)

### largeDisplay
This is a simple file, but a lot of the code can be understood. I highly recommemend viewing [this](https://www.arduino.cc/reference/en/) to learn more of the technical aspects to c++ arduino coding.
nextDigit() turns the latch pin off and on to tell the display driver that it needs to refresh the display, and writeDigit(char digit) writes what the display should show.
