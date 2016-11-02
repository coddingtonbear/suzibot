#include <ESP8266.h>
#include <SC16IS750.h>

// WIFI Settings
#define CS_WIFI 3
#define FILENAME_AP_PASSWORDS_DB "/db/ap.db"

void initWifi();
ESP8266 getWifi();
