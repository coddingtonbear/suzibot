#include "wifi.h"


WifiManager::WifiManager(EventManager& evt_mgr, Stream* serial_port):
    port(serial_port),
    event_manager(evt_mgr),
    initialized(false)
{
}

void WifiManager::begin() {
    initialized = true;
}

void WifiManager::cycle() {
}
