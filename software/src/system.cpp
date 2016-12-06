#include "system.h"


SystemManager::SystemManager(EventManager* evt_mgr, uint8_t led_pin_no):
    event_manager(evt_mgr),
    led_pin(led_pin_no),
    last_memory_check(0),
    last_memory_size(0)
{
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, HIGH);
}

void SystemManager::begin()
{
}

void SystemManager::cycle()
{
    if ((millis() - last_memory_check) > 5e3) {
        int free_memory = get_free_memory();
        int pre_check_size = last_memory_size;
        last_memory_size = free_memory;
        last_memory_check = micros();

        String* output = new String();
        StaticJsonBuffer<100> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();
        root["free"] = free_memory;
        root["last"] = pre_check_size;
        root.printTo(*output);

        event_manager->queueEvent(
            EventManager::kEventNewMemoryMeasurement,
            output
        );
        if (free_memory < 2e3) {
            String* output = new String();
            root.printTo(*output);
            event_manager->queueEvent(
                EventManager::kEventLowMemoryWarning,
                output,
                EventManager::kHighPriority
            );
        }
    }
}

int SystemManager::get_free_memory()
{
    extern int __heap_start, *__brkval; 
    int v; 
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
