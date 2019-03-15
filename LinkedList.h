#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList
{
private:
  Node *head; //Pointer for first node
  Node *last; //Pointer for last node

public:
  //Constructors
  LinkedList();

  //Member Functions
  Node *getHeadVal();
  Node *findNodeByValue(int);
  bool mergeLinkedList(LinkedList *);
  bool deleteFirstNode();
  bool deleteNodeByValue(int);
  bool deleteNodeAfterValue(int);
  bool deleteNodeBeforeValue(int);
  bool insertNodeAfter(int, int);
  int findLengthOfList();
  void traverseLinkedList();
  void reverseTraverseLinkedList();
  void printMiddle();
  void createNodeAtLast(int);
};
#endif //LINKED_LIST_H