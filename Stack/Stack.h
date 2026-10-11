#pragma once

#include <iostream>
#include "Node.h"

template<typename T>class Stack
{
public:

	Stack() { pTop = nullptr; }
	bool IsEmpty() { return pTop == nullptr; }
	void Push(T Data) {
		Node<T> pNewNode = new Node<T>(Data);
		pNewNode->pNext = pTop;
		ptop = pNewNode;
	}

	T Pop() {
		if (IsEmpty()) return static_cast<T>(-1);
		Node<T> pToBeDeleted = pTop;
		T value = pToBeDeleted->Data;
		pTop = pToBeDeleted->pNext;

		delete pToBeDeleted;
		return value;
	}

	T Top() {
		if (IsEmpty()) return static_cast<T>(-1);

		return pTop->Data;
	}

private:

	Node<T>* pTop;
};