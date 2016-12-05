#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "service.h"

class WifiManager: public StandardService
{
    public:
        WifiManager(EventManager* evt_mgr, Stream* serial_port);
        void begin();
        void cycle();
        bool ready();
        bool failed();
        bool busy();
        bool timeout();
        String get_data(bool reset=true);
        String get_command();
        void command(String command_name, int timeout=5000);
    private:
        EventManager* event_manager;
        Stream* port;
        String command_name;
        String command_data;
        enum WifiCommandStatus {
            COMMAND_READY,
            COMMAND_TIMEOUT,
            COMMAND_OK,
            COMMAND_FAILED,
            COMMAND_BUSY
        };
        WifiCommandStatus status;
        int command_timeout;
        bool initialized;
};
