#include <SC16IS750.h>
#include <SdFat.h>
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

// GPS Settings
#define CS_GPS 3
#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"
TinyGPSPlus gps;
SC16IS750 gpsSerial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
);

// SD Card Settings
#define CS_SD 10
#define FILENAME_LOG "log.txt"
SdFat sd;
File openFile;

// K-Line Settings
#define CS_KLINE A5
SC16IS750 klineSerial = SC16IS750(
    CS_KLINE,
    SC16IS750_CHAN_A,
    6000000UL
);

// Piezo Settings
#define PIEZO 8
const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4};

// Power Management Settings
#define RX_VOLTAGE A4
#define TX_POWER_OFF A6
double currentVoltage = 0;

void playNotes(const int* notes, uint8_t length) {
    /*
    for(unsigned int i = 0; i < length/sizeof(notes[0]); i++) {
        tone(PIEZO, notes[i], 250);
        delay(250);
    }
    */
}

void setup() {
    pinMode(CS_SD, OUTPUT);
    pinMode(CS_GPS, OUTPUT);
    pinMode(CS_WIFI, OUTPUT);
    pinMode(CS_KLINE, OUTPUT);
    pinMode(PIEZO, OUTPUT);
    pinMode(RX_VOLTAGE, INPUT);
    pinMode(TX_POWER_OFF, OUTPUT);

    digitalWrite(CS_SD, HIGH);
    digitalWrite(CS_GPS, HIGH);
    digitalWrite(CS_WIFI, HIGH);
    digitalWrite(CS_KLINE, HIGH);
    digitalWrite(TX_POWER_OFF, LOW);

    SPI.begin();
    Serial.begin(115200);

    /* SD */
    digitalWrite(CS_SD, LOW);
    if(! sd.begin(CS_SD, SPI_CLOCK_DIV8)) {
        Serial.println("ERROR initializing SD.");
    }
    if (!sd.exists("/db")) {
        sd.mkdir("/db");
    }
    digitalWrite(CS_SD, HIGH);
    for(int i = 0; i < 16; i++) {
        SPI.transfer(0xff);
    }

    /* GPS */
    gpsSerial.begin(9600);
    gpsSerial.flush();
    char configureGps[] = (
        "$PMTK251,9600*17\r\n"
        "$PMTK314,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"
    );
    for(uint8_t i = 0; i < sizeof(configureGps)/sizeof(configureGps[0]); i++) {
        gpsSerial.write(configureGps[i]);
    }

    /* WIFI */
    wifiSerial.begin(9600);

    /* K-Line */
    klineSerial.begin(10400);

    playNotes(STARTUP, sizeof(STARTUP));
}

void updateLocation() {
    while(gpsSerial.available()) {
        byte value = gpsSerial.read();
        Serial.print((char)value);
        gps.encode(value);
    }
}

void logMessage(char* message) {
    digitalWrite(CS_SD, LOW);
    openFile = sd.open(FILENAME_LOG, FILE_WRITE);
    openFile.println(message);
    openFile.close();
    digitalWrite(CS_SD, HIGH);
    for(int i = 0; i < 16; i++) {
        SPI.transfer(0xff);
    }
}

void updateVoltage() {
    const int sampleCount = 5;
    int value = analogRead(RX_VOLTAGE);
    double voltage = (double)value / (double)43;

    if (currentVoltage > 0) {
        currentVoltage -= currentVoltage / sampleCount;
        currentVoltage += voltage / sampleCount;
    } else {
        currentVoltage = voltage;
    }
}

void powerOff() {
    digitalWrite(TX_POWER_OFF, true);
    playNotes(SHUTDOWN, sizeof(SHUTDOWN));
}

void bridgeSerial(SC16IS750 serial) {
    while (serial.available()) {
        Serial.write(serial.read());
    }
    while (Serial.available()) {
        serial.write(Serial.read());
    }
}

void loop() {
    //updateLocation();
    //updateVoltage();

    bridgeSerial(gpsSerial);

    /*
     * LOGGING
     *
    digitalWrite(CS_SD, LOW);
    char buf[8];
    sprintf(buf, "%03i", gps.time.value());
    logMessage(buf);
    Serial.println(buf);
    digitalWrite(CS_SD, HIGH);
    for(int i = 0; i < 8; i++) {
        SPI.transfer(0xff);
    }
    Serial.println("OK");
    */

    /* 
     * POWER OFF MANAGEMENT
     *
     * If power drops below 11.5V, shut down immediately.
     */
    if(currentVoltage > 9.0 && currentVoltage < 11.5) {
        Serial.println(currentVoltage);
        powerOff();
    }
}

