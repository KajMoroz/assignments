//---------------------------------------------------
// Name: Kaj Moroz
// Student Number : 7661464
// Course: COMP 2150
// Instructor: Gord Boyer
// Assignment: 2
//
//
// Purpose of Program: Simulate a train system where the file inputs the arrival and wait time at the station.

#include<string>
#include<iostream>
#include "AbstractQueue.h"
#include "Arrival.h"
#include "ArrivalEvent.h"
#include "Departure.h"
#include "DepartureEvent.h"
#include "Events.h"
#include "GlobalVariables.h"
#include "IncomingSwitch.h"
#include "InSwitchEvent.h"
#include "loadQueue.h"
#include "Node.h"
#include "Object.h"
#include "OutSwitch.h"
#include "OutSwitchEvent.h"
#include "Station.h"
#include "StationEvent.h"
#include "Train.h"
#include "TrainList.h"

using namespace std;

void processSimulation(string fileName);

int main()
{
    string fileName;

    cout << "Input the filename of the file you wish to simulate." << endl;
    cin >> fileName;

    processSimulation(fileName);

    cout << "Processing Completed." << endl;
    return 0;
}

void processSimulation(string fileName)
{



    TrainList * registerOfTrains = new TrainList();
    bool somethingHappened = false;


    //The train system parts, event and object for that event
    Arrival * arrivalQueue = new Arrival();
    ArrivalEvent * arrEvent = new ArrivalEvent(arrivalQueue);

   Departure * depQueue = new Departure();
   DepartureEvent * depEvent = new DepartureEvent(depQueue);

   IncomingSwitch * incQueue = new IncomingSwitch();
   InSwitchEvent * incEvent = new InSwitchEvent(incQueue);

   OutSwitch * outQueue = new OutSwitch();
   OutSwitchEvent * outEvent = new OutSwitchEvent(outQueue);

   Station * statQueue = new Station();
   StationEvent * statEvent = new StationEvent(statQueue);

   LoadQueue * theLoadProgram = new LoadQueue(arrivalQueue, fileName);

   Train * activeTrain = theLoadProgram->run();

    //Load up the active train
    while(activeTrain != NULL)
    {
        arrivalQueue->insert(activeTrain);
        activeTrain = theLoadProgram->run();
    }

    //If the simulation has a train in it.
    while(arrivalQueue->length() > 0 || depQueue->length() > 0 || incQueue->length() > 0 || outQueue->length() > 0 || statQueue->length() > 0)
    {
        somethingHappened = false;
        activeTrain = arrEvent->run();
        if(activeTrain != NULL)
        {
            if(incQueue->getMaxTrains() < incQueue->length())
            {
                incQueue->insert(activeTrain);
                registerOfTrains->insert(activeTrain);
                activeTrain->setTrainNumber(currentTrainNumber);
                currentTrainNumber++;
                activeTrain->setDelay(currentTime + incQueue->getDelay());
                somethingHappened = true;
            }
            else
            {
                arrivalQueue->insert(activeTrain);
            }
        }

        activeTrain = incEvent->run();
        if(activeTrain != NULL)
        {
            if(statQueue->getMaxTrains() < statQueue->length())
            {
                statQueue->insert(activeTrain);
                activeTrain->setInTime(currentTime);
                activeTrain->setDepartureTime(activeTrain->delayTime() + currentTime);
                somethingHappened = true;
            }
            else
            {
                incQueue->insert(activeTrain);
            }
        }

        activeTrain = statEvent->run();
        if(activeTrain != NULL)
        {
            somethingHappened = true;
            depQueue->insert(activeTrain);
            activeTrain->setDepartureTime(currentTime);
        }

        activeTrain = depEvent->run();
        if(activeTrain != NULL)
        {
            if(outQueue->getMaxTrains() < outQueue->length())
            {
                outQueue->insert(activeTrain);
                activeTrain->setDelay(currentTime + outQueue->getDelay());
                somethingHappened = true;
            }
            else
            {
                depQueue->insert(activeTrain);
            }
        }

        activeTrain = outEvent->run();
        if(activeTrain != NULL)
        {
            if(outQueue->getMaxTrains() < outQueue->length())
            {
                outQueue->insert(activeTrain);
                activeTrain->setTotalWait(activeTrain->getTotalWait() + (activeTrain->departureTime() - outQueue->getDelay()));
                activeTrain->setOutTime(currentTime);
                somethingHappened = true;
            }
            else
            {
                depQueue->insert(activeTrain);
            }
        }


        if(somethingHappened == false)
        {
            currentTime++;
        }
    }

    registerOfTrains->printList();
}
