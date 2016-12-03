#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "service.h"

// Power Management Settings

class PowerManager: public StandardService
{
    public:
        PowerManager(
            EventManager& evt_mgr,
            uint8_t regulator_3v3_pin_no,
            uint8_t level_converter_pin_no,
            uint8_t voltage_12v_pin_no,
            uint8_t power_off_pin_no
        );
        void begin();
        void cycle();
        void powerOff();
        uint8_t read12v();
        long read5v();
    private:
        void updateVoltage12v();

        uint8_t regulator_3v3_pin;
        uint8_t level_converter_pin;
        uint8_t voltage_12v_pin;
        uint8_t power_off_pin;
        uint8_t voltage_12v;
        long voltage_5v;
        EventManager event_manager;
};
