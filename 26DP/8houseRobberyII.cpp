// Problem Link - https://leetcode.com/problems/house-robber-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &nums, int start, int size)
    {
        if (start >= size)
        {
            return 0;
        }
        int included = nums[start] + recursive(nums, start + 2, size);
        int excluded = recursive(nums, start + 1, size);
        return max(included, excluded);
    }
    int topDown(vector<int> &nums, int start, int size, vector<int> &dp)
    {
        if (start >= size)
        {
            return 0;
        }
        if (dp[start] != -1)
            return dp[start];
        int included = nums[start] + topDown(nums, start + 2, size, dp);
        int excluded = topDown(nums, start + 1, size, dp);
        return dp[start] = max(included, excluded);
    }
    int bottomUp(vector<int> &nums, int index, int size)
    {
        vector<int> dp(size + 3, 0);
        for (int start = size - 1; start >= index; start--)
        {
            int included = nums[start] + dp[start + 2];
            int excluded = dp[start + 1];
            dp[start] = max(included, excluded);
        }
        return dp[index];
    }
    int spaceOptimization(vector<int> &nums, int index, int size)
    {
        int next1 = 0;
        int next2 = 0;
        int curr = 0;
        for (int start = size - 1; start >= index; start--)
        {
            int included = nums[start] + next2;
            int excluded = next1;
            curr = max(included, excluded);
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }

public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        int firstHouseIncluded;
        int firstHouseExcluded;

        // TopDown Answer
        vector<int> dp(size, -1);
        firstHouseIncluded = nums[0] + topDown(nums, 2, size - 1, dp);
        dp.clear();
        dp.resize(size, -1);
        firstHouseExcluded = topDown(nums, 1, size, dp);

        // BottomUp Answer
        firstHouseIncluded = nums[0] + bottomUp(nums, 2, size - 1);
        firstHouseExcluded = bottomUp(nums, 1, size);

        // Space Optimization
        firstHouseIncluded = nums[0] + spaceOptimization(nums, 2, size - 1);
        firstHouseExcluded = spaceOptimization(nums, 1, size);

        return max(firstHouseIncluded, firstHouseExcluded);
    }
};