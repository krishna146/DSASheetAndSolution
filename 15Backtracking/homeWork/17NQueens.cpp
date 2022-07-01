// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool isSafe(int row, int col, unordered_map<int, bool> &visitedRow, unordered_map<int, bool> &visitedUpperDiagonal, unordered_map<int, bool> &visitedLowerDiagonal)
    {
        if (visitedRow[row])
            return false;
        if (visitedLowerDiagonal[row + col])
            return false;
        if (visitedUpperDiagonal[row - col])
            return false;
        return true;
    }

private:
    void solve(int col, unordered_map<int, bool> &visitedRow, unordered_map<int, bool> &visitedUpperDiagonal, unordered_map<int, bool> &visitedLowerDiagonal, vector<vector<string>> &ans, int &n, vector<string> &temp)
    {
        if (col == n)
        {
            ans.push_back(temp);

            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (isSafe(row, col, visitedRow, visitedUpperDiagonal, visitedLowerDiagonal))
            {
                visitedRow[row] = true;
                visitedLowerDiagonal[row + col] = true;
                visitedUpperDiagonal[row - col] = true;
                temp[row][col] = 'Q';
                solve(col + 1, visitedRow, visitedUpperDiagonal, visitedLowerDiagonal, ans, n, temp);
                visitedRow[row] = false;
                visitedLowerDiagonal[row + col] = false;
                visitedUpperDiagonal[row - col] = false;
                temp[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_map<int, bool> visitedRow;
        unordered_map<int, bool> visitedUpperDiagonal;
        unordered_map<int, bool> visitedLowerDiagonal;
        int col = 0;
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(col, visitedRow, visitedUpperDiagonal, visitedLowerDiagonal, ans, n, temp);
        return ans;
    }
};
int main()
{
    Solution Obj;
    vector<vector<string>> ans = Obj.solveNQueens(4);
    for (auto el : ans)
    {
        for (auto temp : el)
        {
            cout << temp << endl;
        }
        cout << endl;
    }
}