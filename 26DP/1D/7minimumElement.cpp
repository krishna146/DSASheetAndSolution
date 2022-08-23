// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int countWaysRecursive(vector<int> &nums, int target)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return -1;
    int elementTaken = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int tempElementTaken = countWaysRecursive(nums, target - nums[i]);
        if (tempElementTaken != -1)
        {
            elementTaken = min(tempElementTaken + 1, elementTaken);
        }
    }
    return (elementTaken == INT_MAX) ? -1 : elementTaken;
}
int countWaysTopDown(vector<int> &nums, int target, vector<int> &dp)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return -1;
    if (dp[target] != -1)
        return dp[target];
    int elementTaken = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int tempElementTaken = countWaysTopDown(nums, target - nums[i], dp);
        if (tempElementTaken != -1)
        {
            elementTaken = min(tempElementTaken + 1, elementTaken);
        }
    }
    return dp[target] = (elementTaken == INT_MAX) ? -1 : elementTaken;
}
int countWaysBottomUp(vector<int> &num, int x)
{
    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    for (int target = 1; target <= x; target++)
    {
        int elementTaken = INT_MAX;
        for (int i = 0; i < num.size(); i++)
        {
            int tempElementTaken = -1;
            if (target - num[i] >= 0)
                tempElementTaken = dp[target - num[i]];
            if (tempElementTaken != -1)
            {
                elementTaken = min(tempElementTaken + 1, elementTaken);
            }
        }
        dp[target] = (elementTaken == INT_MAX) ? -1 : elementTaken;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    return countWaysBottomUp(num, x);
}