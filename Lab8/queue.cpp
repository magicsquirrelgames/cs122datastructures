#include "queue.hpp"

void Queue::enqueue(string newData)
{
    Node* newNode = new Node(newData);

    if(!head) head = newNode;
    if(tail) tail->setNext(newNode);
    tail = newNode;
}

string Queue::dequeue()
{
    if(!isEmpty())
    {
        string data = head->getData();
        Node* nodeToDelete = head;
        if(head->getNext())
        {
            head = head->getNext();
            delete nodeToDelete;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
        }
        return data;
    }
    else
    {
        return "";
    }
}

void Queue::printQueueRecursive()
{
    if(head)
    {
        printQueueRecursive(head);  
        cout << endl;
    } 
}

void Queue::printQueueRecursive(Node* current)
{
    cout << current->getData();
    if(current->getNext())
    {
        cout << ",";
        printQueueRecursive(current->getNext());
    }
}