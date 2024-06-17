#include <iostream>
#include <vector>
#include <Windows.h>
#include "../QuickSort/IQuickSort.h"
#include <string>
#include "../n-Queen/n-Queen.h"
#include "../Prod-RecursiveIntegerMultiplication/IProd.h"
#include "../StrassenMatrixMultiplication/IStrassen.h"


void ChangeText();
int SelectedAlgorithm = 1;

// Function to set console text color
static void SetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void ChangeText()
{
#if defined(_WIN32)
	system("cls");
#elif defined(__LINUX__)
	system("clear");
#endif

	std::cout << "Please select the algorithm you want to experiment with: \n";

	std::string options[] = {
		"QuickSort",
		"N-Queen",
		"Prod-RecursiveIntegerMultiplication",
		"StrassenMatrixMultiplication"
	};

	for (int i = 0; i < 4; ++i)
	{
		if (SelectedAlgorithm == i + 1)
		{
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // White
			std::cout << "-> " << options[i] << "\n";
		}
		else
		{
			SetConsoleColor(FOREGROUND_INTENSITY); // Gray
			std::cout << "   " << options[i] << "\n";
		}
	}

	// Reset to default console color
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


static void QuickSort()
	{
		//Quick Sort
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

static void NQueen()
	{
		int N, numQueens;
		std::cout << "Enter the size of the board (N): ";
		std::cin >> N;
		std::cout << "Enter the number of queens already placed: ";
		std::cin >> numQueens;

		std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
		std::cout << "Enter the positions of the queens (row and column):\n";
		for (int i = 0; i < numQueens; ++i)
		{
			int row, col;
			std::cin >> row >> col;
			board[row][col] = 1;
		}

		SolveNQueens(board, numQueens);
	}

static void ProdRecursive()
	{
		int x, y;
		std::cout << "Enter x : ";
		std::cin >> x;
		std::cout << "Enter y : ";
		std::cin >> y;
		std::cout << "Answer : " << prod(x, y) << std::endl;
	}

	static void Strassen()
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

		std::cout << "Result of matrix multiplication:" << std::endl;
		print(C, N);
	}

int main()
{
	ChangeText();
	while (true)
	{
		if (GetKeyState(VK_UP) & 0x8000)
		{
			SelectedAlgorithm--;
			if (SelectedAlgorithm > 4) SelectedAlgorithm = 1;
			ChangeText();
			Sleep(150);  // Debounce
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			SelectedAlgorithm++;
			if (SelectedAlgorithm < 1) SelectedAlgorithm = 4;
			ChangeText();
			Sleep(150);  // Debounce
		}
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			break;
		}
	}

	std::cout << "You selected algorithm number " << SelectedAlgorithm << ".\n";



	switch (SelectedAlgorithm)
	{
	case 1:
		QuickSort();
		break;
	case 2:
		NQueen();
		break;
	case 3:
		ProdRecursive();
		break;
	case 4:
		Strassen();
		break;
	}

	std::cout << "Thanks for using the program :)" << "\n";
	return 0;
}
