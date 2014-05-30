#include <iostream>
#include "StationEvent.h"
#include "Train.h"
#include "GlobalVariables.h"

using namespace std;

class StationEvent;

StationEvent :: StationEvent(AbsQueue * eventQueue) :
    Events(eventQueue)
    {}

StationEvent :: ~StationEvent()
    {}
//If the train is null, no event can be processed.
Train * StationEvent :: run()
{
    int i = 0;
    Train * currentTrain = dynamic_cast<Train *>(activeQueue->get(i));

    if(activeQueue->length() > 0)
    {
        while(i < activeQueue->length() && (currentTrain->departureTime() > currentTime || currentTrain->departureTime() == -1))
        {
            i++;
            activeQueue->insert(currentTrain);
            currentTrain = dynamic_cast<Train *>(activeQueue->get(i));
        }

        if(i == activeQueue->length())
        {
            currentTrain = NULL;
        }

    }
    else
    {
        currentTrain = NULL;
    }

    if(i == activeQueue->length())
    {
        currentTrain = NULL;
    }

    return currentTrain;
}
