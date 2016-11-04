#include <SC16IS750.h>
#include <Arduino.h>


class KLineManager
{
    public:
        KLineManager(SC16IS750& serial_port);
        void begin(uint16_t baud);
        void cycle();
    private:
        SC16IS750 port;
};
