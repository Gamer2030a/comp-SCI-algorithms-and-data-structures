#include <iostream>
#include "IStrassen.h"
#include <vector>

int main()
{
    int n;
    cout << "Enter the size of the square matrices (power of 2): ";
    cin >> n;

    // Input matrices A and B
    vector<vector<int>> A = inputMatrix(n);
    vector<vector<int>> B = inputMatrix(n);

    // Perform Strassen matrix multiplication
    vector<vector<int>> C = strassenMatrixMultiplication(A, B);

    // Print the result
    cout << "Result of matrix multiplication:" << endl;
    printMatrix(C);

    return 0;
}
