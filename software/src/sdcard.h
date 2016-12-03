#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include <SD.h>
#include "service.h"

#define FILENAME_LOG "log.txt"

class SDCardManager: public StandardService
{
    public:
        SDCardManager(
            EventManager& evt_mgr,
            uint8_t pin_no,
            unsigned long baud = 250000,
            String log_filename = FILENAME_LOG
        );
        void begin();
        void cycle();
        void logMessage(String message);
    private:
        void assert();
        void deassert();

        uint8_t pin_number;
        unsigned long spi_baud;
        String log_file_name;
        File log_file;
        EventManager event_manager;
};
