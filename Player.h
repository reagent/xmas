#ifndef Player_h
#define Player_h

#include "Arduino.h"

class Player {
    short outputPin;
    String instructions;

public:
    Player(short outputPin);
    void addInstructions(String instructions);
    void play();
private:
    void playNote(String instruction);
};

#endif