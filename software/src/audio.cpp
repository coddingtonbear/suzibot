#include "audio.h"

void playNotes(const int* notes, uint8_t length) {
    for(unsigned int i = 0; i < length/sizeof(notes[0]); i++) {
        tone(PIEZO, notes[i], 250);
        //delay(250);
    }
}
