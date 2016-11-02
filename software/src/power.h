#include "Arduino.h"

// Power Management Settings
#define ENABLE_LEVEL_CONVERTER 15
#define RX_VOLTAGE A7
#define TX_POWER_OFF 22

void powerOff();
uint8_t read12v();
long read5v();
void updateVoltage12v();
