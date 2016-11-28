#include "kline.h"


KLineManager::KLineManager(EventManager& evt_mgr, SC16IS750& serial_port, uint16_t baud_rate) {
    port = serial_port;
    baud = baud_rate;
    event_manager = evt_mgr;
}

void KLineManager::begin() {
    port.begin(baud);
    port.flush();
    if(! port.ping()) {
        Serial.println("ERROR initializing K-Line.");
    }
}

void KLineManager::cycle() {
}
