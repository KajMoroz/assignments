#ifndef OUTSWITCHEVENT_H_INCLUDED
#define OUTSWITCHEVENT_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class OutSwitchEvent: public Events{

private:
public:
    OutSwitchEvent(AbsQueue * eventQueue);
    ~OutSwitchEvent();
    Train * run();
};


#endif // OUTSWITCHEVENT_H_INCLUDED
