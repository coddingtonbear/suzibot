#include "gps.h"


GpsManager::GpsManager(EventManager& evt_mgr, SC16IS750& serial_port, uint16_t baud_rate, uint8_t disable_gps_pin) {
    port = serial_port;
    disable_gps = disable_gps_pin;
    baud = baud_rate;
    event_manager = evt_mgr;
    initialized = false;

    pinMode(disable_gps, OUTPUT);
    digitalWrite(disable_gps, HIGH);
}

void GpsManager::disable() {
    digitalWrite(disable_gps, HIGH);
}

void GpsManager::enable() {
    digitalWrite(disable_gps, LOW);
}

void GpsManager::begin() {
    enable();

    port.begin(9600);
    if(port.ping()) {
        char configureGps[] = (
            //"$PMTK251,9600*17\r\n"
            //"$PMTK314,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
            //"$PMTK314,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2D\r\n"
            "$PMTK314,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2E\r\n"
            //"$PMTK314,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"
            //"$PMTK314,-1*04\r\n"
        );
        for(uint8_t i = 0; i < sizeof(configureGps)/sizeof(configureGps[0]); i++) {
            port.write(configureGps[i]);
        }
        initialized = true;
    } else {
        Serial.println("ERROR initializing GPS.");
    }
}

void GpsManager::cycle() {
    if (initialized) {
        updateLocation();
    }
}

void GpsManager::updateLocation() {
    while(port.available()) {
        byte value = port.read();
        gps.encode(value);
    }
}
