#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <EventManager.h>
#include "service.h"

class SystemManager: public StandardService
{
    public:
        SystemManager(
            EventManager* evt_mgr,
            uint8_t led_pin_no
        );
        void begin();
        void cycle();
        int get_free_memory();
    private:
        EventManager* event_manager;
        unsigned long last_memory_check;
        int last_memory_size;
        uint8_t led_pin;
};
