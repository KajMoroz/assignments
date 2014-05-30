#ifndef DEPARTURE_H_INCLUDED
#define DEPARTURE_H_INCLUDED
#include "AbstractQueue.h"
using namespace std;

class Departure: public AbsQueue{

private:
public:
    void printList();
    Departure();
    ~Departure();
    int getPriority(Object * item);
};


#endif // DEPARTURE_H_INCLUDED
