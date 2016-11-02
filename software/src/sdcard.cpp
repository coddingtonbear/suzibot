#include <SD.h>
#include "sdcard.h"


File openFile;


void initSdCard() {
    if(! SD.begin(CS_SD)) {
        Serial.println("ERROR initializing SD.");
    } else {
        if (!SD.exists("/db")) {
            SD.mkdir("/db");
        }
    }
}


void logMessage(char* message) {
    openFile = SD.open(FILENAME_LOG, FILE_WRITE);
    openFile.println(message);
    openFile.close();
}
