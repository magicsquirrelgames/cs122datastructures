#include <iostream>
#include <string>

using namespace std;

// NODE ==================================================================
class Node
{
    private:
        string data;
        Node* next;
    public:
        Node() {data = ""; next = nullptr;}
        Node(string newData) {data = newData; next = nullptr;}
        ~Node() {delete next;}

        string getData() {return data;}
        Node* getNext() {return next;}

        void setData(string newData) {data = newData;}
        void setNext(Node* newNext) {next = newNext;}
};

// QUEUE ==================================================================
class Queue
{
    private:
        Node* head;
        Node* tail;

        void printQueueRecursive(Node* current);
    public:
        Queue() {head = tail = nullptr;}
        Queue(string newData) {head = new Node(newData);}
        ~Queue() {delete head;}

        bool isEmpty() {return head == nullptr;}

        void enqueue(string newData);
        string dequeue();
        void printQueueRecursive();
};