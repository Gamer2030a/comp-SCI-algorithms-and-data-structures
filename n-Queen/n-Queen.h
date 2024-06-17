#include <iostream>
#include <vector>

void PrintSolution(const std::vector<std::vector<int>>& board)
{
    int N = board.size();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << (board[i][j] ? "Q " : ". ");
        }
        std::cout << "\n";
    }
}

bool IsSafe(const std::vector<std::vector<int>>& board, int row, int col)
{
    int N = board.size();
    // Check this row on the left side
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool SolveNQueensUtil(std::vector<std::vector<int>>& board, int col)
{
    int N = board.size();
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; ++i)
    {
        if (IsSafe(board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (SolveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

bool SolveNQueens(std::vector<std::vector<int>>& board, int numQueens)
{
    int N = board.size();
    int col = 0;
    // Find the first empty column to start the backtracking from
    for (col = 0; col < N; ++col)
    {
        bool found = false;
        for (int row = 0; row < N; ++row)
        {
            if (board[row][col] == 1)
            {
                found = true;
                break;
            }
        }
        if (!found) break;
    }

    if (!SolveNQueensUtil(board, col))
    {
        std::cout << "Solution does not exist\n";
        return false;
    }

    PrintSolution(board);
    return true;
}