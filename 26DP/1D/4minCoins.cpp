// Problem Link - https://leetcode.com/problems/coin-change/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        int ans = INT_MAX;
        for (auto coin : coins)
        {
            int temp = recursive(amount - coin, coins);
            if (temp != -1)
            {
                ans = min(ans, 1 + temp);
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    int topDown(int amount, vector<int> &coins, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (dp[amount] != INT_MIN)
            return dp[amount];
        int ans = INT_MAX;
        for (auto coin : coins)
        {
            int temp = topDown(amount - coin, coins, dp);
            if (temp != -1)
            {
                ans = min(ans, 1 + temp);
            }
        }
        if (ans == INT_MAX)
            return dp[amount] = -1;
        return dp[amount] = ans;
    }
    int bottomUp(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int tempAmount = 1; tempAmount <= amount; tempAmount++)
        {
            int ans = INT_MAX;
            for (auto coin : coins)
            {
                int temp = -1;
                if (tempAmount - coin >= 0)
                    temp = dp[tempAmount - coin];
                if (temp != -1)
                {
                    ans = min(ans, 1 + temp);
                }
            }
            if (ans != INT_MAX)
                dp[tempAmount] = ans;
        }
        return dp[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        return bottomUp(amount, coins);
    }
};