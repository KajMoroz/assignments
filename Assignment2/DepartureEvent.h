#ifndef DEPARTUREEVENT_H_INCLUDED
#define DEPARTUREEVENT_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class DepartureEvent: public Events{

private:
public:
    DepartureEvent(AbsQueue * check);
    ~DepartureEvent();
    Train * run();
};


#endif // DEPARTUREEVENT_H_INCLUDED
