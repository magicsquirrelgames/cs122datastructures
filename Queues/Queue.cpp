#include "Queue.hpp"

Queue::Queue()
{
	this->mpHead = this->mpTail = nullptr; // empty queue
}

// insert back
bool Queue::enqueue(const string& newPrintJob)
{
	Node* pNew = new Node(newPrintJob); // createNode ()

	if (mpTail == nullptr) {
		mpTail = pNew;
		mpHead = pNew;
		return true;
	}

	mpTail->SetMpNext(pNew);
	mpTail = pNew;

	return true;
}

void Queue::print() {

	Node* pCur = mpHead;

	while (pCur) {
		std::cout << pCur->GetPrintJob() << std::endl;
		pCur = pCur->GetMpNext();
	}
}

string Queue::dequeue() {

	if (!mpHead) {
		return "";
	}

	string s = mpHead->GetPrintJob();
	Node* t = mpHead;

	if (mpTail == mpHead) mpTail = nullptr;
	mpHead = mpHead->GetMpNext();
	delete t;

	return s;
}

void Queue::clear() {
	while (mpHead) {
		dequeue();
	}
}

Queue::~Queue() {
	std::cout << "queue is being deleted" << std::endl;
	clear();
}

bool Queue::isEmpty() {
	return mpHead == nullptr;
}

// TODO: fix
//Queue::Queue(const Queue& other) {
//
//	Node* pCur = other.mpHead;
//	while (pCur) {
//		enqueue(pCur->GetPrintJob());
//		pCur = pCur->GetMpNext();
//	}
//}