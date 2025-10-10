// This example implements a queue from the ground up and applies
// the queue to storing print jobs. 

// History: 10/1/25 - We started to implement a queue in C++. A queue is a 
//                    First In, First Out (FIFO) data structure. We implemented
//                    the basic attributes of a class Node and Queue. We implemented
//                    the default constructor for a Queue and started working on 
//                    the enqueue () function.
// 
//			10/3/25 - Cleaned up file io related code to focus on queue related material.
//					  We finished up the enqueue function, implemented dequeue, isEmpty,
//					  print, clear, and the destructor. Started on deep copy constructor.
//

#include "Queue.hpp"
#include <fstream>
#include <string>

using std::ifstream;
using std::ios;

// TODO LIST:
// ------finish enqueue
// ------dequeue
// ------print queue
// ------isEmpty
// ------destroy queue (+ destructor)
// - deep copy constructor


int main(void)
{
	Queue<int> q1;

	return 0;
}