#ifndef OUTSWITCH_H_INCLUDED
#define OUTSWITCH_H_INCLUDED

#include "AbstractQueue.h"

using namespace std;

class OutSwitch: public AbsQueue{

private:
public:
    OutSwitch();
    ~OutSwitch();
    int getPriority(Object * item);
    int getDelay();
    int getMaxTrains();
    void printList();
};

#endif // OUTSWITCH_H_INCLUDED
