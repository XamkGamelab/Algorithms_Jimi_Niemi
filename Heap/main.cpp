#include "Heap.h"
#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>     

void heapSort(std::vector<int>& numbers, int count)
{
    Heap heap(count);

    //INSERT
    for (int i = 0; i < count; i++)
    {
        heap.insert(numbers[i]);
    }
    
    //DEL MIN
    for (int i = 0; i < count; i++)
    {
        numbers[i] = heap.del_min();
    }
}

bool isSorted(std::vector<int>& numbers, int count)
{
    //CHECK IF THE NUMBERS ARE SORTED IN THE COUNT
    for (int i = 1; i < count; i++)
    {
        if (numbers[i - 1] > numbers[i])
        {
            return false;
        }
    }

    return true;
}

void testSort(int count)
{
    std::vector<int> numbers(count);

    //SET THE RANDOM NUMBERS
    for (int i = 0; i < count; i++)
    {
        numbers[i] = rand();
    }
    
    //CHECK THE TIME BETWEEN BEFORE AND AFTER SORT
    clock_t start = clock();
    heapSort(numbers, count);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    //PRINT THE TIME HOW LONG IT TOOK TO SORT THE NUMBERS
    std::cout << count << " numbers: " << seconds << " seconds!";

    if (isSorted(numbers, count))
    {
        std::cout << " Sorted OK!" << std::endl;
    }
    else
    {
        std::cout << " NOT sorted!" << std::endl;
    }
}

int main()
{
    srand(time(0));   

    testSort(100000);
    testSort(1000000);
    testSort(10000000);

    return EXIT_SUCCESS;
}