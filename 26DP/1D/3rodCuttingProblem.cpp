// Problem Link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    // Tc = O(3^n) SC = O(N)
    int recursive(int n, int &x, int &y, int &z)
    {
        if (n < 0)
            return -1;
        if (n == 0)
            return 0;
        int first = recursive(n - x, x, y, z);
        int second = recursive(n - y, x, y, z);
        int third = recursive(n - z, x, y, z);
        if (first != -1 || second != -1 || third != -1)
        {
            return 1 + max(first, max(second, third));
        }
        return -1;
    }
    // Tc = O(N) SC = O(N)
    int topDown(int n, int &x, int &y, int &z, int *dp)
    {
        if (n < 0)
            return -1;
        if (n == 0)
            return 0;
        if (dp[n] != INT_MIN)
            return dp[n];
        int first = topDown(n - x, x, y, z, dp);
        int second = topDown(n - y, x, y, z, dp);
        int third = topDown(n - z, x, y, z, dp);
        if (first != -1 || second != -1 || third != -1)
        {
            return dp[n] = 1 + max(first, max(second, third));
        }
        return dp[n] = -1;
    }
    // Tc = O(N) Sc = O(N)
    int bottomUp(int n, int &x, int &y, int &z)
    {
        int *dp = new int[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int first, second, third;
            if (i - x >= 0)
                first = dp[i - x];
            else
                first = -1;
            if (i - y >= 0)
                second = dp[i - y];
            else
                second = -1;
            if (i - z >= 0)
                third = dp[i - z];
            else
                third = -1;

            if (first != -1 || second != -1 || third != -1)
            {
                dp[i] = 1 + max(first, max(second, third));
            }
            else
                dp[i] = -1;
        }
        if (dp[n] == -1)
            return 0;
        return dp[n];
    }

public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        return bottomUp(n, x, y, z);
    }
};