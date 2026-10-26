#pragma once
#include "BSTNode.h"

class BST 
{

public:

	BST() { pRoot = nullptr; }
	bool IsEmpty() { return pRoot == nullptr; }
	void Insert(int value);
	bool Delete(int value);
	bool Find(int value);
	void Print();
	int CountNodes();
	int CountLeaves();

private:

	BSTNode* pRoot;
};