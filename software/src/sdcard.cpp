#include "sdcard.h"


SPISettings sd_settings(250000, MSBFIRST, SPI_MODE0);


SDCardManager::SDCardManager(EventManager& evt_mgr, uint8_t pin_no, unsigned long baud, String log_filename) {
    pin_number = pin_no;
    spi_baud = baud;
    log_file_name = log_filename;
    event_manager = evt_mgr;

    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, HIGH);
}

void SDCardManager::begin() {
    assert();

    if(! SD.begin(pin_number)) {
        Serial.println("ERROR initializing SD.");
    } else {
        if (!SD.exists("/db")) {
            SD.mkdir("/db");
        }
    }

    deassert();
}

void SDCardManager::cycle() {
}

void SDCardManager::assert() {
    SPI.beginTransaction(sd_settings);
}

void SDCardManager::deassert() {
    SPI.endTransaction();
}

void SDCardManager::logMessage(String message) {
    //openFile = SD.open(FILENAME_LOG, FILE_WRITE);
    //openFile.println(message);
    //openFile.close();
}
