
#include <iostream>
#include "LinkedList.h"

bool LinkedList::IsEmpty()
{
	return pHead == nullptr;
}

void LinkedList::Insert(int value)
{
	Node* pNewNode = new Node(value);
	pNewNode->pNext = pHead;
	pHead = pNewNode;
}

void LinkedList::InsertEnd(int value)
{
	Node* pNewNode = new Node(value);
	if (IsEmpty())
	{
		pHead = pNewNode;
		return;
	}

	Node* pCurrent = pHead;
	while (pCurrent->pNext != nullptr)
	{
		pCurrent = pCurrent->pNext;
	}

	pCurrent->pNext = pNewNode;	

}

void LinkedList::Print()
{
	Node* Temp = pHead;
	while (Temp != nullptr)
	{
		std::cout << Temp->Data << std::endl;
		Temp = Temp->pNext;
	}

	std::cout << "NULL" << std::endl;
}

void LinkedList::Find(int value)
{
	Node* Temp = pHead;

	while (Temp != nullptr) 
	{
		if (Temp->Data == value) 
		{
			std::cout << "Value founded: " << Temp->Data << std::endl;
			return;
		}

		Temp = Temp->pNext;
	}

	std::cout << "Not value found: " << value << std::endl;
}

void LinkedList::Delete(int value)
{
	if (IsEmpty())
	{
		std::cout << "List is empty" << std::endl;
		return;
	}


	if (pHead->Data == value)
	{
		Node* pDelete = pHead;
		pHead = pHead->pNext;
		delete pDelete;
		std::cout << "Deleted node: " << value << std::endl;
		return;
	}

	Node* prev = pHead;
	Node* current = pHead->pNext;

	while (current != nullptr)
	{
		if (current->Data == value)
		{
			prev->pNext = current->pNext;
			delete current;
			std::cout << "Deleted node: " << value << std::endl;
			return;
		}

		prev = current;
		current = current->pNext;
	}

	std::cout << "Not value found: " << value << std::endl;

}
