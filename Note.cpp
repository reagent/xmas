#include "Arduino.h"
#include "Note.h"

Note::Note(String name, short frequency)
{
    this->name      = name;
    this->tempo     = 150;
    this->frequency = frequency;
}

void Note::play(short outputPin, int duration)
{
    Serial.print("Playing '");
    Serial.print(this->name);
    Serial.print("' for ");
    Serial.println(duration);

    // TODO: duration of zero is bad ;)

    if (this->frequency) {
        tone(outputPin, this->frequency, duration * this->tempo);
        delay(duration * this->tempo);
    } else {
        delay(duration * this->tempo);
    }

    delay(this->tempo / 10);
}