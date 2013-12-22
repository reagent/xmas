#ifndef Notes_h
#define Notes_h

#include "Note.h"

class Notes {
    int size;

public:
    static Note * find(String name);
private:
    Notes();

    Note **noteCollection;
    static Notes * notes;
};

#endif