#include "Arduino.h"
#include "Player.h"
#include "PlayableNote.h"

Player::Player(short outputPin)
{
    this->outputPin = outputPin;
}

void Player::addInstructions(String instructions)
{
    if (this->instructions.length() > 0) {
        this->instructions += ",";
    }

    this->instructions += instructions;
}

void Player::play()
{
    int currentPosition = 0,
        delimiterPosition = 0;

    while ((delimiterPosition = this->instructions.indexOf(',', currentPosition)) >= 0) {
        playNote(this->instructions.substring(currentPosition, delimiterPosition));
        currentPosition = delimiterPosition + 1;
    }

    if (currentPosition <= this->instructions.length()) {
        playNote(this->instructions.substring(currentPosition));
    }
}

void Player::playNote(String instruction)
{
    PlayableNote note(this->outputPin, instruction);
    note.play();
}