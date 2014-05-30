#include <iostream>
#include "Station.h"
#define MAX_TRAINS 3

using namespace std;

const int maxTrains = MAX_TRAINS;

class Station;

Station :: Station() :
    AbsQueue()
    {}
Station :: ~Station()
    {}

int Station :: getPriority(Object * item)
{
    Train * temp = dynamic_cast<Train*>(item);
    return (temp)->trainNumber();
}

int Station :: getMaxTrains()
{
    return maxTrains;
}

void Station :: printList()
{
    int i = 0;
    cout << "Train #" << "     " << "Arrival Time" << "     " << "InSwitch Time"
    << "     " << "Station Time" << "     " << "Departure Time" << "     "
    << "OutSwitch Time" << "     " << "Total Wait Time" << endl;


    while(i < length())
    {
        Train * activeTrain = dynamic_cast<Train *>(get(i));

        cout << activeTrain->trainNumber() << "     " << activeTrain->arrivalTime() //Does the formating for the text block output
        << activeTrain->getInTime() << "     " << activeTrain->waitTime() << "     "
        << activeTrain->departureTime() << "     " << activeTrain->getOutTime()
        << "     " << activeTrain->getTotalWait() << endl;

        i++;
    }
}
