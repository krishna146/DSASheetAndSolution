// Problem Link - https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &nums1, vector<int> &nums2, int idx, int swapped)
    {
        cout << idx << " " << swapped << endl;
        if (idx == nums1.size())
            return 0;
        int ans = INT_MAX;
        if (idx == 0 || nums1[idx] > nums1[idx - 1] && nums2[idx] > nums2[idx - 1])
        {
            ans = recursive(nums1, nums2, idx + 1, 0);
        }
        if (idx == 0 || nums1[idx] > nums2[idx - 1] && nums2[idx] > nums1[idx - 1])
        {
            swap(nums1[idx], nums2[idx]);
            ans = min(ans, 1 + recursive(nums1, nums2, idx + 1, 1));
            swap(nums1[idx], nums2[idx]);
        }
        return ans;
    }
    int topDown(vector<int> &nums1, vector<int> &nums2, int idx, int swapped, vector<vector<int>> &dp)
    {
        if (idx == nums1.size())
            return 0;
        if (dp[idx][swapped] != -1)
            return dp[idx][swapped];
        int ans = INT_MAX;
        if (idx == 0 || nums1[idx] > nums1[idx - 1] && nums2[idx] > nums2[idx - 1])
        {
            ans = topDown(nums1, nums2, idx + 1, 0, dp);
        }
        if (idx == 0 || nums1[idx] > nums2[idx - 1] && nums2[idx] > nums1[idx - 1])
        {
            swap(nums1[idx], nums2[idx]);
            ans = min(ans, 1 + topDown(nums1, nums2, idx + 1, 1, dp));
            swap(nums1[idx], nums2[idx]);
        }
        return dp[idx][swapped] = ans;
    }
    int bottomUp(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
        for (int idx = nums1.size() - 1; idx >= 0; idx--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                if (swapped)
                {
                    swap(nums1[idx], nums2[idx]);
                }
                if (idx == 0 || nums1[idx] > nums1[idx - 1] && nums2[idx] > nums2[idx - 1])
                {
                    ans = dp[idx + 1][0];
                }
                if (idx == 0 || nums1[idx] > nums2[idx - 1] && nums2[idx] > nums1[idx - 1])
                {
                    ans = min(ans, 1 + dp[idx + 1][1]);
                }
                if (swapped)
                {
                    swap(nums1[idx], nums2[idx]);
                }
                dp[idx][swapped] = ans;
            }
        }
        return dp[0][0];
    }

    int spaceOptimized(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> dp(2, 0);
        for (int idx = nums1.size() - 1; idx >= 0; idx--)
        {
            vector<int> temp(2);
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                if (swapped)
                {
                    swap(nums1[idx], nums2[idx]);
                }
                if (idx == 0 || nums1[idx] > nums1[idx - 1] && nums2[idx] > nums2[idx - 1])
                {
                    ans = dp[0];
                }
                if (idx == 0 || nums1[idx] > nums2[idx - 1] && nums2[idx] > nums1[idx - 1])
                {
                    ans = min(ans, 1 + dp[1]);
                }
                if (swapped)
                {
                    swap(nums1[idx], nums2[idx]);
                }
                temp[swapped] = ans;
            }
            dp = temp;
        }
        return dp[0];
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        int swapped = 0;
        // return recursive(nums1, nums2, 1, swapped);

        // topDown
        //  vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        //  return topDown(nums1, nums2, 0, swapped, dp);

        // Bottom Up
        //  return bottomUp(nums1, nums2);
        return spaceOptimized(nums1, nums2);
    }
};