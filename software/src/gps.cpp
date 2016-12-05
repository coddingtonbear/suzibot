#include "gps.h"


GpsManager::GpsManager(EventManager* evt_mgr, Stream* serial_port, uint8_t disable_gps_pin):
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
        if (gps.location.isUpdated()) {
            // Build a JSON object having this data
            String* output = new String();
            StaticJsonBuffer<200> jsonBuffer;
            JsonObject& root = jsonBuffer.createObject();
            root["lat"] = double_with_n_digits(gps.location.lat(), 6);
            root["lng"] = double_with_n_digits(gps.location.lng(), 6);
            root["alt"] = gps.altitude.meters();
            root["year"] = gps.date.year();
            root["month"] = gps.date.month();
            root["day"] = gps.date.day();
            root["hr"] = gps.time.hour();
            root["min"] = gps.time.minute();
            root["sec"] = gps.time.second();
            root["csec"] = gps.time.centisecond();
            root.printTo(*output);

            // Emit the event
            event_manager->queueEvent(
                EventManager::kEventNewGPSCoordinate,
                output
            );
        }
    }
}

void GpsManager::updateLocation() {
    while(port->available()) {
        byte value = port->read();
        gps.encode(value);
    }
}
