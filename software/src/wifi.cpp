#include "wifi.h"


WifiManager::WifiManager(EventManager& evt_mgr, SC16IS750& serial_port, uint16_t baud_rate) {
    port = serial_port;
    baud = baud_rate;
    event_manager = evt_mgr;
    initialized = false;
}

void WifiManager::begin() {
    port.begin(baud);
    if(port.ping()) {
        initialized = true;
    } else {
        Serial.println("ERROR initializing WIFI.");
    }
}

void WifiManager::cycle() {
}
