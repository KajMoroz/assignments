#ifndef TRAINLIST_H_INCLUDED
#define TRAINLIST_H_INCLUDED

#include "AbstractQueue.h"

using namespace std;

class TrainList: public AbsQueue{

private:
public:
    void printList();
    TrainList();
    ~TrainList();
    int getPriority(Object * item);
};

#endif // TRAINLIST_H_INCLUDED
