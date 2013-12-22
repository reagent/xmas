#include "Arduino.h"
#include "Notes.h"

Note * Notes::find(String name)
{
    if (!notes) { notes = new Notes(); }

    // TODO: error handling
    for (int i = 0; i < notes->size; i++) {
        if (notes->noteCollection[i]->name == name) {
            return notes->noteCollection[i];
        }
    }
}

Notes::Notes()
{
    this->size = 15;

    // TODO: read this from a string

    this->noteCollection = new Note*[this->size];

    this->noteCollection[0]  = new Note("R"); // Rest
    this->noteCollection[1]  = new Note("C4", 262);
    this->noteCollection[2]  = new Note("D4", 294);
    this->noteCollection[3]  = new Note("E4", 330);
    this->noteCollection[4]  = new Note("F4", 349);
    this->noteCollection[5]  = new Note("G4", 392);
    this->noteCollection[6]  = new Note("A4", 440);
    this->noteCollection[7]  = new Note("B4", 494);
    this->noteCollection[8]  = new Note("C5", 523);
    this->noteCollection[9]  = new Note("D5", 587);
    this->noteCollection[10] = new Note("E5", 659);
    this->noteCollection[11] = new Note("F5", 699);
    this->noteCollection[12] = new Note("G5", 784);
    this->noteCollection[13] = new Note("A5", 880);
    this->noteCollection[14] = new Note("B5", 988);
}

Notes * Notes::notes; // Required to handle undefined reference in singleton