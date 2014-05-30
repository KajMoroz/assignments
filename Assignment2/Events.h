#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "Train.h"
#include "AbstractQueue.h"

class Events{

private:
public:
    Events(AbsQueue * act);
    ~Events();
    AbsQueue * activeQueue;
    //If the train is null, no event can be processed.
    virtual Train * run() = 0;
};


#endif // EVENTS_H_INCLUDED
