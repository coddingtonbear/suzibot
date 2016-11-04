#include "wifi.h"


WifiManager::WifiManager(SC16IS750& serial_port) {
    port = serial_port;
    wifi = ESP8266(port);
}

void WifiManager::begin(uint16_t baud) {
    port.begin(baud);
    if(! port.ping()) {
        Serial.println("ERROR initializing WIFI.");
    } else {
        wifi.begin();
    }
}

void WifiManager::cycle() {
}
