#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "sdcard.h"
#include "service.h"

class WifiManager: public StandardService
{
    public:
        WifiManager(
            EventManager* evt_mgr,
            Stream* serial_port,
            SDCardManager *sd_mgr
        );
        void begin();
        void cycle();
        bool ready();
        bool failed();
        bool busy();
        bool timeout();
        String get_data(bool reset=true);
        String get_command();
        void command(
            String cmd_name,
            String cmd_callback_name="",
            int timeout=5000
        );
    private:
        EventManager* event_manager;
        SDCardManager* sd_manager;
        Stream* port;
        String command_name;
        String command_data;
        String command_callback_name;
        enum WifiCommandStatus {
            COMMAND_READY,
            COMMAND_TIMEOUT,
            COMMAND_OK,
            COMMAND_FAILED,
            COMMAND_BUSY
        };
        enum WifiCommandCallback {
        };
        WifiCommandStatus status;
        void call_command_callback(
            WifiCommandStatus status,
            String command_data
        );
        int command_timeout;
        bool initialized;
};
