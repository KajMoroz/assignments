#ifndef INCOMINGSWITCH_H_INCLUDED
#define INCOMINGSWITCH_H_INCLUDED

#include "AbstractQueue.h"


using namespace std;

class IncomingSwitch: public AbsQueue{

private:
public:
    void printList();
    IncomingSwitch();
    ~IncomingSwitch();
    int getPriority(Object * item);
    int getDelay();
    int getMaxTrains();
};
#endif // INCOMINGSWITCH_H_INCLUDED
