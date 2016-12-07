#include "wifi.h"


WifiManager::WifiManager(EventManager* evt_mgr, Stream* serial_port, SDCardManager* sd_mgr):
    event_manager(evt_mgr),
    port(serial_port),
    sd_manager(sd_mgr),
    initialized(false),
    command_status(COMMAND_OK),
    status(WIFI_DISCONNECTED)
{
    command_data.reserve(1e3);
}

void WifiManager::begin()
{
    initialized = true;
}

void WifiManager::cycle()
{
    while(port->available()) {
        char byte = (char)port->read();
        if(command_status == COMMAND_BUSY) {
            command_data += byte;
            if(
                command_data.lastIndexOf("\r\nERROR") != -1 ||
                command_data.lastIndexOf("\r\nFAIL") != -1
            ) {
                command_status = COMMAND_FAILED;
            } else if (command_data.lastIndexOf("\r\nOK") != -1) {
                command_status = COMMAND_OK;
            } else if (millis() > command_timeout) {
                command_status = COMMAND_TIMEOUT;
            }
            if(command_callback_name) {
                call_command_callback(command_status, command_data);
            }
        }
    }
}

void WifiManager::call_command_callback(WifiCommandStatus command_status, String command_data)
{
}

String WifiManager::get_command() {
    return command_name;
}

String WifiManager::get_data(bool reset) {
    String data = command_data;
    command_data = "";
    return data;
}

bool WifiManager::timeout() {
    return command_status == COMMAND_TIMEOUT;
}

bool WifiManager::failed() {
    return command_status == COMMAND_FAILED;
}

bool WifiManager::busy() {
    return command_status == COMMAND_BUSY;
}

bool WifiManager::ready() {
    return command_status == COMMAND_OK;
}

void WifiManager::command(
    String cmd_name,
    String cmd_callback_name,
    int timeout
)
{
    command_name = cmd_name;
    command_data = "";
    command_data.reserve(1e3)
    command_timeout = millis() + timeout;
    command_callback_name = cmd_callback_name;
    command_status = COMMAND_BUSY;

    port->flush();
    for(uint8_t i = 0; i < command_name.length(); i++) {
        port->write(command_name[i]);
    }
    port->write("\r");
    port->write("\n");
}
