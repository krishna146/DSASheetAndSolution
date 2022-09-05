// Problem Link - https://leetcode.com/problems/guess-number-higher-or-lower-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(int low, int high)
    {
        if (low >= high)
            return 0;
        int ans = INT_MAX;
        for (int num = low; num <= high; num++)
        {
            ans = min(max(num + recursive(low, num - 1), num + recursive(num + 1, high)), ans);
        }
        return ans;
    }
    int topDown(int low, int high, vector<vector<int>> &dp)
    {
        if (low >= high)
            return 0;
        int ans = INT_MAX;
        if (dp[low][high] != -1)
            return dp[low][high];
        for (int num = low; num <= high; num++)
        {
            ans = min(num + max(topDown(low, num - 1, dp), topDown(num + 1, high, dp)), ans);
        }
        return dp[low][high] = ans;
    }
    int bottomUp(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int low = n; low >= 1; low--)
        {
            for (int high = low + 1; high <= n; high++)
            {
                int ans = INT_MAX;
                for (int num = low; num <= high; num++)
                {
                    ans = min(num + max(dp[low][num - 1], dp[num + 1][high]), ans);
                }
                dp[low][high] = ans;
            }
        }
        return dp[1][n];
    }

public:
    int getMoneyAmount(int n)
    {
        // return recursive(1, n);
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return topDown(1, n, dp);
        return bottomUp(n);
    }
};