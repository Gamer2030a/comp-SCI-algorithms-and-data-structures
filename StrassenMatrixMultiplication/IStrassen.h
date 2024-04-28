#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to perform Strassen matrix multiplication
vector<vector<int>> strassenMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: when matrix size is 1x1
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide matrices into submatrices
    int halfSize = n / 2;
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));

    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    // Recursive calls for the submatrices
    vector<vector<int>> P1 = strassenMatrixMultiplication(A11, subtractMatrix(B12, B22));
    vector<vector<int>> P2 = strassenMatrixMultiplication(addMatrix(A11, A12), B22);
    vector<vector<int>> P3 = strassenMatrixMultiplication(addMatrix(A21, A22), B11);
    vector<vector<int>> P4 = strassenMatrixMultiplication(A22, subtractMatrix(B21, B11));
    vector<vector<int>> P5 = strassenMatrixMultiplication(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> P6 = strassenMatrixMultiplication(subtractMatrix(A12, A22), addMatrix(B21, B22));
    vector<vector<int>> P7 = strassenMatrixMultiplication(subtractMatrix(A11, A21), addMatrix(B11, B12));

    // Calculate the resulting submatrices
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrix(P1, P2);
    vector<vector<int>> C21 = addMatrix(P3, P4);
    vector<vector<int>> C22 = subtractMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);

    // Combine the resulting submatrices
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to input a matrix
vector<vector<int>> inputMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter elements of matrix (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
    
}