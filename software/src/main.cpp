#include <SC16IS750.h>
#include <SD.h>
#include <SPI.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#include "pitches.h"

// WIFI Settings
#define RX_WIFI 0
#define TX_WIFI 1
#define FILENAME_AP_PASSWORDS_DB "/db/ap.db"

// GPS Settings
#define CS_GPS A0
#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"
TinyGPSPlus gps;
SC16IS750 gpsSerial = SC16IS750(
    SC16IS750_PROTOCOL_SPI,
    CS_GPS,
    14745600U
);

// SD Card Settings
#define CS_SD 10
#define FILENAME_LOG "/log.txt"
File logFile;

// K-Line Settings
#define CS_KLINE A1

// Piezo Settings
#define PIEZO 6
const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4, NULL};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4, NULL};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4, NULL};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4, NULL};

// Power Management Settings
#define RX_VOLTAGE A7
#define TX_POWER_OFF 6
double currentVoltage = 0;

void playNotes(const int* notes) {
    for(unsigned int i = 0; i < 10; i++) {
        if(notes[i] == NULL) {
            break;
        }
        tone(PIEZO, notes[i], 250);
        delay(250);
    }
    Serial.println();
}

void setup() {
    SPI.begin();
    Serial.begin(9600);

    /* SD */
    /*
    pinMode(CS_SD, OUTPUT);
    SD.begin(CS_SD);
    if (!SD.exists("/db")) {
        SD.mkdir("/db");
    }*/

    /* GPS */
    pinMode(CS_GPS, OUTPUT);
    gpsSerial.begin(9600);

    while(1){
        /*
        Serial.print("LSR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_LSR), BIN);
        Serial.print("IER: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_IER), BIN);
        Serial.print("FCR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_FCR), BIN);
        Serial.print("MCR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_MCR), BIN);
        Serial.print("LCR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_LCR), BIN);
        Serial.print("RXLVL: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_RXLVL), BIN);
        uint8_t temp_lcr = gpsSerial.ReadRegister(SC16IS750_REG_LCR);
        gpsSerial.WriteRegister(SC16IS750_REG_LCR, 0xbf);
        Serial.print("LCR (temp): ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_LCR), BIN);
        Serial.print("EFR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_EFR), BIN);
        gpsSerial.WriteRegister(SC16IS750_REG_LCR,temp_lcr);
        Serial.print("LCR: ");
        Serial.println(gpsSerial.ReadRegister(SC16IS750_REG_LCR), BIN);

        if(gpsSerial.ping() != 1) {
            Serial.println("GPS Error");
            //playNotes(ERROR);
        } else {
            //Serial.println("GPS OK");
            //playNotes(CONNECTED);
        }
        */

        while(gpsSerial.available()) {
            Serial.print(gpsSerial.read(), HEX);
        }

        //Serial.println();
    }

    /* Piezo */
    pinMode(6, OUTPUT);

    playNotes(STARTUP);
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
    playNotes(SHUTDOWN);
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

