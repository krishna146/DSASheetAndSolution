// Problem Link - https://leetcode.com/problems/longest-arithmetic-subsequence/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        unordered_map<int, int> *dp = new unordered_map<int, int>[nums.size()];
        int ans = 2;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end())
                {
                    ans = max(ans, 1 + dp[j][diff]);
                    dp[i][diff] = 1 + dp[j][diff];
                }
                else
                {
                    dp[i][diff] = 2;
                }
            }
        }
        return ans;
    }
};