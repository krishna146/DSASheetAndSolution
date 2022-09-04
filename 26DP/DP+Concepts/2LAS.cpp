// Problem Link - https://leetcode.com/problems/longest-arithmetic-subsequence/
/* By Krishna Kumar */
// DP + Hashing
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // unordered_map<int, int> *dp = new unordered_map<int, int>[nums.size()];
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(2 * maxi + 1, -1));
        int ans = 2;
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                int diff = nums[i] - nums[j] + maxi;
                if(dp[j][diff] != -1){
                    ans = max(ans, 1 + dp[j][diff]);
                    dp[i][diff] = 1 + dp[j][diff];
                }else{
                    dp[i][diff] = 2;
                }
            }
        }
        return ans;
    }
};