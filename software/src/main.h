#include <EventManager.h>
#include <SC16IS750.h>
#include <SPI.h>

#include "audio.h"
#include "gps.h"
#include "kline.h"
#include "pins.h"
#include "power.h"
#include "sdcard.h"
#include "system.h"
#include "wifi.h"

#define LED PIN_PD7
#define PIEZO PIN_PB0

#define DISABLE_GPS PIN_PB2
#define ENABLE_LEVEL_CONVERTER PIN_PB1
#define ENABLE_3V3_REGULATOR PIN_PA0
#define RX_VOLTAGE PIN_PA7
#define TX_POWER_OFF PIN_PC6

#define CS_SD PIN_PB4
#define CS_KLINE PIN_PC7
#define CS_WIFI PIN_PB3
#define CS_GPS PIN_PB3

void bridgeSerial(Stream& serial, bool send=true);
void setup();
void loop();
void print_gps_coordinate(int event_id, String* param);
void print_memory_available(int event_id, String* param);
