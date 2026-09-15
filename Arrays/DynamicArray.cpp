// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	unsigned n = 10;
	int* Parray = new int[n];

	for (int i = 0; i < n; i++)
	{
		Parray[i] = 0;
		std::cout << Parray[i] << std::endl;
	}

	Parray = new int[n + 10];

	for (int i = 0; i < n; i++)
	{
		Parray[i] = 0;
		std::cout << Parray[i] << std::endl;
	}

	delete[] Parray;
}

