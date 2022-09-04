// Problem Link - https://leetcode.com/problems/longest-increasing-subsequence/
/* By Krishna Kumar */
// Concept : Dp + binary search
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursion(int currIndex, int prevIndex, vector<int> &arr, int N)
    {
        if (currIndex == N)
        {
            return 0;
        }
        int option1 = 0;
        // include
        if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
        {
            option1 = 1 + recursion(currIndex + 1, currIndex, arr, N);
        }
        // exclude
        int option2 = recursion(currIndex + 1, prevIndex, arr, N);
        return max(option1, option2);
    }

    int topDown(int currIndex, int prevIndex, vector<int> &arr, int N, vector<vector<int>> &dp)
    {
        if (currIndex == N)
        {
            return 0;
        }
        if (dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];
        int option1 = 0;
        // include
        if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
        {
            option1 = 1 + topDown(currIndex + 1, currIndex, arr, N, dp);
        }
        // exclude
        int option2 = topDown(currIndex + 1, prevIndex, arr, N, dp);
        return dp[currIndex][prevIndex + 1] = max(option1, option2);
    }

    int bottomUp(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        for (int currIndex = N - 1; currIndex >= 0; currIndex--)
        {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
            {
                int option1 = 0;
                // include
                if (prevIndex == -1 || arr[currIndex] > arr[prevIndex] == 1)
                {
                    option1 = 1 + dp[currIndex + 1][currIndex + 1];
                }
                // exclude
                int option2 = dp[currIndex + 1][prevIndex + 1];
                dp[currIndex][prevIndex + 1] = max(option1, option2);
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<int> arr, int N)
    {
        vector<int> dp(N + 1, 0);
        for (int currIndex = N - 1; currIndex >= 0; currIndex--)
        {
            vector<int> temp(N + 1, 0);
            for (int prevIndex = currIndex; prevIndex >= -1; prevIndex--)
            {
                int option1 = 0;
                // include
                if (prevIndex == -1 || arr[currIndex] > arr[prevIndex] == 1)
                {
                    option1 = 1 + dp[currIndex + 1];
                }
                // exclude
                int option2 = dp[prevIndex + 1];
                temp[prevIndex + 1] = max(option1, option2);
            }
            dp = temp;
        }
        return dp[0];
    }
    int binarySearchSolution(vector<int> &nums)
    {
        vector<int> dummy;
        dummy.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > dummy.back())
            {
                dummy.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(dummy.begin(), dummy.end(), nums[i]);
                *it = nums[i];
            }
        }
        return dummy.size();
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        // return recursion(0, -1, nums, nums.size());

        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        // return topDown(0, -1, nums, nums.size(), dp);

        // return bottomUp(nums, nums.size());

        return spaceOptimized(nums, nums.size());

        // return binarySearchSolution(nums);
    }
};