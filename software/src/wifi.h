#include <ESP8266.h>
#include <SC16IS750.h>
#include <Arduino.h>

class WifiManager {
    public:
        WifiManager(SC16IS750& serial_port);
        void begin(uint16_t baud);
        void cycle();
    private:
        SC16IS750 port;
        ESP8266 wifi;
};
