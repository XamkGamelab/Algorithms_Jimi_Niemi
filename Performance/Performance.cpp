#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;   // time

//Linear Search
int LinearSearch(int* a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) return i;
    }

    return -1;
}

//Binary Search
int BinarySearch(int* a, int x, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
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
    int sizes[] = { 100000, 1000000, 10000000 };
    const int R = 1000;                         

    for (int n : sizes)
    {
        int* a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }

        volatile long long sink = 0;          

        //Calculating times between start and end of the search
        auto t0 = steady_clock::now();

        for (int k = 0; k < R; k++)
        {
            sink += LinearSearch(a, k * (n / R), n);
        }
        auto t1 = steady_clock::now();

        for (int k = 0; k < R; k++)
        {
            sink += BinarySearch(a, k * (n / R), n);
        }

        auto t2 = steady_clock::now();

        double lin = duration<double, milli>(t1 - t0).count();
        double bin = duration<double, milli>(t2 - t1).count();

        //Printing the times
        cout << "n=" << n
            << "  linear " << lin << " ms (" << lin / R * 1000 << " us avg)"
            << "  binary " << bin << " ms (" << bin / R * 1000 << " us avg)\n";

        delete[] a;
    }
}