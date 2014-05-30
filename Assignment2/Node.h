#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

using namespace std;

class Object;

class Node{

private:
    Object * item;
    Node * nextNode;
public:
    void setNextNode(Node * nodePtr);
    Node(Object * input);
    Object * getItem();
    Node * getNextNode();
};
#endif // NODE_H_INCLUDED
