#ifndef Note_h
#define Note_h

class Note {
    short frequency;
    int tempo;

public:
    String name;

    Note(String name, short frequency = NULL);
    void play(short outputPin, int duration);
};

#endif