#pragma once

class Node 
{
public:

	int Data;
	Node* pNext;
	Node(int data)
	{
		Data = data;
		pNext = nullptr;
	}
};