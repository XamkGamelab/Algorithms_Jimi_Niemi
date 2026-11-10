#include "Heap.h"
#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>     

void HeapSort(std::vector<int>& numbers, int count)
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

bool IsSorted(std::vector<int>& numbers, int count)
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

void TestSort(int count)
{
    std::vector<int> numbers(count);

    //SET THE RANDOM NUMBERS
    for (int i = 0; i < count; i++)
    {
        numbers[i] = rand();
    }

    //CHECK THE TIME BETWEEN BEFORE AND AFTER SORT
    clock_t start = clock();
    HeapSort(numbers, count);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    //PRINT THE TIME HOW LONG IT TOOK TO SORT THE NUMBERS
    std::cout << count << " numbers: " << seconds << " seconds!";

    if (IsSorted(numbers, count))
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
    // HEAP TEST
    Heap heap(20);
    int data[] = { 17, 11, 6, 14, 22, 8, 1, 16, 10, 19, 12, 3, 5, 15, 13 };

    for (int i = 0; i < 15; i++)
    {
        heap.insert(data[i]);
    }

    std::cout << "Heap after inserts: ";
    heap.print();

    std::cout << "Removed: " << heap.del_min() << std::endl;
    std::cout << "Heap after del_min: ";
    heap.print();
    std::cout << std::endl;

    // SORTING AND TIMING
    srand(time(0));

    TestSort(100000);
    TestSort(1000000);
    TestSort(10000000);

    return EXIT_SUCCESS;
}