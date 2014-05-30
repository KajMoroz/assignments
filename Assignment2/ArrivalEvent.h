#ifndef ARRIVALEVENT_H_INCLUDED
#define ARRIVALEVENT_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class ArrivalEvent: public Events{

private:
public:
    ArrivalEvent(AbsQueue* act);
    ~ArrivalEvent();
    Train * run();
};


#endif // ARRIVALEVENT_H_INCLUDED
