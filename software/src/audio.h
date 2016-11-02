#include "Arduino.h"
#include "pitches.h"

#define PIEZO 0

const int STARTUP[] = {NOTE_C4, NOTE_E4, NOTE_E4};
const int SHUTDOWN[] = {NOTE_E4, NOTE_C4, NOTE_C4};
const int CONNECTED[] = {NOTE_C4, NOTE_D4, NOTE_E4};
const int ERROR[] = {NOTE_A4, NOTE_A4, NOTE_A4};


void playNotes(const int* notes, uint8_t length);
