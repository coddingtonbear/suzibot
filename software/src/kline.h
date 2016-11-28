#include <Arduino.h>
#include <EventManager.h>
#include <SC16IS750.h>
#include "service.h"


class KLineManager: public StandardService
{
    public:
        KLineManager(EventManager& evt_mgr, SC16IS750& serial_port, uint16_t baud_rate);
        void begin();
        void cycle();
    private:
        SC16IS750 port;
        uint16_t baud;
        EventManager event_manager;
};
