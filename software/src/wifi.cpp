#include "wifi.h"


WifiManager::WifiManager(SC16IS750& serial_port, uint16_t baud_rate) {
    port = serial_port;
    baud = baud_rate;
}

void WifiManager::begin() {
    port.begin(baud);
    if(! port.ping()) {
        Serial.println("ERROR initializing WIFI.");
    }
}

void WifiManager::cycle() {
}
