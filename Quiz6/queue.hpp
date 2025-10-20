#include <iostream>
#include <string>

using std::string;

class Queue
{
public:
		Queue(int newSize = 0);
		~Queue();

		bool enqueue(string &newItem); 
		bool dequeue(string &removedItem);

		bool isEmpty();

private:
		int mSize; // represents the number of items in the queue
		int mMaxSize; // must not exceed the max size of our allocated array
		string *mpFront; // will point to the beginning of contiguous memory on the heap (an array)
};

//  Description: Inserts the item at the end of the queue. A successful insert 
//             increases mSize by 1.
//
// Returns: True if the item was inserted into the contiguous memory; false otherwise.
//
// Precondition: mpFront must already point to contiguous memory; specifically 
//               item at index 0.
//
// Errors: Check that mSize does not exceed mMaxSize; if the item cannot be inserted because //         the mMaxSize is exceeded, then return false.

bool Queue::enqueue(string &newItem)
{
    if(mSize < mMaxSize)
    {
        mSize++;
        mpFront[mSize] = newItem;

        return true;
    }
    else
    {
        return false;
    }
}