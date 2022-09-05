// Problem Link - https://leetcode.com/problems/unique-binary-search-trees/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
    int recursive(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        int ways = 0;
        for (int i = 1; i <= n; i++)
        {
            ways += recursive(i - 1) * recursive(n - i);
        }
        return ways;
    }
    int topDown(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return 1;
        int ways = 0;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i <= n; i++)
        {
            ways += topDown(i - 1, dp) * topDown(n - i, dp);
        }
        return dp[n] = ways;
    }
    int bottomUp(int num)
    {
        vector<int> dp(num + 1, 1);
        for (int n = 2; n <= num; n++)
        {
            int ways = 0;
            for (int i = 1; i <= n; i++)
            {
                ways += dp[i - 1] * dp[n - i];
            }
            dp[n] = ways;
        }
        return dp[num];
    }

public:
    int numTrees(int n)
    {
        // return recursive(n);
        // vector<int> dp(n + 1, -1);
        // return topDown(n, dp);
        return bottomUp(n);
    }
};