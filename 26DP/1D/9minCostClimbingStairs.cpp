// Problem Link - https://leetcode.com/problems/min-cost-climbing-stairs/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &cost, int step)
    {
        if (step == cost.size())
            return 0;
        if (step > cost.size())
            return INT_MAX;
        return cost[step] + min(recursive(cost, step + 1), recursive(cost, step + 2));
    }
    int topDown(vector<int> &cost, int step, vector<int> &dp)
    {
        if (step == cost.size())
            return 0;
        if (step > cost.size())
            return INT_MAX;
        if (dp[step] != INT_MIN)
            return dp[step];
        return dp[step] = cost[step] + min(topDown(cost, step + 1, dp), topDown(cost, step + 2, dp));
    }
    int bottomUp(vector<int> &cost)
    {
        int size = cost.size();
        vector<int> dp(size + 2, INT_MAX);
        dp[size + 1] = INT_MAX;
        dp[size] = 0;
        for (int step = size - 1; step >= 0; step--)
        {
            dp[step] = cost[step] + min(dp[step + 1], dp[step + 2]);
        }
        return min(dp[0], dp[1]);
    }
    int spaceOptimization(vector<int> &cost)
    {
        int size = cost.size();
        int next2 = INT_MAX;
        int next1 = 0;
        int curr;
        for (int step = size - 1; step >= 0; step--)
        {
            curr = cost[step] + min(next1, next2);
            next2 = next1;
            next1 = curr;
        }
        return min(curr, next2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // vector<int> dp(cost.size(), INT_MIN);
        // int indexZeroStart = topDown(cost, 0, dp);
        // int indexOneStart = topDown(cost, 1, dp);
        // return min(indexZeroStart, indexOneStart);
        return spaceOptimization(cost);
    }
};