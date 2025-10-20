#include "BST.hpp"

int main(void)
{
	srand(time(NULL));

	BST<int> tree;

	for(int i = 0; i < 100; i++)
	{
		tree.insert(rand() % 1000);
	}

	tree.insert(400);

	tree.print();

	if(tree.get(400))
	{
		cout << "Get works." << endl;
	}
	else
	{
		cout << "Get does not work." << endl;
	}

	return 0;
}