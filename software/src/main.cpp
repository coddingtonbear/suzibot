#include <SC16IS750.h>
#include <SD.h>
#include <TinyGPS++.h>
#include <SPI.h>

#include "pitches.h"

// WIFI Settings
#define RX_WIFI 0
#define TX_WIFI 1
#define FILENAME_AP_PASSWORDS_DB "/db/ap.db"

// GPS Settings
#define CS_GPS A0
#define ENABLE_GPS 3
#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"
TinyGPSPlus gps;
SC16IS750 gpsSerial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
    //14592000UL
);

// SD Card Settings
#define CS_SD 10
#define FILENAME_LOG "/log.txt"
File logFile;

// K-Line Settings
#define CS_KLINE A1

// Piezo Settings
#define PIEZO 6
const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4};

// Power Management Settings
#define RX_VOLTAGE A7
#define TX_POWER_OFF 6
double currentVoltage = 0;

void playNotes(const int* notes, uint8_t length) {
    for(unsigned int i = 0; i < length/sizeof(notes[0]); i++) {
        tone(PIEZO, notes[i], 250);
        delay(250);
    }
    Serial.println();
}

void setup() {
    SPI.begin();
    Serial.begin(115200);

    /* SD */
    /*
    pinMode(CS_SD, OUTPUT);
    SD.begin(CS_SD);
    if (!SD.exists("/db")) {
        SD.mkdir("/db");
    }*/

    /* GPS */
    pinMode(10, OUTPUT);
    pinMode(CS_GPS, OUTPUT);
    gpsSerial.begin(9600);
    gpsSerial.flush();
    gpsSerial.printAllRegisters();

    char configureGps[] = (
        "$PMTK251,9600*17\r\n"
        "$PMTK314,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2D\r\n"
    );
    for(uint8_t i = 0; i < sizeof(configureGps)/sizeof(configureGps[0]); i++) {
        gpsSerial.write(configureGps[i]);
    }

    unsigned int outputCount = 0;

    while(1){
        uint8_t bytesAvailable = gpsSerial.available();
        if(bytesAvailable > 0) {
            gpsSerial.printRegister(SC16IS750_REG_LCR);
            Serial.print("Reading ");
            Serial.print(bytesAvailable);
            Serial.print(" bytes: ");
            for(int i = 0; i < bytesAvailable; i++) {
                Serial.print((char)gpsSerial.read());
            }
            Serial.println("");
        }
    }

    /* Piezo */
    pinMode(6, OUTPUT);

    playNotes(STARTUP, sizeof(STARTUP));
}

void updateLocation() {
    while(gpsSerial.available()) {
        byte value = gpsSerial.read();
        Serial.print(value, HEX);
        gps.encode(value);
    }
}

void logMessage(char* message) {
    logFile.write(message);
    logFile.write('\n');
    logFile.flush();
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

void loop() {
    updateLocation();

    /*
    updateVoltage();
    if(currentVoltage < 11.5) {
        powerOff();
    }*/
    delay(1000);
}

