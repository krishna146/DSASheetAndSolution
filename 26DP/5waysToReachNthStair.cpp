// Problem Link - https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// Problem Link - https://practice.geeksforgeeks.org/problems/reach-the-nth-point5433/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int topDown(vector<int> &dp, int nStairs, int start)
{
    if (start > nStairs)
        return -1;
    if (start == nStairs)
        return 1;
    if (dp[start] != INT_MIN)
        return dp[start];
    int oneLength = topDown(dp, nStairs, start + 1);
    int twoLength = topDown(dp, nStairs, start + 2);
    if (oneLength == -1 && twoLength == -1)
        return dp[start] = -1;
    else if (oneLength == -1 || twoLength == -1)
    {
        if (oneLength == -1)
            return dp[start] = twoLength;
        if (twoLength == -1)
            return dp[start] = oneLength;
    }
    return dp[start] = (oneLength + twoLength) % 1000000007;
}
int bottomUp(int nStairs)
{
    vector<int> dp(nStairs + 2, -1);
    dp[nStairs] = 1;
    dp[nStairs + 1] = -1;
    for (int stair = nStairs - 1; stair >= 0; stair--)
    {
        int oneLength = dp[stair + 1];
        int twoLength = dp[stair + 2];
        if (oneLength == -1 && twoLength == -1)
            dp[stair] = -1;
        else if (oneLength == -1 || twoLength == -1)
        {
            if (oneLength == -1)
                dp[stair] = twoLength;
            if (twoLength == -1)
                dp[stair] = oneLength;
        }
        else
            dp[stair] = (oneLength + twoLength) % 1000000007;
    }
    return dp[0];
}
int spaceOptimization(int nStairs)
{
    int next1 = 1;
    int next2 = -1;
    int curr;
    for (int stair = nStairs - 1; stair >= 0; stair--)
    {
        int oneLength = next1;
        int twoLength = next2;
        if (oneLength == -1 && twoLength == -1)
            curr = -1;
        else if (oneLength == -1 || twoLength == -1)
        {
            if (oneLength == -1)
                curr = twoLength;
            if (twoLength == -1)
                curr = oneLength;
        }
        else
            curr = (oneLength + twoLength) % 1000000007;
        next2 = next1;
        next1 = curr;
    }
    return curr;
}
int countDistinctWays(int nStairs)
{
    //  Write your code here.

    return bottomUp(nStairs);
}