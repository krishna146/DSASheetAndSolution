// Problem Link - https://leetcode.com/problems/perfect-squares/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(int n)
    {
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        int i = 1;
        while (i * i <= n)
        {
            ans = min(recursive(n - i * i), ans);
            i++;
        }
        return 1 + ans;
    }
    int topDown(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        if (dp[n] != -1)
            return dp[n];
        int i = 1;
        while (i * i <= n)
        {
            ans = min(topDown(n - i * i, dp), ans);
            i++;
        }
        return dp[n] = 1 + ans;
    }
    int bottomUp(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int num = 1; num <= n; num++)
        {
            int ans = INT_MAX;
            int i = 1;
            while (i * i <= num)
            {
                ans = min(dp[num - i * i], ans);
                i++;
            }
            dp[num] = 1 + ans;
        }
        return dp[n];
    }

public:
    int numSquares(int n)
    {
        // return recursive(n);
        // vector<int> dp(n + 1, -1);
        // return topDown(n, dp);
        return bottomUp(n);
    }
};