//Problem Link - https://leetcode.com/problems/partition-equal-subset-sum/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
private:
    bool recursive(vector<int> &nums,int idx, int sum){
        if(sum == 0) return true;
        if(idx == nums.size()) return false;
        return recursive(nums, idx + 1, sum - nums[idx]) || recursive(nums, idx + 1, sum);
    }
    bool topDown(vector<int> &nums,int idx, int sum, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(idx == nums.size()) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool inc = false;
        if(sum - nums[idx] >= 0)
            inc = topDown(nums, idx + 1, sum - nums[idx], dp);
        
        return dp[idx][sum] = inc || topDown(nums, idx + 1, sum, dp);
    }
    bool bottomUp(vector<int> &nums, int target){
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        for(int idx = 0 ; idx <= nums.size() ; idx++){
            dp[idx][0] = true;
        }
        for(int idx = nums.size() - 1 ; idx >= 0 ; idx--){
            for(int sum = 0 ; sum <= target ; sum++){
                bool inc = false;
                if(sum - nums[idx] >= 0)
                    inc = dp[idx + 1][sum - nums[idx]];

                dp[idx][sum] = inc || dp[idx + 1][sum];
            }
        }
        return dp[0][target];
        
    }
    bool spaceOptimized(vector<int> &nums, int target){
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        vector<int> next(target + 1, false);
        vector<int> curr(target + 1);
        next[0] = true;
        for(int idx = nums.size() - 1 ; idx >= 0 ; idx--){
            for(int sum = 0 ; sum <= target ; sum++){
                bool inc = false;
                if(sum - nums[idx] >= 0)
                    inc = next[sum - nums[idx]];

                curr[sum] = inc || next[sum];
            }
            next = curr;
        }
        return next[target];
        
    }
};