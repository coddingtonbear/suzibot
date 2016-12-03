#include "kline.h"


KLineManager::KLineManager(EventManager& evt_mgr, Stream* serial_port):
    event_manager(evt_mgr),
    port(serial_port),
    initialized(false)
{
}

void KLineManager::begin() {
    initialized = true;
}

void KLineManager::cycle() {
}
