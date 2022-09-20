// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &prices, int idx, int buy)
    {
        if (idx == prices.size())
            return 0;
        int skipKro = recursive(prices, idx + 1, buy);
        if (buy)
        {
            int buyKro = -prices[idx] + recursive(prices, idx + 1, 0);
            return max(buyKro, skipKro);
        }
        int sellKro = prices[idx] + recursive(prices, idx + 1, 1);
        return max(sellKro, skipKro);
    }
    int topDown(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp)
    {
        if (idx == prices.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int skipKro = topDown(prices, idx + 1, buy, dp);
        if (buy)
        {
            int buyKro = -prices[idx] + topDown(prices, idx + 1, 0, dp);
            return dp[idx][buy] = max(buyKro, skipKro);
        }
        int sellKro = prices[idx] + topDown(prices, idx + 1, 1, dp);
        return dp[idx][buy] = max(sellKro, skipKro);
    }
    int bottomUp(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int skipKro = dp[idx + 1][buy];
                if (buy)
                {
                    int buyKro = -prices[idx] + dp[idx + 1][0];
                    dp[idx][buy] = max(buyKro, skipKro);
                }
                else
                {
                    int sellKro = prices[idx] + dp[idx + 1][1];
                    dp[idx][buy] = max(sellKro, skipKro);
                }
            }
        }
        return dp[0][1];
    }
    int spaceOptimization(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            vector<int> temp(2, 0);
            for (int buy = 1; buy >= 0; buy--)
            {
                int skipKro = dp[buy];
                if (buy)
                {
                    int buyKro = -prices[idx] + dp[0];
                    temp[buy] = max(buyKro, skipKro);
                }
                else
                {
                    int sellKro = prices[idx] + dp[1];
                    temp[buy] = max(sellKro, skipKro);
                }
            }
            dp = temp;
        }
        return dp[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // return recursive(prices, 0, 1);
        //  vector<vector<int>> dp(n, vector<int>(2, -1));
        //  return topDown(prices, 0, 1, dp);
        return spaceOptimization(prices);
    }
};