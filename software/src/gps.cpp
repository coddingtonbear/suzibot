#include "gps.h"


GpsManager::GpsManager(SC16IS750& serial_port, uint8_t disable_gps_pin) {
    port = serial_port;
    disable_gps = disable_gps_pin;

    pinMode(disable_gps_pin, OUTPUT);
    digitalWrite(disable_gps_pin, LOW);
}

void GpsManager::disable() {
    digitalWrite(disable_gps, HIGH);
}

void GpsManager::enable() {
    digitalWrite(disable_gps, LOW);
}

void GpsManager::begin(uint16_t baud) {
    port.begin(9600);
    if(! port.ping()) {
        Serial.println("ERROR initializing GPS.");
    }
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
}

void GpsManager::cycle() {
    updateLocation();
}

void GpsManager::updateLocation() {
    while(port.available()) {
        byte value = port.read();
        gps.encode(value);
    }
}
