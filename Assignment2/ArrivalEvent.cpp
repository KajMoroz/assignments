#include <iostream>
#include "ArrivalEvent.h"
#include "Train.h"
#include "GlobalVariables.h"
#include "LoadQueue.h"
#include "Events.h"

using namespace std;

class ArrivalEvent;

ArrivalEvent :: ArrivalEvent(AbsQueue * act) :
    Events(act)
    {}

ArrivalEvent :: ~ArrivalEvent()
    {}

Train * ArrivalEvent :: run()
{
    int i = 0;
    Train * currentTrain = dynamic_cast<Train *>((activeQueue)->get(i));

    if((activeQueue)->length() > 0)
    {
        while(i < (activeQueue)->length() && currentTrain->arrivalTime() > currentTime)
        {
            i++;
            (activeQueue)->insert(currentTrain);
            currentTrain = dynamic_cast<Train *>((activeQueue)->get(i));
        }

        if(i == (activeQueue)->length())
        {
            currentTrain = NULL;
        }

    }
    else
    {
        currentTrain = NULL;
    }

    if(i == (activeQueue)->length())
    {
        currentTrain = NULL;
    }

    return currentTrain;
}
