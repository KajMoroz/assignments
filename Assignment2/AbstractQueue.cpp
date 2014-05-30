#include <iostream>
#include "AbstractQueue.h"
#include "Node.h"

using namespace std;

class AbsQueue;

AbsQueue :: AbsQueue():
    top(NULL),
    num(0)
    {}

int AbsQueue :: length()
{
    return num;
}

Object * AbsQueue :: get(int i)
{
    Object * item = NULL;
    Node * prev = NULL;
    Node * current = top;
    int counter = 0;

    while(counter < i)
    {
        prev = current;
        current = top->getNextNode();
    }

    item = current->getItem();

    if(current != top)
    {
        prev->setNextNode(current->getNextNode());
    }

    return item;
}

void AbsQueue :: insert(Object * item)
{
    Node * created = new Node(item);

    Node * temp = top;
    Node * prev = NULL;

    if(top == NULL || getPriority(top->getItem()) > getPriority(item))
    {
        created = top;
    }

    while(temp != NULL || getPriority(item) > getPriority(temp->getItem()))
    {
        prev = top;
        temp = temp->getNextNode();
    }

    if(top != created)
    {
        prev->setNextNode(created);
        created->setNextNode(temp);
    }
}
