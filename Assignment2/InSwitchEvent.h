#ifndef INSWITCHEVENT_H_INCLUDED
#define INSWITCHEVENT_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class InSwitchEvent: public Events{

private:
public:
    InSwitchEvent(AbsQueue * act);
    ~InSwitchEvent();
    Train * run();
};


#endif // INSWITCHEVENT_H_INCLUDED
