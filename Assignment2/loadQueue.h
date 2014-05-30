#ifndef LOADQUEUE_H_INCLUDED
#define LOADQUEUE_H_INCLUDED

#include "Events.h"
#include "Train.h"

using namespace std;

class LoadQueue: public Events{

private:
public:
    LoadQueue(AbsQueue * act, string fileName);
    ~LoadQueue();
    Train * run();
};


#endif // LOADQUEUE_H_INCLUDED
