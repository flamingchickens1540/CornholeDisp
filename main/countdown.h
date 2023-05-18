
namespace countdown {

    /**
     * @brief Does the prerequisites for the countdown
     * 
     * @param countdownPin countdown pin
     */
    void initialize(char countdownPin, unsigned long* cntdwnDuration);

    /**
     * @brief If the display 
     * 
     * @return true: the countdown is on
     * @return false: the countdown is off
     */
    inline bool isOn();

    /**
     * @brief returns the time since the start of the countdown
     * 
     * @return unsigned long: time since countdown
     */
    inline unsigned long getEndTime();

    void tick();

    /**
     * @brief get the time left
     * 
     * @return unsigned long: time left
     */
    unsigned long getTimeLeft();
}