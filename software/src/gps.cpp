#include "gps.h"


GpsManager::GpsManager(EventManager& evt_mgr, Stream* serial_port, uint8_t disable_gps_pin):
    event_manager(evt_mgr),
    port(serial_port),
    disable_gps(disable_gps_pin),
    initialized(false)
{
    pinMode(disable_gps, OUTPUT);
    disable();
}

void GpsManager::disable() {
    digitalWrite(disable_gps, HIGH);
}

void GpsManager::enable() {
    digitalWrite(disable_gps, LOW);
}

void GpsManager::begin() {
    enable();

    char configureGps[] = (
        //"$PMTK251,9600*17\r\n"
        //"$PMTK314,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
        //"$PMTK314,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2D\r\n"
        "$PMTK314,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2E\r\n"
        //"$PMTK314,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"
        //"$PMTK314,-1*04\r\n"
    );
    for(uint8_t i = 0; i < sizeof(configureGps)/sizeof(configureGps[0]); i++) {
        port->write(configureGps[i]);
    }
    initialized = true;
}

void GpsManager::cycle() {
    if (initialized) {
        updateLocation();
    }
}

void GpsManager::updateLocation() {
    while(port->available()) {
        byte value = port->read();
        gps.encode(value);
    }
}
