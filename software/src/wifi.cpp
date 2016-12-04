#include "wifi.h"


WifiManager::WifiManager(EventManager& evt_mgr, Stream* serial_port):
    event_manager(evt_mgr),
    port(serial_port),
    initialized(false)
{
}

void WifiManager::begin() {
    initialized = true;
}

void WifiManager::cycle() {
}
