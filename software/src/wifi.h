#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "sdcard.h"
#include "service.h"

enum WifiCommandStatus {
    COMMAND_READY,
    COMMAND_TIMEOUT,
    COMMAND_OK,
    COMMAND_FAILED,
    COMMAND_BUSY
};

enum WifiStatus {
    WIFI_DISCONNECTED,
    WIFI_LIST_APS,
    WIFI_CONNECTION_ATTEMPT,
    WIFI_CONNECTED
};

struct WifiStateTransition
{
    WifiStateTransition(
        WifiStatus from,
        WifiStatus to,
        String name
    );
    String name;
    WifiStatus from;
    WifiStatus to;
};

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
        WifiStateTransition[] = {
            WifiStateTransition(
        }
        EventManager* event_manager;
        SDCardManager* sd_manager;
        Stream* port;
        String command_name;
        String command_data;
        String command_callback_name;
        WifiCommandStatus command_status;
        WifiStatus status;
        void call_command_callback(
            WifiCommandStatus status,
            String command_data
        );
        int command_timeout;
        bool initialized;
};
