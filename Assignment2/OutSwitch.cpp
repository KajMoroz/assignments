#include <iostream>
#include "OutSwitch.h"
#define DELAY 4
#define MAX_TRAINS 1

using namespace std;

const int timeDelay = DELAY;
const int maxTrains = MAX_TRAINS;

class OutSwitch;

OutSwitch :: OutSwitch() :
    AbsQueue()
    {}
OutSwitch :: ~OutSwitch()
    {}

int OutSwitch :: getPriority(Object * item)
{
    Train * temp = dynamic_cast<Train*>(item);
    return (temp)->trainNumber();
}

int OutSwitch :: getMaxTrains()
{
    return maxTrains;
}

int OutSwitch :: getDelay()
{
    return timeDelay;
}

void OutSwitch :: printList()
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
