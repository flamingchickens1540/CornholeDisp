
namespace countdown {

    /**
     * @brief Does the prerequisites for the countdown
     *
     */
    void initialize(unsigned long* cntdwnDuration);

    /**
     * @brief returns the time since the start of the countdown
     * 
     * @return unsigned long: time since countdown
     */
    inline unsigned long getEndTime();

    void reset();

    /**
     * @brief get the time left
     * 
     * @return unsigned long: time left
     */
    unsigned long getTimeLeft();
}