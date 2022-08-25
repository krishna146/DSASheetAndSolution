// Problem Link - https://practice.gee/'  ksforgeeks.org/problems/0-1-knapsack-problem0945/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(int capacity, int index, int *wt, int *val, int n)
    {
        if (index == n || capacity == 0)
            return 0;
        int include = 0;
        if (wt[index] <= capacity)
        {
            include = val[index] + recursive(capacity - wt[index], index + 1, wt, val, n);
        }
        int exclude = recursive(capacity, index + 1, wt, val, n);
        return max(include, exclude);
    }
    int topDown(int capacity, int index, int *wt, int *val, int n, vector<vector<int>> &dp)
    {
        if (index == n || capacity == 0)
            return 0;
        int include = 0;
        if (dp[index][capacity] != -1)
            return dp[index][capacity];
        if (wt[index] <= capacity)
        {
            include = val[index] + topDown(capacity - wt[index], index + 1, wt, val, n, dp);
        }
        int exclude = topDown(capacity, index + 1, wt, val, n, dp);
        return dp[index][capacity] = max(include, exclude);
    }
    int bottomUp(int capacity, int *wt, int *val, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int cap = 1; cap <= capacity; cap++)
            {
                int include = 0;
                if (wt[index] <= cap)
                {
                    include = val[index] + dp[index + 1][cap - wt[index]];
                }
                int exclude = dp[index + 1][cap];
                dp[index][cap] = max(include, exclude);
            }
        }
        return dp[0][capacity];
    }
    int sapceOptimized(int capacity, int *wt, int *val, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int cap = 1; cap <= capacity; cap++)
            {
                int include = 0;
                if (wt[index] <= cap)
                {
                    include = val[index] + dp[index + 1][cap - wt[index]];
                }
                int exclude = dp[index + 1][cap];
                dp[index][cap] = max(include, exclude);
            }
        }
        return dp[0][capacity];
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        //   vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        //   return topDown(W, 0, wt, val, n, dp);
        return bottomUp(W, wt, val, n);
    }
};