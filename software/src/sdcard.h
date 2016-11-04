#include <SD.h>
#include <Arduino.h>

#define FILENAME_LOG "log.txt"

class SDCardManager
{
    public:
        SDCardManager(
            uint8_t pin_no,
            unsigned long baud = 250000,
            String log_filename = FILENAME_LOG
        );
        void begin();
        void cycle();
        void logMessage(String message);
    private:
        uint8_t pin_number;
        unsigned long spi_baud;
        String log_file_name;
        File log_file;
};
