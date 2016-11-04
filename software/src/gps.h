#include <SC16IS750.h>
#include <TinyGPS++.h>
#include <Arduino.h>

#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"


class GpsManager
{
    public:
        GpsManager(SC16IS750& serial_port, uint8_t disable_gps_pin);
        void begin(uint16_t baud);
        void cycle();
        void disable();
        void enable();
    private:
        void updateLocation();

        uint8_t disable_gps;
        SC16IS750 port;
        TinyGPSPlus gps;
};
