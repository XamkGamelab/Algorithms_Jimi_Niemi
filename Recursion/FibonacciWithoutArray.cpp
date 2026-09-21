// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	const unsigned n = 94;
	unsigned long long First = 0;
	unsigned long long Second = 1;

	for (int i = 2; i < n; ++i)
	{
		long long Sum = First + Second;
		First = Second;
		Second = Sum;

		std::cout << "Fibonaccis value is: " << Second << std::endl;
	}

	return 0;
}
