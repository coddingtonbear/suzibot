#include "kline.h"


KLineManager::KLineManager(SC16IS750& serial_port) {
    port = serial_port;
}

void KLineManager::begin(uint16_t baud) {
    port.begin(baud);
    port.flush();
    if(! port.ping()) {
        Serial.println("ERROR initializing K-Line.");
    }
}

void KLineManager::cycle() {
}
