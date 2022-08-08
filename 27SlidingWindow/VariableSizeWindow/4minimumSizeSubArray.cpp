// Problem Link - https://leetcode.com/problems/minimum-size-subarray-sum/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int currSum = 0;
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        for (right = 0; right < nums.size(); right++)
        {
            currSum += nums[right];
            while (currSum >= target)
            {
                ans = min(right - left + 1, ans);
                currSum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};