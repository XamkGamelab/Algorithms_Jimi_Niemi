#pragma once

template<typename T> class Node {

public:

	T Data;
	Node* pNext;

	Node(T data) {
		this->Data = Data;
		this->pNext = nullptr;
	}
};