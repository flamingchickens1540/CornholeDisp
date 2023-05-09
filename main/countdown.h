
namespace countdown {

    void initialize(char countdownPin);

    inline bool isOff();

    inline unsigned long startTime();

    void tick();

    unsigned long getTimeLeft();
}