#include <iostream>
#include <utility>
#include <chrono>

void simpleSort(float* a, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] < a[i])
                std::swap(a[j], a[i]);
}


int main(int argc, char* argv[])
{
    const int n = 10000;
    static float a[n];

    //RANDOMIZING THE ARRAY
    for (int i = 0; i < n; ++i)
        a[i] = rand() / (float)RAND_MAX;  

    //STARTING TIME
    auto start = std::chrono::steady_clock::now();

    //USING THE SORTING
    simpleSort(a, n);

    //ENDING TIME
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> time = end - start;
    std::cout << "Sorting " << n << " time took " << time.count() << " ms";

    return 0;
}