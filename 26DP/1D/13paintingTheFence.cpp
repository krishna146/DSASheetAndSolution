// Problem Link - https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MOD 1000000007
class Solution
{
private:
    int recursive(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return (k % MOD * k % MOD) % MOD;
        return recursive(n - 1, k) * (k - 1) + recursive(n - 2, k) * (k - 1);
    }
    long long topDown(int n, int k, vector<long long> &dp)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return (k * k) % MOD;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = ((topDown(n - 1, k, dp) * (k - 1)) % MOD + (topDown(n - 2, k, dp) * (k - 1)) % MOD) % MOD;
    }
    long long bottomUp(int num, int k)
    {
        vector<long long> dp(num + 1, -1);
        dp[1] = k;
        dp[2] = (k * k) % MOD;
        for (int n = 3; n <= num; n++)
        {
            dp[n] = ((dp[n - 1] * (k - 1)) % MOD + (dp[n - 2] * (k - 1)) % MOD) % MOD;
        }
        return dp[num];
    }
    long long spaceOptimization(int num, int k)
    {
        if (num == 1)
            return k;
        if (num == 2)
            return (k * k) % MOD;
        long long prev1 = k;
        long long prev2 = (k * k) % MOD;
        long long curr;
        for (int n = 3; n <= num; n++)
        {
            curr = ((prev2 * (k - 1)) % MOD + (prev1 * (k - 1)) % MOD) % MOD;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }

public:
    long long countWays(int n, int k)
    {
        // code here
        // return recursive(n, k);
        // vector<long long> dp(n + 1, -1);
        // return topDown(n, k, dp);
        return spaceOptimization(n, k);
    }
};