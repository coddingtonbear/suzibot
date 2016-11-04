#include <Arduino.h>
#include <SC16IS750.h>
#include <TinyGPS++.h>
#include "service.h"

#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"


class GpsManager: public StandardService
{
    public:
        GpsManager(SC16IS750& serial_port, uint16_t baud_rate, uint8_t disable_gps_pin);
        void begin();
        void cycle();
        void disable();
        void enable();
    private:
        void updateLocation();

        uint16_t baud;
        uint8_t disable_gps;
        SC16IS750 port;
        TinyGPSPlus gps;
};
