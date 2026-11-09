#include <iostream>
#include <vector>

class Heap {

public:

	Heap(int size);
	int length() { return heapArray[0]; }
	void insert(int key);
	int del_min();
	void print();

private:

	int maxSize;
	std::vector<int> heapArray;
};