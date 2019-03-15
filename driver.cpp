#include "LinkedList.h"
//NOTE THIS PROGRAM REQUIRES YOU TO CREATE YOUR OWN NODES THROUGH USER INPUT THE OPTION TO CREATE NODES is '6' IN MAIN MENU
int main()
{
    //Creating two lists dynamically
    LinkedList *LLO1 = new LinkedList();
    LinkedList *LLO2 = new LinkedList();
    Node *found = NULL;
    int input{0}, data{0}, data1{0};
    while (1)
    {
        std::cout << "\nPress \n1-To calculate length of linked list.\n2-To delete complete list.\n3-To print middle of node.\n5-To print linked list.\n6-To create node.\n7-To find node.\n8-To delete node by value.\n9-To delete node after value.\n10-To delete node before value.\n11-To insert node after value.\n12-To merge linked list.\n13-To reverse print linked list.\nPress any other key to exit.\nInput:";
        std::cin >> input;

        switch (input)
        {
        case 1:
            std::cout << "\nFind Length of,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                std::cout << "\nLength of linked list is :" << LLO1->findLengthOfList() << std::endl;
            else if (input == 2)
                std::cout << "\nLength of linked list is :" << LLO2->findLengthOfList() << std::endl;
            else
                std::cout << "Invalid Input." << std::endl;
            break;
        case 2:
            std::cout << "\nDelete From,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
            {
                while (LLO1->getHeadVal() != NULL)
                    LLO1->deleteFirstNode();
            }
            else if (input == 2)
            {
                while (LLO2->getHeadVal() != NULL)
                    LLO2->deleteFirstNode();
            }
            else
                std::cout << "\nInvalid Input." << std::endl;

            break;
        case 3:
            std::cout << "\nDelete From,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
            {
                LLO1->printMiddle();
            }
            else if (input == 2)
            {
                LLO2->printMiddle();
            }
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 5:
            std::cout << "\nTo print,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->traverseLinkedList();
            else if (input == 2)
                LLO2->traverseLinkedList();
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 6:
            std::cout << "\nInput data to store: ";
            std::cin >> data;

            std::cout << "\nTo create node in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->createNodeAtLast(data);
            else if (input == 2)
                LLO1->createNodeAtLast(data);
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 7:
            std::cout << "\nInput value to find: ";
            std::cin >> data;

            std::cout << "\nTo find value in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                found = LLO1->findNodeByValue(data);
            else if (input == 2)
                found = LLO2->findNodeByValue(data);
            else
                std::cout << "\nInvalid Input." << std::endl;
            if (found != NULL)
                std::cout << "\nValue has been found." << std::endl;
            break;
        case 8:
            std::cout << "\nInput value to delete: ";
            std::cin >> data;

            std::cout << "\nTo delete value in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->deleteNodeByValue(data);
            else if (input == 2)
                LLO2->deleteNodeByValue(data);
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 9:
            std::cout << "\nInput value to delete after: ";
            std::cin >> data;

            std::cout << "\nTo delete value in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->deleteNodeAfterValue(data);
            else if (input == 2)
                LLO2->deleteNodeAfterValue(data);
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 10:
            std::cout << "\nInput value to delete before: ";
            std::cin >> data;

            std::cout << "\nTo delete value in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->deleteNodeBeforeValue(data);
            else if (input == 2)
                LLO2->deleteNodeBeforeValue(data);
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 11:
            std::cout << "\nInput value to insert after: ";
            std::cin >> data;
            std::cout << "\nInput value to insert: ";
            std::cin >> data1;

            std::cout << "\nTo insert value in,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->insertNodeAfter(data, data1);
            else if (input == 2)
                LLO2->insertNodeAfter(data, data1);
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        case 12:
            LLO1->mergeLinkedList(LLO2);
            break;
        case 13:
            std::cout << "\nTo print,"
                      << "\n1-Linked List 1"
                      << "\n2-Linked List 2"
                      << "\nInput: ";
            std::cin >> input;
            if (input == 1)
                LLO1->reverseTraverseLinkedList();
            else if (input == 2)
                LLO2->reverseTraverseLinkedList();
            else
                std::cout << "\nInvalid Input." << std::endl;
            break;
        default:
            return 0;
        }
    }
}