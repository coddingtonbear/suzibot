#include <EventManager.h>
#include <SC16IS750.h>
#include <SPI.h>

#include "audio.h"
#include "gps.h"
#include "kline.h"
#include "sdcard.h"
#include "wifi.h"
#include "power.h"

#define LED 15
#define PIEZO 0

#define DISABLE_GPS 2
#define ENABLE_LEVEL_CONVERTER 1
#define ENABLE_3V3_REGULATOR A0
#define RX_VOLTAGE A7
#define TX_POWER_OFF 22

#define CS_SD 4
#define CS_KLINE 23
#define CS_WIFI 3
#define CS_GPS 3

EventManager event_manager;

AudioManager audio_mgr = AudioManager(event_manager, PIEZO);
SDCardManager sd_mgr = SDCardManager(event_manager, CS_SD);
PowerManager power_mgr = PowerManager(
    event_manager,
    ENABLE_3V3_REGULATOR,
    ENABLE_LEVEL_CONVERTER,
    RX_VOLTAGE,
    TX_POWER_OFF
);

SC16IS750 kLine_serial = SC16IS750(
    CS_KLINE,
    SC16IS750_CHAN_A,
    6000000UL
);
KLineManager kline_mgr = KLineManager(event_manager, kLine_serial, 10400);

SC16IS750 gps_serial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
);
GpsManager gps_mgr = GpsManager(event_manager, gps_serial, 9600, DISABLE_GPS);

SC16IS750 wifi_serial = SC16IS750(
    CS_WIFI,
    SC16IS750_CHAN_B,
    14745600UL
);
WifiManager wifi_mgr = WifiManager(event_manager, wifi_serial, 9600);

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
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);

    SPI.begin();
    Serial.begin(1000000);

    /* Audio */
    Serial.println("Initializing Audio...");
    audio_mgr.begin();

    /* Power Management */
    Serial.println("Initializing Power Manager...");
    power_mgr.begin();

    /* SD */
    Serial.println("Initializing SD...");
    sd_mgr.begin();

    /* K-Line */
    Serial.println("Initializing K-Line...");
    kline_mgr.begin();

    /* WIFI */
    Serial.println("Initializing WIFI...");
    wifi_mgr.begin();

    /* GPS */
    Serial.println("Initializing GPS...");
    gps_mgr.begin();

    Serial.println("Ready.");
}

void loop() {
    wifi_mgr.cycle();
    kline_mgr.cycle();
    gps_mgr.cycle();
    sd_mgr.cycle();
    audio_mgr.cycle();
    power_mgr.cycle();

    //wifiSerial.flush();
    //bridgeSerial(wifiSerial);
    //bridgeSerial(gpsSerial, false);

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

