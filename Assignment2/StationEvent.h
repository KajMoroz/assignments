#ifndef STATIONEVENT_H_INCLUDED
#define STATIONEVENT_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class StationEvent: public Events{

private:
public:
    StationEvent(AbsQueue * eventQueue);
    ~StationEvent();
    Train * run();
};


#endif // STATIONEVENT_H_INCLUDED
