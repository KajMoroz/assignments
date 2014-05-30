#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED
#include "Object.h"

using namespace std;

class Train: public Object{

private:
    int aTime; //Arrival and Departure times.
    int wait;
    int dTime;
    int number;
    int delayT;
    int totalWait;
    int leavesInSwitch;
    int leavesOutSwitch;

public:
    Train(int arr, int waitTime, int num);
    int arrivalTime();
    int departureTime();
    int trainNumber();
    int waitTime();
    int delayTime();
    int getTotalWait();
    int getInTime();
    int getOutTime();
    void setTrainNumber(int num);
    void setDepartureTime(int num);
    void setDelay(int num);
    void setOutTime(int num);
    void setInTime(int num);
    void setTotalWait(int num);
};

#endif // TRAIN_H_INCLUDED
