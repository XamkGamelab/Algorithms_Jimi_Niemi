// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int array[10];

	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << std::endl;
	}

	int array2[10];

	for (int i = 0; i < 10; i++)
	{
		array2[i] = 0;
		std::cout << array[i] << std::endl;
	}

	int array3[10];
	std::cout << array3[20] << std::endl;
	

	int array4[10];
	array4[10] = 50;
	std::cout << array4[10] << std::endl;
	
}

