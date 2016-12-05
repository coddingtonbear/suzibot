#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <EventManager.h>
#include <TinyGPS++.h>
#include "service.h"

#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"


class GpsManager: public StandardService
{
    public:
        GpsManager(EventManager* evt_mgr, Stream* serial_port, uint8_t disable_gps_pin);
        void begin();
        void cycle();
        void disable();
        void enable();
    private:
        void updateLocation();

        uint8_t disable_gps;
        Stream* port;
        TinyGPSPlus gps;
        EventManager* event_manager;
        bool initialized;
};
