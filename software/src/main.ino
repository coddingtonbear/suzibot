#include <SPI.h>
#include "audio.h"
#include "gps.h"
#include "kline.h"
#include "sdcard.h"
#include "wifi.h"
#include "power.h"

// Notification Settings
#define LED 1

void bridgeSerial(SC16IS750& serial, bool send = true) {
    while (serial.available()) {
        uint8_t value = serial.read();
        Serial.write(value);
    }
    if(send) {
        while (Serial.available()) {
            serial.write(Serial.read());
        }
    }
}

void setup() {
    pinMode(ENABLE_LEVEL_CONVERTER, OUTPUT);
    pinMode(CS_SD, OUTPUT);
    pinMode(CS_GPS, OUTPUT);
    pinMode(DISABLE_GPS, OUTPUT);
    pinMode(CS_WIFI, OUTPUT);
    pinMode(CS_KLINE, OUTPUT);
    pinMode(PIEZO, OUTPUT);
    pinMode(RX_VOLTAGE, INPUT);
    pinMode(TX_POWER_OFF, OUTPUT);

    pinMode(LED, OUTPUT);

    digitalWrite(LED, HIGH);
    digitalWrite(ENABLE_LEVEL_CONVERTER, HIGH);
    digitalWrite(CS_SD, HIGH);
    digitalWrite(CS_GPS, HIGH);
    digitalWrite(DISABLE_GPS, LOW);
    digitalWrite(CS_WIFI, HIGH);
    digitalWrite(CS_KLINE, HIGH);
    digitalWrite(TX_POWER_OFF, LOW);

    SPI.begin();
    Serial.begin(1000000);

    /* SD */
    Serial.println("Initializing SD...");
    initSdCard();

    /* K-Line */
    Serial.println("Initializing K-Line...");
    initKline();

    /* WIFI */
    Serial.println("Initializing WIFI...");
    initWifi();

    /* GPS */
    Serial.println("Initializing GPS...");
    initGps();

    //playNotes(STARTUP, sizeof(STARTUP));
    Serial.println("Ready.");
}

void loop() {
    updateLocation();
    //updateVoltage();
    //wifiSerial.flush();
    //bridgeSerial(wifiSerial);
    //bridgeSerial(gpsSerial, false);

    //Serial.println(getWifi().getAPList());

    /*
     * LOGGING
     */
    //char buf[8];
    //sprintf(buf, "%03u", gps.time.value());
    //logMessage(buf);
    //Serial.println(buf);

    /* 
     * POWER OFF MANAGEMENT
     *
     * If power drops below 11.5V, shut down immediately.
     
    if(voltage12v > 9.0 && voltage12v < 11.5) {
        Serial.println(voltage12v);
        powerOff();
    }*/
}

