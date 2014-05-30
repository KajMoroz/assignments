#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include "AbstractQueue.h"

using namespace std;

class Station: public AbsQueue{

private:
public:
    Station();
    ~Station();
    int getPriority(Object * item);
    int getDelay();
    int getMaxTrains();
    void printList();
};


#endif // STATION_H_INCLUDED
