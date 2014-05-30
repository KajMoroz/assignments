#ifndef ARRIVAL_H_INCLUDED
#define ARRIVAL_H_INCLUDED

#include "AbstractQueue.h"

using namespace std;

class Arrival: public AbsQueue{

private:
public:
    void printList();
    Arrival();
    ~Arrival();
    int getPriority(Object * item);
};


#endif // ARRIVAL_H_INCLUDED
