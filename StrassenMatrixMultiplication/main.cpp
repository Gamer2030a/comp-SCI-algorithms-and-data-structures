#include <iostream>
#include "IStrassen.h"
#include <vector>

int main()
{
  size N = 4;

    //Matrix A
    Matrix A = createMatrix(N);
    A[0][0] = 5; A[0][1] = 2; A[0][2] = 8; A[0][3] = 7;
    A[1][0] = 1; A[1][1] = 7; A[1][2] = 7; A[1][3] = 8;
    A[2][0] = 3; A[2][1] = 1; A[2][2] = 6; A[2][3] = 2;
    A[3][0] = 2; A[3][1] = 4; A[3][2] = 7; A[3][3] = 7;

    //Matrix B
    Matrix B = createMatrix(N);
    B[0][0] = 7; B[0][1] = 1; B[0][2] = 8; B[0][3] = 9;
    B[1][0] = 2; B[1][1] = 7; B[1][2] = 2; B[1][3] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 9; B[2][3] = 8;
    B[3][0] = 9; B[3][1] = 5; B[3][2] = 1; B[3][3] = 7;

    //Call the Strassen function
    Matrix C = strassen(A, B, N);

    cout << "Result of matrix multiplication:" << endl;
    printMatrix(C, N);
    return 0;
}
