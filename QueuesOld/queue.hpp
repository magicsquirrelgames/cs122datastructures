#pragma once

#include <iostream>
#include <string>

using namespace std;


// NODE ==========================================
class Node
{
    public:
        Node(string newPrintJob);

        Node* GetNext() const;
        void SetNext(Node* newNext);

        const string& GetPrintJob() const;
    private:
        string printJob;
        Node* next;
};

Node::Node(string newPrintJob)
{
    printJob = newPrintJob;
}

void Node::SetNext(Node* newNext)
{
    this->next = newNext;
}

const string& Node::GetPrintJob() const
{
    return this->printJob;
}

// QUEUE ==========================================
class Queue
{
    public:
        Queue();
        ~Queue();
        Queue(const Queue& copy);

        bool enqueue(const string &newPrintJob);
        string dequeue();

        void print();
        void clear();

        bool isEmpty();
    private:
        Node *head;
        Node *tail;
};

Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue()
{
    this->clear();
}

Queue::Queue(const Queue& copy)
{
    Node* current = copy.head;
    while(current)
    {
        enqueue(current->GetPrintJob());
        current = current->GetNext();
    }
}

bool Queue::enqueue(const string &newPrintJob)
{
    Node *newNode = new Node(newPrintJob);

    if(this->tail == nullptr)
    {
        this->tail = newNode;
        this->head = newNode;
        return true;
    }

    this->tail->SetNext(newNode);
    this->tail = newNode;

    return true;
}

void Queue::print()
{
    Node* current = this->head;
    while(current != nullptr)
    {
        cout << current->GetPrintJob() << endl;
        current = current->GetNext();
    }
}

string Queue::dequeue()
{
    if(this->head == nullptr)
    {
        return "";
    }

    string string = this->head->GetPrintJob();
    Node* temp = this->head;
    
    if(this->tail == this->head) this->tail = nullptr;
    
    this->head = this->head->GetNext();

    delete temp;

    return string;
}

void Queue::clear()
{
    while(head != nullptr)
    {
        dequeue();
    }
}

bool Queue::isEmpty()
{
    return this->head == nullptr;
}