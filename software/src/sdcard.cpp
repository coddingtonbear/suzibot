#include "sdcard.h"


SDCardManager::SDCardManager(uint8_t pin_no, unsigned long baud, String log_filename) {
    pin_number = pin_no;
    spi_baud = baud;
    log_file_name = log_filename;

    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, HIGH);
}

void SDCardManager::begin() {
    if(! SD.begin(pin_number)) {
        Serial.println("ERROR initializing SD.");
    } else {
        if (!SD.exists("/db")) {
            SD.mkdir("/db");
        }
    }
}

void SDCardManager::cycle() {
}

void SDCardManager::logMessage(String message) {
    /*
    openFile = SD.open(FILENAME_LOG, FILE_WRITE);
    openFile.println(message);
    openFile.close();
    */
}
