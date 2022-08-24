// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &days, vector<int> &costs, int index)
    {
        if (index >= days.size())
            return 0;
        int tempIndex;
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 1) - days.begin();
        int first = costs[0] + recursive(days, costs, tempIndex);
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 7) - days.begin();
        int second = costs[1] + recursive(days, costs, tempIndex);
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 30) - days.begin();
        int third = costs[2] + recursive(days, costs, tempIndex);
        return min(first, min(second, third));
    }
    int topDown(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        if (index >= days.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int tempIndex;
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 1) - days.begin();
        int first = costs[0] + topDown(days, costs, tempIndex, dp);
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 7) - days.begin();
        int second = costs[1] + topDown(days, costs, tempIndex, dp);
        tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 30) - days.begin();
        int third = costs[2] + topDown(days, costs, tempIndex, dp);
        return dp[index] = min(first, min(second, third));
    }
    int bottomUp(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            int tempIndex;
            tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 1) - days.begin();
            int first = costs[0] + dp[tempIndex];
            tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 7) - days.begin();
            int second = costs[1] + dp[tempIndex];
            tempIndex = lower_bound(days.begin() + index, days.end(), days[index] + 30) - days.begin();
            int third = costs[2] + dp[tempIndex];
            dp[index] = min(first, min(second, third));
        }
        return dp[0];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // vector<int> dp(days.size(), -1);
        // return topDown(days, costs, 0, dp);
        return bottomUp(days, costs);
    }
};