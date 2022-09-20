// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(int idx, int buy, int transCount, vector<int> &prices)
    {
        if (transCount == 0 || idx == prices.size())
            return 0;
        int skipKro = recursive(idx + 1, buy, transCount, prices);
        if (buy)
        {
            int buyKro = -prices[idx] + recursive(idx + 1, 0, transCount, prices);
            return max(skipKro, buyKro);
        }
        int sellKro = prices[idx] + recursive(idx + 1, 1, transCount - 1, prices);
        return max(skipKro, sellKro);
    }
    int topDown(int idx, int buy, int transCount, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (transCount == 0 || idx == prices.size())
            return 0;
        if (dp[idx][buy][transCount] != -1)
            return dp[idx][buy][transCount];
        int skipKro = topDown(idx + 1, buy, transCount, prices, dp);
        if (buy)
        {
            int buyKro = -prices[idx] + topDown(idx + 1, 0, transCount, prices, dp);
            return dp[idx][buy][transCount] = max(skipKro, buyKro);
        }
        int sellKro = prices[idx] + topDown(idx + 1, 1, transCount - 1, prices, dp);
        return dp[idx][buy][transCount] = max(skipKro, sellKro);
    }
    int bottomUp(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                for (int transCount = 1; transCount <= k; transCount++)
                {
                    int skipKro = dp[idx + 1][buy][transCount];
                    if (buy)
                    {
                        int buyKro = -prices[idx] + dp[idx + 1][0][transCount];
                        dp[idx][buy][transCount] = max(skipKro, buyKro);
                    }
                    else
                    {
                        int sellKro = prices[idx] + dp[idx + 1][1][transCount - 1];
                        dp[idx][buy][transCount] = max(skipKro, sellKro);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
    int spaceOptimized(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            vector<vector<int>> curr(2, vector<int>(k + 1, 0));
            for (int buy = 1; buy >= 0; buy--)
            {
                for (int transCount = 1; transCount <= k; transCount++)
                {
                    int skipKro = dp[buy][transCount];
                    if (buy)
                    {
                        int buyKro = -prices[idx] + dp[0][transCount];
                        curr[buy][transCount] = max(skipKro, buyKro);
                    }
                    else
                    {
                        int sellKro = prices[idx] + dp[1][transCount - 1];
                        curr[buy][transCount] = max(skipKro, sellKro);
                    }
                }
            }
            dp = curr;
        }
        return dp[1][k];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // return recursive(0, 1, k, prices);

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, - 1)));
        // return topDown(0, 1, k, prices, dp);
        // return bottomUp(prices, k);
        return spaceOptimized(prices, k);
    }
};