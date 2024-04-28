#include <iostream>
#include "IQuickSort.h"
#include <vector>

int main()
{
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    std::cout << "Sorted array: \n";
    printArray(arr);
}
