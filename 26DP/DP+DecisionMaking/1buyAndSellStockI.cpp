// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
private:
    int recursive(int start, vector<int> &prices){
        if(start == prices.size()) return 0;
        return max(prices[start], recursive(start + 1, prices));
    }
    int topDown(int start, vector<int> &prices, vector<int> &dp){
        if(start == prices.size()) return 0;
        if(dp[start] != -1) return dp[start];
        return dp[start] = max(prices[start], topDown(start + 1, prices, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        
        //Recursive
        // for(int i = 0 ; i < prices.size() - 1; i++){
        //     int maxi = recursive(i + 1, prices);
        //     profit = max(profit, maxi - prices[i]);
        // }
        
        
        //Top Down
        // vector<int> dp(n, -1);
        // for(int i = 0 ; i < prices.size() - 1; i++){
        //     int maxi = topDown(i + 1, prices, dp);
        //     profit = max(profit, maxi - prices[i]);
        // }
        
        
        // Bottom UP
        // vector<int> dp(n + 1, 0); 
        // for(int start = n - 1 ; start >= 1 ; start--){
        //     dp[start] = max(prices[start], dp[start + 1]);
        // }
        // for(int i = 0 ; i < prices.size() - 1; i++){
        //     int maxi = dp[i + 1];
        //     profit = max(profit, maxi - prices[i]);
        // }

        
        
        //Space Optimized
        int maxTillIdx = prices[n - 1];
        for(int idx = n - 2 ; idx >= 0; idx--){
            profit = max(profit, maxTillIdx - prices[idx]);
            maxTillIdx = max(maxTillIdx, prices[idx]);
        }
        return profit;
    }
};