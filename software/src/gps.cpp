#include "gps.h"

TinyGPSPlus gps;
SC16IS750 gpsSerial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
);


void updateLocation() {
    while(gpsSerial.available()) {
        byte value = gpsSerial.read();
        gps.encode(value);
    }
}


bool initGps() {
    gpsSerial.begin(9600);
    if(! gpsSerial.ping()) {
        return false;
    }
    char configureGps[] = (
        //"$PMTK251,9600*17\r\n"
        //"$PMTK314,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
        //"$PMTK314,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2D\r\n"
        "$PMTK314,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2E\r\n"
        //"$PMTK314,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"
        //"$PMTK314,-1*04\r\n"
    );
    for(uint8_t i = 0; i < sizeof(configureGps)/sizeof(configureGps[0]); i++) {
        gpsSerial.write(configureGps[i]);
    }

    return true;
}
