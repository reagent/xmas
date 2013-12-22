#include "Arduino.h"
#include "PlayableNote.h"
#include "Notes.h"

PlayableNote::PlayableNote(short outputPin, String instruction)
{
    this->outputPin = outputPin;
    this->duration  = durationFrom(instruction);

    this->note = Notes::find(noteNameFrom(instruction));
}

void PlayableNote::play()
{
    this->note->play(this->outputPin, this->duration);
}

int PlayableNote::delimiterPosition(String instruction)
{
    return instruction.indexOf(':');
}

String PlayableNote::noteNameFrom(String instruction)
{
    return instruction.substring(0, delimiterPosition(instruction));
}

int PlayableNote::durationFrom(String instruction)
{
    return instruction.substring(delimiterPosition(instruction) + 1).toInt();
}