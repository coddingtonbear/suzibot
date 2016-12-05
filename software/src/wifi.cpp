#include "wifi.h"


WifiManager::WifiManager(EventManager* evt_mgr, Stream* serial_port):
    event_manager(evt_mgr),
    port(serial_port),
    initialized(false),
    status(COMMAND_OK)
{
}

void WifiManager::begin()
{
    initialized = true;

    command("AT+CWLAP");
}

void WifiManager::cycle()
{
    while(port->available()) {
        char byte = (char)port->read();
        if(status == COMMAND_BUSY) {
            command_data += byte;
            if(
                command_data.lastIndexOf("\r\nERROR") != -1 ||
                command_data.lastIndexOf("\r\nFAIL") != -1
            ) {
                status = COMMAND_FAILED;
            } else if (command_data.lastIndexOf("\r\nOK") != -1) {
                status = COMMAND_OK;
            } else if (millis() > command_timeout) {
                status = COMMAND_TIMEOUT;
            }
        }
    }
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
    return status == COMMAND_TIMEOUT;
}

bool WifiManager::failed() {
    return status == COMMAND_FAILED;
}

bool WifiManager::busy() {
    return status == COMMAND_BUSY;
}

bool WifiManager::ready() {
    return status == COMMAND_OK;
}

void WifiManager::command(String cmd_name, int timeout)
{
    command_name = cmd_name;
    command_data = "";
    command_timeout = millis() + timeout;
    status = COMMAND_BUSY;

    port->flush();
    for(uint8_t i = 0; i < command_name.length(); i++) {
        port->write(command_name[i]);
    }
    port->write("\r");
    port->write("\n");
}
