#ifndef PlayableNote_h
#define PlayableNote_h

#include "Note.h"

class PlayableNote {
    short outputPin;
    Note * note;
    int duration;

public:
    PlayableNote(short outputPin, String instruction);
    void play();
private:
    int delimiterPosition(String instruction);
    String noteNameFrom(String instruction);
    int durationFrom(String instruction);
};

#endif