#include <iostream>
#include "IncomingSwitch.h"
#define DELAY 6
#define MAX_TRAINS 1

using namespace std;

const int timeDelay = DELAY;
const int maxTrains = MAX_TRAINS;

class IncomingSwitch;

IncomingSwitch :: IncomingSwitch() :
    AbsQueue()
    {}
IncomingSwitch :: ~IncomingSwitch()
    {}

int IncomingSwitch :: getPriority(Object * item)
{
    Train * temp = dynamic_cast<Train*>(item);
    return (temp)->arrivalTime();
}

int IncomingSwitch :: getMaxTrains()
{
    return maxTrains;
}

int IncomingSwitch :: getDelay()
{
    return timeDelay;
}

void IncomingSwitch :: printList()
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
