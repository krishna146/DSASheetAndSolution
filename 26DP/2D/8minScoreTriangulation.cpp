// Problem Link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &values, int i, int j)
    {
        if (i + 1 == j)
            return 0;
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(values[i] * values[k] * values[j] + recursive(values, i, k) + recursive(values, k, j), ans);
        }
        return ans;
    }
    int topDown(vector<int> &values, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(values[i] * values[k] * values[j] + topDown(values, i, k, dp) + topDown(values, k, j, dp), ans);
        }
        return dp[i][j] = ans;
    }
    int bottomUp(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(values[i] * values[k] * values[j] + dp[i][k] + dp[k][j], ans);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        // return recursive(values, 0, n - 1);
        // vector<vector<int>> dp(n , vector<int>(n, -1));
        // return topDown(values, 0, n - 1, dp);
        return bottomUp(values);
    }
};