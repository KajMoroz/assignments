#include <iostream>
#include "Train.h"

using namespace std;

class Train;

Train :: Train(int arr, int waitTime, int num) :
    aTime(arr),
    wait(waitTime),
    number(num),
    totalWait(0),
    leavesInSwitch(0),
    leavesOutSwitch(0)
    {}

int Train :: arrivalTime()
{
    return aTime;
}

int Train :: departureTime()
{
    return dTime;
}

int Train :: trainNumber()
{
    return number;
}

int Train :: delayTime()
{
    return delayT;
}

int Train :: waitTime()
{
    return wait;
}

int Train :: getTotalWait()
{
    return totalWait;
}

int Train :: getInTime()
{
    return leavesInSwitch;
}

int Train :: getOutTime()
{
    return leavesOutSwitch;
}


void Train :: setTrainNumber(int num)
{
    number = num;
}

void Train :: setDepartureTime(int num)
{
    dTime = num;
}

void Train :: setDelay(int num)
{
    delayT = num;
}

void Train :: setInTime(int num)
{
    leavesInSwitch = num;
}

void Train :: setOutTime(int num)
{
    leavesOutSwitch = num;
}

void Train :: setTotalWait(int num)
{
    totalWait = num;
}
