#include "main.h"


EventManager event_manager;

AudioManager audio_mgr = AudioManager(&event_manager, PIEZO);
SDCardManager sd_mgr = SDCardManager(&event_manager, CS_SD);
PowerManager power_mgr = PowerManager(
    &event_manager,
    ENABLE_3V3_REGULATOR,
    ENABLE_LEVEL_CONVERTER,
    RX_VOLTAGE,
    TX_POWER_OFF
);
SystemManager system_mgr = SystemManager(&event_manager);

SC16IS750 kline_serial = SC16IS750(
    CS_KLINE,
    SC16IS750_CHAN_A,
    6000000UL
);
KLineManager kline_mgr = KLineManager(&event_manager, &kline_serial);

SC16IS750 gps_serial = SC16IS750(
    CS_GPS,
    SC16IS750_CHAN_A,
    14745600UL
);
GpsManager gps_mgr = GpsManager(&event_manager, &gps_serial, DISABLE_GPS);

SC16IS750 wifi_serial = SC16IS750(
    CS_WIFI,
    SC16IS750_CHAN_B,
    14745600UL
);
WifiManager wifi_mgr = WifiManager(&event_manager, &wifi_serial);

void bridgeSerial(Stream& serial, bool send) {
    while (serial.available()) {
        uint8_t value = serial.read();
        Serial.write(value);
    }
    if(send) {
        while (Serial.available()) {
            serial.write(Serial.read());
        }
    }
}

void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);

    SPI.begin();
    Serial.begin(1000000);

    /* System */
    Serial.println("Initializing System...");
    system_mgr.begin();

    /* Audio */
    Serial.println("Initializing Audio...");
    audio_mgr.begin();

    /* Power Management */
    Serial.println("Initializing Power Manager...");
    power_mgr.begin();

    /* SD */
    Serial.println("Initializing SD...");
    sd_mgr.begin();

    /* K-Line */
    Serial.println("Initializing K-Line...");
    kline_serial.begin(10400);
    if (kline_serial.ping()) {
        kline_mgr.begin();
    } else {
        Serial.println("Error initializing K-Line.");
    }

    /* GPS */
    Serial.println("Initializing GPS...");
    gps_serial.begin(9600);
    if (gps_serial.ping()) {
        gps_mgr.begin();
    } else {
        Serial.println("Error initializing GPS.");
    }

    /* WIFI */
    Serial.println("Initializing WIFI...");
    wifi_serial.begin(9600);
    if (wifi_serial.ping()) {
        wifi_mgr.begin();
    } else {
        Serial.println("Error initializing WIFI.");
    }

    Serial.println("Ready.");

    /*
    event_manager.addListener(
        EventManager::kEventNewGPSCoordinate,
        print_gps_coordinate
    );
    event_manager.addListener(
        EventManager::kEventNewMemoryMeasurement,
        print_memory_available
    );
    */
}

void print_gps_coordinate(int event_id, String* param) {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(*param);
    Serial.println(
        root["year"].as<String>() + "-" +
        root["month"].as<String>() + "-" +
        root["day"].as<String>() + "T" +
        root["hr"].as<String>() + ":" +
        root["min"].as<String>() + ":" +
        root["sec"].as<String>()
    );
    Serial.println(
        "Lat: " + root["lat"].as<String>() + "; " +
        "Lng: " + root["lng"].as<String>() + "; " +
        "Alt: " + root["alt"].as<String>()
    );
}

void print_memory_available(int event_id, String* param) {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(*param);

    Serial.print(root["free"].as<String>() + " free (");
    Serial.print(
        root["free"].as<unsigned long>() - root["last"].as<unsigned long>()
    );
    Serial.println(" increase)");
}

void loop() {
    system_mgr.cycle();
    wifi_mgr.cycle();
    kline_mgr.cycle();
    gps_mgr.cycle();
    sd_mgr.cycle();
    audio_mgr.cycle();
    power_mgr.cycle();

    event_manager.processAllEvents();

    //bridgeSerial(wifi_serial);
    if(wifi_mgr.ready()) {
        String wifi_data = wifi_mgr.get_data();
        if(wifi_data.length()) {
            Serial.print("Data available for ");
            Serial.print(wifi_mgr.get_command());
            Serial.println(": ");
            Serial.println(wifi_data);
        }
    }

    /*
     * LOGGING
     */
    //char buf[8];
    //sprintf(buf, "%03u", gps.time.value());
    //logMessage(buf);
    //Serial.println(buf);

    /* 
     * POWER OFF MANAGEMENT
     *
     * If power drops below 11.5V, shut down immediately.
     
    if(voltage12v > 9.0 && voltage12v < 11.5) {
        Serial.println(voltage12v);
        powerOff();
    }*/
}

