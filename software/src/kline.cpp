#include "kline.h"


SC16IS750 klineSerial = SC16IS750(
    CS_KLINE,
    SC16IS750_CHAN_A,
    6000000UL
);

void initKline() {
    klineSerial.begin(10400);
    klineSerial.flush();
    if(! klineSerial.ping()) {
        Serial.println("ERROR initializing K-Line.");
    }
}
