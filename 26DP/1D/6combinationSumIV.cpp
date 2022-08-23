// Problem Link - https://leetcode.com/problems/combination-sum-iv/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int countWaysRecursive(vector<int> &nums, int target)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ways += countWaysRecursive(nums, target - nums[i]);
        }
        return ways;
    }
    int countWaysTopDown(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ways += countWaysTopDown(nums, target - nums[i], dp);
        }
        return dp[target] = ways;
    }
    int countWaysBottomUp(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int tempTarget = 1; tempTarget <= target; tempTarget++)
        {
            int ways = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (tempTarget - nums[i] >= 0)
                    ways += dp[tempTarget - nums[i]];
            }
            dp[tempTarget] = ways;
        }
        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {

        return countWaysBottomUp(nums, target);
    }
};