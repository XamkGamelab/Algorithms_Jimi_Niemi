// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	const unsigned n = 94;
	unsigned long long Array[n];

	Array[0] = 0;
	Array[1] = 1;

	for (int i = 2; i < n; ++i)
	{
		Array[i] = Array[i - 1] + Array[n - 2];
	}

	for (int i = 1; i < n; ++i)
	{
		std::cout << "Fibonaccis value is: " << Array[i] << std::endl;
	}

	return 0;
}
