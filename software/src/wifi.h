#include <Arduino.h>
#include <EventManager.h>
#include <SC16IS750.h>
#include "service.h"

class WifiManager: public StandardService
{
    public:
        WifiManager(EventManager& evt_mgr, SC16IS750& serial_port, uint16_t baud_rate);
        void begin();
        void cycle();
    private:
        EventManager event_manager;
        uint16_t baud;
        SC16IS750 port;
        bool initialized;
};
