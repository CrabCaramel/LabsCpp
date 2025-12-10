#include <iostream>
#include <array>
#include <span>

void arrWithBreak(std::span<int> a, std::span<int> b)
{
    int idx = 0;
    while (true)
    {
        if (idx >= a.size())
            break;

        a[idx] = a[idx] * b[idx];
        idx++;
    }
}

void arrWithWhile(std::span<int> a, std::span<int> b)
{
    int k = 0;
    while (k < a.size())
    {
        a[k] = a[k] * b[k];
        k++;
    }
}

void arrWithFor(std::span<int> a, std::span<int> b)
{
    for (int i = 0; i < a.size(); ++i)
        a[i] = a[i] * b[i];
}

int main()
{
    int arr1[5] = { 1, 2, 3, 4, 5 };
    int arr2[5] = { 2, 4, 5, 8, 10 };

    arrWithBreak(arr1, arr2);
    arrWithWhile(arr1, arr2);
    arrWithFor(arr1, arr2);
}

