#pragma once
#include <iostream>
#include "Node.h"

class LinkedList
{

public:

	bool IsEmpty();
	void Insert(int value);
	void InsertEnd(int value);
	void Print();
	void Find(int value);
	void Delete(int value);

	LinkedList()
	{
		pHead = nullptr;
	}

private: 

	Node* pHead;
};
