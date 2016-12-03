#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "service.h"

class WifiManager: public StandardService
{
    public:
        WifiManager(EventManager& evt_mgr, Stream* serial_port);
        void begin();
        void cycle();
    private:
        EventManager event_manager;
        Stream* port;
        bool initialized;
};
