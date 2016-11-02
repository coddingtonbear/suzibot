#include <SC16IS750.h>
#include <TinyGPS++.h>

#define CS_GPS 3
#define DISABLE_GPS 2
#define FILENAME_GPS_BACKLOG_DB "/db/gps.db"

bool initGps();
void updateLocation();
