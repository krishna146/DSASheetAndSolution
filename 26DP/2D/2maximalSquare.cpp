// Problem Link - https://leetcode.com/problems/maximal-square/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int topDown(vector<vector<char>> &matrix, int row, int col, int &ans, vector<vector<int>> &dp)
    {
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int bottom = topDown(matrix, row + 1, col, ans, dp);
        int diagonal = topDown(matrix, row + 1, col + 1, ans, dp);
        int right = topDown(matrix, row, col + 1, ans, dp);
        int tempAns = 0;
        if (matrix[row][col] == '1')
        {
            tempAns = 1 + min(bottom, min(diagonal, right));
            ans = max(tempAns, ans);
        }
        return dp[row][col] = tempAns;
    }
    int bottomUp(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int ans = 0;
        for (int row = matrix.size() - 1; row >= 0; row--)
        {
            for (int col = matrix[0].size() - 1; col >= 0; col--)
            {
                int bottom = dp[row + 1][col];
                int diagonal = dp[row + 1][col + 1];
                int right = dp[row][col + 1];
                int tempAns = 0;
                if (matrix[row][col] == '1')
                {
                    tempAns = 1 + min(bottom, min(diagonal, right));
                    ans = max(tempAns, ans);
                }
                dp[row][col] = tempAns;
            }
        }
        return ans * ans;
        ;
    }
    int spaceOptimized(vector<vector<char>> &matrix)
    {
        vector<int> nextRowAns(matrix[0].size() + 1, 0);
        int ans = 0;
        for (int row = matrix.size() - 1; row >= 0; row--)
        {
            int nextColAns = 0;
            int diagonalColAns = 0;
            for (int col = matrix[0].size() - 1; col >= 0; col--)
            {
                int bottom = nextRowAns[col];
                int diagonal = diagonalColAns;
                int right = nextColAns;
                int tempAns = 0;
                if (matrix[row][col] == '1')
                {
                    tempAns = 1 + min(bottom, min(diagonal, right));
                    ans = max(tempAns, ans);
                }
                nextColAns = tempAns;
                diagonalColAns = nextRowAns[col];
                nextRowAns[col] = tempAns;
            }
        }
        return ans * ans;
        ;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        // int ans = 0;
        // vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // topDown(matrix, 0, 0, ans, dp);
        // return ans * ans;
        return spaceOptimized(matrix);
    }
};