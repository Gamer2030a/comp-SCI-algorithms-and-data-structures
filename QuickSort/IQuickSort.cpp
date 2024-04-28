#include "IQuickSort.h"
#include <vector>
#include <iostream>

void QuickSort(std::vector<int>& A, int P, int R)
{
	if (P < R) {
		int Q = Partition(A, P, R);
		QuickSort(A, P, Q - 1);
		QuickSort(A, Q + 1, R);
	}
}

int Partition(std::vector<int>& A,int P, int R)
{
	int pivot = A[R];
	int i = P - 1;

	for (int j = P; j < R; j++) {
		if (A[j] <= pivot) {
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[R]);
	return i + 1;
}

void printArray(const std::vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

