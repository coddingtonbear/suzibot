#include <Arduino.h>
#include <ESP8266.h>
#include <SC16IS750.h>
#include "service.h"

class WifiManager: public StandardService
{
    public:
        WifiManager(SC16IS750& serial_port, uint16_t baud_rate);
        void begin();
        void cycle();
    private:
        uint16_t baud;
        SC16IS750 port;
        ESP8266 wifi;
};
