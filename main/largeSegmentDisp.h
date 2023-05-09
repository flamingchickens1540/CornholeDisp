// Documentation to be written
namespace large_segment_display {
    void initialize(char latPin, char clkPin, char serPin);
    inline void startPin(char pin);
    void nextDigit();
    void nextSeg();
    inline void tickPin(char pin);
    void writeSeg(bool on);
    void writeDigit(char segs);
}