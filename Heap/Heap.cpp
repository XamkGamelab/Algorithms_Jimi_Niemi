#include "Heap.h"
#include <iostream>

Heap::Heap(int size)
{
	//SET THE START VALUES
	maxSize = size;
	heapArray.resize(size + 1);   
	heapArray[0] = 0;             
}

void Heap::insert(int key)
{
	if (length() >= maxSize)
	{
		return;
	}

	if (length() < 1)
	{
		heapArray[1] = key;
		heapArray[0]++;
		return;
	}

	int index = length() + 1;
	heapArray[index] = key;
	heapArray[0]++;

	int parent_index = index / 2;
	while(heapArray[parent_index] > heapArray[index] && index > 1)
	{
		int tmp = heapArray[parent_index];
		heapArray[parent_index] = heapArray[index];
		heapArray[index] = tmp;

		index = parent_index;
		parent_index = index / 2;
	}

	return;
}

int Heap::del_min()
{
	if (length() <= 0)
	{
		return -1;
	}

	int min = heapArray[1];
	int lastIndex = heapArray[length()];
	heapArray[1] = lastIndex;
	heapArray[0]--;

	int current = 1;
	while (true)
	{
		int left = current * 2;
		int right = current * 2 + 1;

		// IF THERE IS NO CHILDREN, WE ARE AT THE BOTTOM
		if (left > length())
		{
			break;
		}

		//CHECK THE SMALLER CHILD
		int smaller = left;
		if (right <= length() && heapArray[right] < heapArray[left])
		{
			smaller = right;
		}

		// BREAK WHEN SMALLEST IS FOUND
		if (heapArray[current] <= heapArray[smaller])
		{
			break;
		}

		// SWAP TO THE SMALLER AND KEEP GOING
		int temp = heapArray[current];
		heapArray[current] = heapArray[smaller];
		heapArray[smaller] = temp;
		current = smaller;
	}

	return min;
}

void Heap::print()
{
	for (int i = 1; i <= length(); ++i) {
		std::cout << heapArray[i] << " ";
	}

	std::cout << std::endl;
}

