#include "LinkedList.h"

//Linked List constructor definition
LinkedList::LinkedList()
{
    //INTIALIZING WITH NULL
    head = NULL;
    last = NULL;
}

//Creates a node and inserts it at last
void LinkedList::createNodeAtLast(int data)
{
    if (head == NULL)
    {
        //IF THE HEAD IS NULL IT CREATES A STARTING NODE FOR IT
        Node *temp = new Node(data);
        head = temp;
        last = head;
    }
    else
    {
        //CREATES THE NODES LINKING TO FIRST NODE
        last->next = new Node(data);
        last->next->prev = last;
        last = last->next;
    }
}

//Deletes the node from beginning of the list
//PROBLEM STATEMENT:DELETE THE WHOLE LINKED LIST(Function gets called again and again to delete the whole list)
bool LinkedList::deleteFirstNode()
{
    Node *temp = NULL;
    if (head == NULL)
    {
        //PRINTS A EMPTY IF THE HEAD IS NULL
        std::cout << "\n****List is empty.****" << std::endl;
        return false;
    }
    else
    {
        //UPDATES THE STARTING POINTER TO NEXT NODE
        temp = head;
        head = head->next;
        temp->next = NULL;
    }
    delete temp;
    return true;
}

//Traverses the list and prints it
//PROBLEM STATEMENT: FIND THE LENGTH OF A LINKED LIST
int LinkedList::findLengthOfList()
{
    Node *curr = head;
    int length = 0;
    if (curr == NULL)
    {
        //PRINTS A EMPTY IF THE HEAD IS NULL
        std::cout << "\n****List is empty.****" << std::endl;
    }
    else
    {
        for (; curr != NULL; curr = curr->next)
        {
            ++length;
        }
    }
    return length;
}
void LinkedList::traverseLinkedList()
{
    Node *curr = head;
    if (curr == NULL)
    {
        //PRINTS A EMPTY IF THE HEAD IS NULL
        std::cout << "\n****List is empty.****" << std::endl;
    }
    else
    {
        for (int i = 1; curr != NULL; curr = curr->next, ++i)
        {
            std::cout << "\nNode "
                      << i
                      << " data: "
                      << curr->data
                      << std::endl
                      << std::endl;
        }
    }
}
void LinkedList::reverseTraverseLinkedList()
{
    Node *curr = last;
    if (curr == NULL)
    {
        //PRINTS A EMPTY IF THE HEAD IS NULL
        std::cout << "\n****List is empty.****" << std::endl;
    }
    else
    {
        for (int i = findLengthOfList(); curr != NULL; curr = curr->prev, --i)
        {
            std::cout << "\nNode "
                      << i
                      << " data: "
                      << curr->data
                      << std::endl
                      << std::endl;
        }
    }
}
//PROBLEM STATEMENT: PRINT THE MIDDLE NODE
void LinkedList::printMiddle()
{
    Node *curr = head;
    if (curr == NULL)
    {
        std::cout << "\n****List is empty.****" << std::endl;
    }
    else
    {
        int middle = (findLengthOfList() / 2);
        for (int i = 1; i != middle; curr = curr->next)
        {
        }
        std::cout << "\nData of the Node is : " << (curr->data) << std::endl;
    }
}
Node *LinkedList::getHeadVal()
{
    return head;
}
Node *LinkedList::findNodeByValue(int value)
{
    Node *curr = head;
    if (head == NULL)
    {
        std::cout << "\n*****List is empty.*****" << std::endl;
    }
    else
    {
        for (; curr != NULL; curr = curr->next)
        {
            if (curr->data == value)
                return curr;
        }
    }
    return NULL;
}
bool LinkedList::deleteNodeByValue(int value)
{
    Node *curr = findNodeByValue(value);
    Node *temp = NULL;
    if (curr == NULL)
    {
        return false;
    }
    else if (curr->next == NULL)
    {
        temp = curr;
        curr->prev->next = NULL;
        curr->prev = NULL;
    }
    else if (curr->prev == NULL)
    {
        temp = curr;
        head = curr->next;
        curr->next = NULL;
    }
    else
    {
        temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
    }
    delete temp;
    return true;
}
bool LinkedList::deleteNodeAfterValue(int value)
{
    Node *curr = findNodeByValue(value);
    curr = curr->next;
    Node *temp = NULL;
    if (curr == NULL)
    {
        return false;
    }
    else if (curr->next == NULL)
    {
        std::cout << "\nNo Nodes after the value." << std::endl;
        return false;
    }
    else
    {
        temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
    }
    delete temp;
    return true;
}
bool LinkedList::deleteNodeBeforeValue(int value)
{
    Node *curr = findNodeByValue(value);
    curr = curr->prev;
    Node *temp = NULL;
    if (curr == NULL)
    {
        return false;
    }
    else if (curr->prev == NULL)
    {
        std::cout << "\nNo Nodes before the value." << std::endl;
    }
    else
    {
        temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
    }
    delete temp;
    return true;
}
bool LinkedList::insertNodeAfter(int value, int data)
{
    Node *temp = new Node(data);
    Node *curr = findNodeByValue(value);
    if (curr == NULL)
    {
        return false;
    }
    else if (curr->next == NULL)
    {
        curr->next = temp;
    }
    else
    {
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
    }
    return true;
}
bool LinkedList::mergeLinkedList(LinkedList *user)
{
    if (user->head == NULL)
    {
        std::cout << "\n*****Linked List 2 is empty.*****" << std::endl;
        return false;
    }
    if (this->head == NULL)
    {
        this->head = user->head;
        this->last = user->last;
        user->head = NULL;
        user->last = NULL;
    }
    else
    {
        this->last->next = user->head;
        user->head->prev = last;
        this->last = user->last;
        user->last = NULL;
        user->head = NULL;
    }
    return true;
}