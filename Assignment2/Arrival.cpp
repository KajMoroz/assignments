#include <iostream>
#include "Arrival.h"

using namespace std;

class Arrival;

Arrival :: Arrival() :
    AbsQueue()
    {}
Arrival :: ~Arrival()
    {}

int Arrival :: getPriority(Object * item)
{
    Train * temp = dynamic_cast<Train*>(item);
    return (temp)->arrivalTime();
}

void Arrival :: printList()
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

