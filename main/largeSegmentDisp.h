//Driver used https://www.sparkfun.com/products/13279
//Display used https://www.sparkfun.com/products/8530

namespace large_segment_display {
    /**
     * @brief Does all the necessary prerequisites for the driver display
     * 
     * @param latPin latch pin
     * @param clkPin clock pin
     * @param serPin serial pin
     */
    void initialize(char latPin, char clkPin, char serPin);

    /**
     * @brief Sets the pinMode to OUTPUT and digitalwrites the pin to on
     * 
     * @param pin Pin to start
     */
    inline void startPin(char pin);

    /**
     * @brief Write to the digit and moves to the next
     * @remarks It write the digit, however I am not sure if it will go to the next
     */
    void nextDigit();

    /**
     * @brief Write the current output of serPin, and switches to the next segment or decimal point
     */
    void nextSeg();

    /**
     * @brief briefly turns the pin off and on
     * 
     * @param pin pin to tick
     */
    inline void tickPin(char pin);

    /**
     * @brief Turn the serial pin on or off corresponding to LOW HIGH outputs, then call function next Seg
     * 
     * @param on whether it should be on or off
     */
    void writeSeg(bool on);

    /**
     * @brief Writes the segments and decimal point of the current digit and does not move to the next digit.
     * 
     * @param segs an 8 bit number corresponding to the 8 segments (with the decimal point) that will be written to. 
     */
    void writeDigit(char segs);
}