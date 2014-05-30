#ifndef ABSTRACTQUEUE_H_INCLUDED
#define ABSTRACTQUEUE_H_INCLUDED
#include "Object.h"
#include "Train.h"

using namespace std;

class Node;
class Train;

class AbsQueue{

private:
    Node * top;
    int num;
public:
    AbsQueue();
    void insert(Object * item);
    int length();
    Object * get(int i);
    ~AbsQueue(){}
    virtual int getPriority(Object * item) = 0;
    virtual void printList() = 0;
};

#endif // ABSTRACTQUEUE_H_INCLUDED
