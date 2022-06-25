// Problem Link - https://leetcode.com/problems/n-queens/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool isPositionSafe(int row, int col, unordered_map<int, bool> &flagRow, unordered_map<int, bool> &flagLowerDiagonal, unordered_map<int, bool> &flagUpperDiagonal)
{
    if (flagRow[row])
    {
        return false;
    }
    if (flagLowerDiagonal[row + col])
    {
        return false;
    }
    if (flagUpperDiagonal[row - col])
    {
        return false;
    }
    return true;
}
void printPlaces(int currCol, unordered_map<int, bool> &flagRow, unordered_map<int, bool> &flagLowerDiagonal, unordered_map<int, bool> &flagUpperDiagonal, int n, vector<int> &ans, vector<vector<int>> &fans)
{
    if (currCol == n)
    {

        fans.push_back(ans);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        bool isPoistionIsSafe = isPositionSafe(row, currCol, flagRow, flagLowerDiagonal, flagUpperDiagonal);
        if (isPoistionIsSafe)
        {
            flagRow[row] = true;
            flagLowerDiagonal[row + currCol] = true;
            flagUpperDiagonal[row - currCol] = true;
            ans.push_back(row + 1);
            printPlaces(currCol + 1, flagRow, flagLowerDiagonal, flagUpperDiagonal, n, ans, fans);
            flagRow[row] = false;
            flagLowerDiagonal[row + currCol] = false;
            flagUpperDiagonal[row - currCol] = false;
            ans.pop_back();
        }
    }
}
int main()
{
    int n = 4;
    unordered_map<int, bool> flagRow;
    unordered_map<int, bool> flaglowerDiagonal;
    unordered_map<int, bool> flagUpperDiagonal;
    vector<vector<int>> fans;
    vector<int> ans;
    printPlaces(0, flagRow, flaglowerDiagonal, flagUpperDiagonal, 4, ans, fans);
    for (auto row : fans)
    {
        for (auto el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}