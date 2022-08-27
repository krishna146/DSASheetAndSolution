// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursion(int currIndex, int prevIndex, int *arr, int &N)
    {
        if (currIndex == N)
        {
            return 0;
        }
        int option1 = 0;
        // include
        if (prevIndex == -1 || abs(arr[currIndex] - arr[prevIndex]) == 1)
        {
            option1 = 1 + recursion(currIndex + 1, currIndex, arr, N);
        }
        // exclude
        int option2 = recursion(currIndex + 1, prevIndex, arr, N);
        return max(option1, option2);
    }
    int topDown(int currIndex, int prevIndex, int *arr, int &N, vector<vector<int>> &dp)
    {
        if (currIndex == N)
        {
            return 0;
        }
        if (dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];
        int option1 = 0;
        // include
        if (prevIndex == -1 || abs(arr[currIndex] - arr[prevIndex]) == 1)
        {
            option1 = 1 + topDown(currIndex + 1, currIndex, arr, N, dp);
        }
        // exclude
        int option2 = topDown(currIndex + 1, prevIndex, arr, N, dp);
        return dp[currIndex][prevIndex + 1] = max(option1, option2);
    }
    int bottomUp(int *arr, int &N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        for (int currIndex = N - 1; currIndex >= 0; currIndex--)
        {
            for (int prevIndex = currIndex; prevIndex >= -1; prevIndex--)
            {
                int option1 = 0;
                // include
                if (prevIndex == -1 || abs(arr[currIndex] - arr[prevIndex]) == 1)
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
    int spaceOptimized(int *arr, int N)
    {
        vector<int> dp(N + 1, 0);
        for (int currIndex = N - 1; currIndex >= 0; currIndex--)
        {
            vector<int> temp(N + 1, 0);
            for (int prevIndex = currIndex; prevIndex >= -1; prevIndex--)
            {
                int option1 = 0;
                // include
                if (prevIndex == -1 || abs(arr[currIndex] - arr[prevIndex]) == 1)
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

public:
    int longestSubsequence(int N, int A[])
    {
        // return recursion(0, -1, A, N);
        // vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        // return topDown(0, -1, A, N, dp);
        // return bottomUp(A, N);
        return spaceOptimized(A, N);
    }
};