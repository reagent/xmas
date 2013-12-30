#include "Player.h"

const short SPEAKER_PIN = 9; // PWM PIN speaker is connected to
const short BUTTON_PIN = 2;  // PIN pushbutton is connected to

Player player(SPEAKER_PIN);

void setup() {
    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT);

    player.addInstructions("G4:4,C5:4,C5:2,D5:2,C5:2,B4:2,A4:4,A4:4");
    player.addInstructions("A4:4,D5:4,D5:2,E5:2,D5:2,C5:2,B4:4,G4:4");
    player.addInstructions("G4:4,E5:4,E5:2,F5:2,E5:2,D5:2,C5:4,A4:4,G4:2,G4:2,A4:4,D5:4,B4:4,C5:4");
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {
       player.play();
    }
}