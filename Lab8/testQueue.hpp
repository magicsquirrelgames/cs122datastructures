#include "queue.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class TestQueue
{
    public:
        void runTests();
        void testIsEmpty();
        void testEnqueue();
        void testDequeue();
        void testPrintQueueRecursive();
};

void TestQueue::runTests()
{
    testIsEmpty();
    testEnqueue();
    testDequeue();
    testPrintQueueRecursive();
}   

void TestQueue::testIsEmpty()
{
    cout << "Testing isEmpty()." << endl;

    Queue queue;
    if(queue.isEmpty())
    {
        cout << GREEN << "Test succeeded." << RESET << endl;
    }
    else
    {
        cout << RED << "Test failed." << RESET << endl;
    }
}

void TestQueue::testEnqueue()
{
    cout << "Testing enqueue()." << endl;

    Queue queue;
    try
    {
        queue.enqueue("dog");
        queue.enqueue("cat");

        cout << GREEN << "Test succeeded." << RESET << endl;
    }
    catch(const exception& e)
    {
        cout << RED << "Test failed." << RESET << endl;
    }
}

void TestQueue::testDequeue()
{
    cout << "Testing dequeue()." << endl;
    Queue queue;
    queue.enqueue("dog");
    string result = queue.dequeue();

    if(result == "dog")
    {
        cout << GREEN << "Test succeeded." << RESET << endl;
    }
    else
    {
        cout << RED << "Test failed." << RESET << endl;
    }
}

void TestQueue::testPrintQueueRecursive()
{
    cout << "Testing printQueueRecursive(). Expected output: 1,2,3,4,5" << endl;
    Queue queue;
    for(int i = 1; i <= 5; i++)
    {
        queue.enqueue(to_string(i));
    }
    queue.printQueueRecursive();
}