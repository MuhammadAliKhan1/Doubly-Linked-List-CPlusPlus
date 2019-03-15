#ifndef NODE_H
#define NODE_H
#include <iostream>

//Node class
class Node
{
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int);
};
#endif //NODE_H