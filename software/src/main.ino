#include <ESP8266.h>
#include <SC16IS750.h>
#include <SD.h>
#include <SPI.h>
#include <TinyGPS++.h>
#include "pitches.h"

// WIFI Settings
#define CS_WIFI 3
#define FILENAME_AP_PASSWORDS_DB "/db/ap.db"
SC16IS750 wifiSerial = SC16IS750(
    CS_WIFI,
    SC16IS750_CHAN_B,
    14745600UL
);
ESP8266 wifi = ESP8266(wifiSerial);

// GPS Settings
#define CS_GPS 3
#define DISABLE_GPS 2
#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"
TinyGPSPlus gps;
SC16IS750 gpsSerial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
);

// SD Card Settings
#define CS_SD 4
#define FILENAME_LOG "log.txt"
File openFile;

// K-Line Settings
#define CS_KLINE 23
SC16IS750 klineSerial = SC16IS750(
    CS_KLINE,
    SC16IS750_CHAN_A,
    6000000UL
);

// Notification Settings
#define LED 1
#define PIEZO 0
const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4};

// Power Management Settings
#define ENABLE_LEVEL_CONVERTER 15
#define RX_VOLTAGE A7
#define TX_POWER_OFF 22
double voltage12v = 0;
double voltage5v = 0;

void playNotes(const int* notes, uint8_t length) {
    for(unsigned int i = 0; i < length/sizeof(notes[0]); i++) {
        tone(PIEZO, notes[i], 250);
        //delay(250);
    }
}

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
    //Serial.begin(115200);
    Serial.begin(1000000);

    /* SD */
    Serial.println("Initializing SD...");
    if(true) {
        if(! SD.begin(CS_SD)) {
            Serial.println("ERROR initializing SD.");
        } else {
            if (!SD.exists("/db")) {
                SD.mkdir("/db");
            }
        }
    }

    /* K-Line */
    Serial.println("Initializing K-Line...");
    klineSerial.begin(10400);
    if(true) {
        klineSerial.flush();
        if(! klineSerial.ping()) {
            Serial.println("ERROR initializing K-Line.");
        }
    }

    /* WIFI */
    Serial.println("Initializing WIFI...");
    wifiSerial.begin(9600);
    if(true) {
        bridgeSerial(wifiSerial, false);
        if(! wifiSerial.ping()) {
            Serial.println("ERROR initializing WIFI.");
        } else {
            wifi.begin();
        }
    }

    /* GPS */
    Serial.println("Initializing GPS...");
    gpsSerial.begin(9600);
    if(true) {
        bridgeSerial(gpsSerial, false);
        if(! gpsSerial.ping()) {
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
            gpsSerial.write(configureGps[i]);
        }
    }

    //playNotes(STARTUP, sizeof(STARTUP));
    Serial.println("Ready.");
}

void updateLocation() {
    while(gpsSerial.available()) {
        byte value = gpsSerial.read();
        gps.encode(value);
    }
}

void logMessage(char* message) {
    openFile = SD.open(FILENAME_LOG, FILE_WRITE);
    openFile.println(message);
    openFile.close();
}

void updateVoltage12v() {
    const int sampleCount = 5;
    int value = analogRead(RX_VOLTAGE);
    double voltage = (double)value / (double)43;

    if (voltage12v > 0) {
        voltage12v -= voltage12v / sampleCount;
        voltage12v += voltage / sampleCount;
    } else {
        voltage12v = voltage;
    }
}

void powerOff() {
    digitalWrite(TX_POWER_OFF, true);
    playNotes(SHUTDOWN, sizeof(SHUTDOWN));
}

long readVcc() {
    // Read 1.1V reference against AVcc
    // set the reference to Vcc and the measurement to the internal 1.1V reference
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);

    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Start conversion
    while (bit_is_set(ADCSRA,ADSC)); // measuring

    uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
    uint8_t high = ADCH; // unlocks both

    long result = (high<<8) | low;

    result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
    return result; // Vcc in millivolts
}

void loop() {
    updateLocation();
    //updateVoltage();
    //wifiSerial.flush();
    //bridgeSerial(wifiSerial);
    //bridgeSerial(gpsSerial, false);

    Serial.println(wifi.getVersion());

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

