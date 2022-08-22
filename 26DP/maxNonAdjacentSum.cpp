// Problem Link - https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // calculate the maximum sum with out adjacent
private:
    int recursive(int *arr, int size, int index)
    {
        if (index >= size)
        {
            return 0;
        }
        int included = arr[index] + recursive(arr, size, index + 2);
        int excluded = recursive(arr, size, index + 1);
        return max(included, excluded);
    }
    int topDown(int *arr, int size, int index, int *dp)
    {
        if (index >= size)
        {
            return 0;
        }
        if (dp[index] != -1)
            return dp[index];
        int included = arr[index] + topDown(arr, size, index + 2, dp);
        int excluded = topDown(arr, size, index + 1, dp);
        return dp[index] = max(included, excluded);
    }
    int bottomUp(int *arr, int size)
    {
        int *dp = new int[size + 2];
        dp[size] = 0;
        dp[size + 1] = 0;
        for (int i = 0; i < size; i++)
            dp[i] = -1;
        for (int index = size - 1; index >= 0; index--)
        {
            int included = arr[index] + dp[index + 2];
            int excluded = dp[index + 1];
            dp[index] = max(included, excluded);
        }
        return dp[0];
    }
    int spaceOptimization(int *arr, int size)
    {
        int next1 = 0;
        int next2 = 0;
        int curr;
        for (int index = size - 1; index >= 0; index--)
        {
            int included = arr[index] + next2;
            int excluded = next1;
            curr = max(included, excluded);
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }

public:
    int findMaxSum(int *arr, int n)
    {
        return spaceOptimization(arr, n);
    }
};
