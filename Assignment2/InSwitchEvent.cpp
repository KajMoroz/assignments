#include <iostream>
#include "InSwitchEvent.h"
#include "Train.h"
#include "GlobalVariables.h"

using namespace std;

class InSwitchEvent;

InSwitchEvent :: InSwitchEvent(AbsQueue * check) :
    Events(check)
    {}

InSwitchEvent :: ~InSwitchEvent()
    {}
//If the train is null, no event can be processed.
Train * InSwitchEvent :: run()
{
    int i = 0;
    Train * currentTrain = dynamic_cast<Train *>(activeQueue->get(i));

    if(activeQueue->length() > 0)
    {
        while(i < activeQueue->length() && currentTrain->arrivalTime() > currentTime && currentTrain->delayTime() < currentTime)
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
