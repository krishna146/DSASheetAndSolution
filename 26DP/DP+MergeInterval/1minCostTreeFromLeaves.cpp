// Problem Link - https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    pair<int, int> recursive(int left, int right, vector<int> &arr)
    {
        if (left == right)
            return {0, arr[left]};
        pair<int, int> ans = {INT_MAX, 0};
        for (int idx = left; idx < right; idx++)
        {
            pair<int, int> leftInterval = recursive(left, idx, arr);
            pair<int, int> rightInterval = recursive(idx + 1, right, arr);
            pair<int, int> tempAns = {leftInterval.first + rightInterval.first + leftInterval.second * rightInterval.second, max(leftInterval.second, rightInterval.second)};
            if (tempAns.first < ans.first)
            {
                ans = tempAns;
            }
        }
        return ans;
    }
    pair<int, int> topDown(int left, int right, vector<int> &arr, vector<vector<pair<int, int>>> &dp)
    {
        if (left == right)
            return {0, arr[left]};
        if (dp[left][right].first != -1)
            return dp[left][right];
        pair<int, int> ans = {INT_MAX, 0};
        for (int idx = left; idx < right; idx++)
        {
            pair<int, int> leftInterval = topDown(left, idx, arr, dp);
            pair<int, int> rightInterval = topDown(idx + 1, right, arr, dp);
            pair<int, int> tempAns = {leftInterval.first + rightInterval.first + leftInterval.second * rightInterval.second, max(leftInterval.second, rightInterval.second)};
            if (tempAns.first < ans.first)
            {
                ans = tempAns;
            }
        }
        return dp[left][right] = ans;
    }
    pair<int, int> bottomUp(vector<int> &arr)
    {
        int size = arr.size();
        vector<vector<pair<int, int>>> dp(size + 1, vector<pair<int, int>>(size + 1, {-1, -1}));
        for (int left = 0, right = 0; left < size; left++, right++)
        {
            dp[left][right] = {0, arr[left]};
        }
        for (int left = size - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < size; right++)
            {
                pair<int, int> ans = {INT_MAX, 0};
                for (int idx = left; idx < right; idx++)
                {
                    pair<int, int> leftInterval = dp[left][idx];
                    pair<int, int> rightInterval = dp[idx + 1][right];
                    pair<int, int> tempAns = {leftInterval.first + rightInterval.first + leftInterval.second * rightInterval.second, max(leftInterval.second, rightInterval.second)};
                    if (tempAns.first < ans.first)
                    {
                        ans = tempAns;
                    }
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][size - 1];
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        // return recursive(0, arr.size() - 1, arr).first;.

        // int size = arr.size();
        // vector<vector<pair<int, int>>> dp(size, vector<pair<int, int>>(size, {-1, -1}));
        // return topDown(0, arr.size() - 1, arr, dp).first;

        return bottomUp(arr).first;
    }
};