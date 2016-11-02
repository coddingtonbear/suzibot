#include "power.h"


double voltage12v = 0;
double voltage5v = 0;


void powerOff() {
    digitalWrite(TX_POWER_OFF, true);
}


uint8_t read12v() {
    return analogRead(RX_VOLTAGE);
}


void updateVoltage12v() {
    const int sampleCount = 5;
    int value = read12v();
    double voltage = (double)value / (double)43;

    if (voltage12v > 0) {
        voltage12v -= voltage12v / sampleCount;
        voltage12v += voltage / sampleCount;
    } else {
        voltage12v = voltage;
    }
}


long read5v() {
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
