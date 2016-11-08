#include "power.h"


PowerManager::PowerManager(
    uint8_t regulator_3v3_pin_no,
    uint8_t level_converter_pin_no,
    uint8_t voltage_12v_pin_no,
    uint8_t power_off_pin_no
) {
    level_converter_pin = level_converter_pin_no;
    pinMode(level_converter_pin, OUTPUT);
    digitalWrite(level_converter_pin, LOW);

    regulator_3v3_pin = regulator_3v3_pin_no;
    pinMode(regulator_3v3_pin, OUTPUT);
    digitalWrite(regulator_3v3_pin, LOW);

    voltage_12v_pin = voltage_12v_pin_no;
    pinMode(voltage_12v_pin, INPUT);

    power_off_pin = power_off_pin_no;
    pinMode(power_off_pin, OUTPUT);
    digitalWrite(power_off_pin, LOW);
}

void PowerManager::begin() {
    delay(1000);
    digitalWrite(level_converter_pin, HIGH);
    digitalWrite(regulator_3v3_pin, HIGH);
}

void PowerManager::cycle() {
    updateVoltage12v();
}

void PowerManager::powerOff() {
    digitalWrite(power_off_pin, true);
}


uint8_t PowerManager::read12v() {
    return analogRead(voltage_12v_pin);
}


void PowerManager::updateVoltage12v() {
    const int sampleCount = 5;
    int value = read12v();
    double voltage = (double)value / (double)43;

    if (voltage_12v > 0) {
        voltage_12v -= voltage_12v / sampleCount;
        voltage_12v += voltage / sampleCount;
    } else {
        voltage_12v = voltage;
    }
}

long PowerManager::read5v() {
    // Read 1.1V reference against AVcc
    // set the reference to Vcc and the measurement to the internal 1.1V reference
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);

    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Start conversion
    while (bit_is_set(ADCSRA,ADSC)); // measuring

    uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
    uint8_t high = ADCH; // unlocks both

    long result = (high<<8) | low;

    result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
    return result; // Vcc in millivolts
}
