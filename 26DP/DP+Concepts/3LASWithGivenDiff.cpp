// Problem Link - https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int ans = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i] - difference;
            dp[arr[i]] = 1 + dp[temp];
            ans = max(dp[arr[i]], ans);
        }
        return ans;
    }
};