#include "Node.hpp"

Node::Node() {

	mPrintJob = "";
	mpNext = nullptr;
}

Node::Node(const string& str) {

	mPrintJob = str;
	mpNext = nullptr;
}

Node* Node::GetMpNext() const {
	return mpNext;
}
void Node::SetMpNext(Node* next) {
	mpNext = next;
}

const string& Node::GetPrintJob() const {
	return mPrintJob;
}
