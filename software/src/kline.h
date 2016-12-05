#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "service.h"


class KLineManager: public StandardService
{
    public:
        KLineManager(EventManager* evt_mgr, Stream* serial_port);
        void begin();
        void cycle();
    private:
        Stream* port;
        uint16_t baud;
        EventManager* event_manager;
        bool initialized;
};
