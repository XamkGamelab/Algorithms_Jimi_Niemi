#include <iostream>

int LinearSearch(int* a, int x, int n)
{
    int i = 0;
    while (i < n && a[i] <= x)
    {
        if (a[i] == x) return i;
        i++;
    }

    return -1;
}

static int* allocateMemory(unsigned n)
{
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = i;
    }

    return array;
}

int BinarySearch(int* a, int x, unsigned n)
{
    long long left = 0, right = (long long)n - 1;  

    while (left <= right)                           
    {
        long long mid = left + (right - left) / 2;

        if (a[mid] == x)
        {
            return (int)mid;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    unsigned n = 100;
    int* a = allocateMemory(n);
    int x = 42;

    std::cout << "Linear search(" << a << ", " << x << ", " << n << ") = " << LinearSearch(a, x, n) << std::endl;
    std::cout << "Binary§ search(" << a << ", " << x << ", " << n << ") = " << BinarySearch(a, x, n) << std::endl;

    return EXIT_SUCCESS;
}