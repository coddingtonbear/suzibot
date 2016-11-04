#include "audio.h"

AudioManager::AudioManager(uint8_t pin_no) {
    pin_number = pin_no;

    pinMode(pin_number, OUTPUT);
}

void AudioManager::begin() {
}

void AudioManager::cycle() {
}

void AudioManager::playNotes(const int* notes, uint8_t length) {
    for(unsigned int i = 0; i < length/sizeof(notes[0]); i++) {
        tone(pin_number, notes[i], 250);
        //delay(250);
    }
}
