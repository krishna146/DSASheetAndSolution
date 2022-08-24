// Problem Link - https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MOD 1000000007
#include <bits/stdc++.h>
long long int recursive(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return ((n - 1) % MOD * (recursive(n - 1) % MOD + recursive(n - 2) % MOD)) % MOD;
}
long long int topDown(int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = ((n - 1) % MOD * (topDown(n - 1, dp) % MOD + topDown(n - 2, dp) % MOD)) % MOD;
}
long long int bottomUp(int num)
{
    vector<long long int> dp(num + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int n = 3; n <= num; n++)
    {
        dp[n] = ((n - 1) % MOD * (dp[n - 1] % MOD + dp[n - 2] % MOD)) % MOD;
    }
    return dp[num] % MOD;
}
long long int spaceOptimization(int num)
{
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    long long int prev1 = 0;
    long long int prev2 = 1;
    long long int curr;
    for (int n = 3; n <= num; n++)
    {
        curr = ((n - 1) % MOD * (prev1 % MOD + prev2 % MOD)) % MOD;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}
long long int countDerangements(int n)
{
    // Write your code here.
    //     vector<int> dp(n + 1, -1);
    //     return topDown(n, dp);
    return spaceOptimization(n);
}