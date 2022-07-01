// Problem Link -https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/* By Krishna Kumar */
#include <iostream>
#include <vector>
using namespace std;
bool isSafePosition(vector<vector<int>> &sudoku, int row, int col, int val)
{
    // checking in column
    for (int i = 0; i <= 8; i++)
    {
        // checking in row
        if (sudoku[i][col] == val)
        {
            return false;
        }
        // checking in col
        if (sudoku[row][i] == val)
        {
            return false;
        }
        if (sudoku[row / 3 * 3 + i /3 ][col / 3 * 3 + i % 3] == val)
            return false;
    }

    return true;
}
bool solveSudoku(vector<vector<int>> &sudoku)
{
    for (int row = 0; row <= 8; row++)
    {
        for (int col = 0; col <= 8; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafePosition(sudoku, row, col, val))
                    {
                        sudoku[row][col] = val;
                        bool furtherSolutionPossible = solveSudoku(sudoku);
                        if (furtherSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
}