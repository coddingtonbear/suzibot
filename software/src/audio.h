#pragma once

#include <Arduino.h>
#include <EventManager.h>
#include "pitches.h"
#include "service.h"

const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4};

class AudioManager: public StandardService
{
    public:
        AudioManager(EventManager* evt_mgr, uint8_t pin_no);
        void playNotes(const int* notes, uint8_t length);
        void begin();
        void cycle();
    private:
        uint8_t pin_number;
        EventManager* event_manager;
};
