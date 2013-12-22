const short SPEAKER_PIN = 9;  // PWM PIN speaker is connected to

class Note {
    short frequency;
    int tempo;

public:
    String name;

    Note(String name, short frequency = NULL)
    {
        this->name      = name;
        this->tempo     = 150;
        this->frequency = frequency;
    }

    void play(short outputPin, int duration)
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
};

class Notes {
    int size;

public:
    static Note * find(String name)
    {
        if (!notes) { notes = new Notes(); }

        // TODO: error handling
        for (int i = 0; i < notes->size; i++) {
            if (notes->noteCollection[i]->name == name) {
                return notes->noteCollection[i];
            }
        }
    }
private:
    Notes()
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

    Note **noteCollection;
    static Notes * notes;
};

Notes * Notes::notes; // Required to handle undefined reference in singleton

class PlayableNote {
    short outputPin;
    Note * note;
    int duration;

public:
    PlayableNote(short outputPin, String instruction)
    {
        this->outputPin = outputPin;
        this->duration  = durationFrom(instruction);

        this->note = Notes::find(noteNameFrom(instruction));
    }

    void play()
    {
        this->note->play(this->outputPin, this->duration);
    }

private:
    int delimiterPosition(String instruction)
    {
        return instruction.indexOf(':');
    }

    String noteNameFrom(String instruction)
    {
        return instruction.substring(0, delimiterPosition(instruction));
    }

    int durationFrom(String instruction)
    {
        return instruction.substring(delimiterPosition(instruction) + 1).toInt();
    }
};

class Player {
    short outputPin;
    String instructions;

public:
    Player(short outputPin)
    {
        this->outputPin = outputPin;
    }

    void addInstructions(String instructions)
    {
        if (this->instructions.length() > 0) {
            this->instructions += ",";
        }

        this->instructions += instructions;
    }

    void play()
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

private:

    void playNote(String instruction)
    {
        PlayableNote note(this->outputPin, instruction);
        note.play();
    }
};

Player player(SPEAKER_PIN);

void setup() {
    Serial.begin(9600);

    player.addInstructions("G4:4,C5:4,C5:2,D5:2,C5:2,B4:2,A4:4,A4:4");
    player.addInstructions("A4:4,D5:4,D5:2,E5:2,D5:2,C5:2,B4:4,G4:4");
    player.addInstructions("G4:4,E5:4,E5:2,F5:2,E5:2,D5:2,C5:4,A4:4,G4:2,G4:2,A4:4,D5:4,B4:4,C5:4");
}

void loop() {
    player.play();

    while(true) {} // Play once
}