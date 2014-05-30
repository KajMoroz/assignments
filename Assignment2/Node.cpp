#include <iostream>
#include "Node.h"
#include "Object.h"

using namespace std;

class Node;
class Object;

Node :: Node(Object * input) :
    item(input),
    nextNode(NULL)
    {}

Object * Node :: getItem()
{
    return item;
}

Node * Node :: getNextNode()
{
    return nextNode;
}

void Node :: setNextNode(Node * nodePtr)
{
    nextNode = nodePtr;
}
