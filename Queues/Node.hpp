#pragma once

#include <iostream>
#include <string>

using std::string;

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Node
{
public:

	Node();
	Node(const string& str);

	Node* GetMpNext() const;
	void SetMpNext(Node* next);

	const string& GetPrintJob() const;

private:
	string mPrintJob;
	Node* mpNext;
};