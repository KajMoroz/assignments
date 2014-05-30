#include <iostream>
#include "OutSwitchEvent.h"
#include "Train.h"
#include "GlobalVariables.h"

using namespace std;

class OutSwitchEvent;

OutSwitchEvent :: OutSwitchEvent(AbsQueue * eventQueue) :
    Events(eventQueue)
    {}

OutSwitchEvent :: ~OutSwitchEvent()
    {}

//If the train is null, no event can be processed.
Train * OutSwitchEvent :: run()
{
    int i = 0;
    Train * currentTrain = dynamic_cast<Train *>(activeQueue->get(i));

    if(activeQueue->length() > 0)
    {
        while(i < activeQueue->length() && currentTrain->departureTime() > currentTime)
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
