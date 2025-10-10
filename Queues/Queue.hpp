#pragma once

#include <iostream>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Queue
{
public:
	Queue(); // make the Queue empty

	// deep copy constructor
	Queue(const Queue& other);

	bool enqueue(const T &newPrintJob);

	T dequeue();

	void print();

	void clear();

	~Queue();

	bool isEmpty();

private:
	Node<T>* mpHead,
		* mpTail;
};