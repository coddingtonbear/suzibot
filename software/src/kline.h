#include <SC16IS750.h>
#include <Arduino.h>
#include "service.h"


class KLineManager: public StandardService
{
    public:
        KLineManager(SC16IS750& serial_port, uint16_t baud_rate);
        void begin();
        void cycle();
    private:
        SC16IS750 port;
        uint16_t baud;
};
