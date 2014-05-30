#include <iostream>
#include <fstream>
#include <string>
#include "LoadQueue.h"
#include "Train.h"
#include "GlobalVariables.h"

using namespace std;

class LoadQueue;

ifstream myFile;

LoadQueue :: LoadQueue(AbsQueue * act, string fileName) :
    Events(act)
    {myFile.open(fileName.c_str());
    }

LoadQueue :: ~LoadQueue()
    {}
//If the train is null, no event can be processed.
Train * LoadQueue :: run()
{
    Train * loadedTrain = NULL;
    int arrTime;
    int waitTime;

    if(!myFile.eof())
    {
        myFile >> arrTime >> waitTime;
        loadedTrain = new Train(arrTime, waitTime, -1);
    }

    return loadedTrain;
}
