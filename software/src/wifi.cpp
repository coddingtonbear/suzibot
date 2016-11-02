#include "wifi.h"


SC16IS750 wifiSerial = SC16IS750(
    CS_WIFI,
    SC16IS750_CHAN_B,
    14745600UL
);
ESP8266 wifi = ESP8266(wifiSerial);


void initWifi() {
    wifiSerial.begin(9600);
    if(! wifiSerial.ping()) {
        Serial.println("ERROR initializing WIFI.");
    } else {
        wifi.begin();
    }
}

ESP8266 getWifi() {
    return wifi;
}
