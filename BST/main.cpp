#include "BST.h"
#include <iostream>

int main()
{
	BST tree;

	//ADD NUMBERS
	tree.Insert(50);
	tree.Insert(30);
	tree.Insert(70);
	tree.Insert(20);
	tree.Insert(40);
	tree.Insert(60);
	tree.Insert(80);

	//PRINT THE TREE
	tree.Print();

	//COUNT AND FIND (1 = TRUE, 0 = FALSE)
	std::cout << "Nodes: " << tree.CountNodes() << std::endl;
	std::cout << "Leaves: " << tree.CountLeaves() << std::endl;
	std::cout << "Find 40: " << tree.Find(40) << std::endl;

	//DELETE THE ROOT AND PRINT AGAIN
	tree.Delete(50);
	tree.Print();

	return 0;
}