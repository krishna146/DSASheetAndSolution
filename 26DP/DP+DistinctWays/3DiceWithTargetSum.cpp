// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MOD 1e9 + 7
class Solution
{
private:
    int face;
    int recursive(int n, int target)
    {
        if (target == 0 && n == 0)
            return 1;
        if (target == 0 || n == 0)
            return 0;
        int ways = 0;
        for (int num = 1; num <= face; num++)
        {
            if (target - num >= 0)
            {
                ways = (ways + recursive(n - 1, target - num)) % int(MOD);
            }
        }
        return ways;
    }
    int topDown(int n, int target, vector<vector<int>> &dp)
    {
        if (target == 0 && n == 0)
            return 1;
        if (target == 0 || n == 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int ways = 0;
        for (int num = 1; num <= face; num++)
        {
            if (target - num >= 0)
            {
                ways = (ways + topDown(n - 1, target - num, dp)) % int(MOD);
            }
        }
        return dp[n][target] = ways;
    }
    int bottomUp(int noOfDice, int targetSum)
    {
        vector<vector<int>> dp(noOfDice + 1, vector<int>(targetSum + 1, 0));
        dp[0][0] = 1;
        for (int n = 1; n <= noOfDice; n++)
        {
            for (int target = 1; target <= targetSum; target++)
            {
                int ways = 0;
                for (int num = 1; num <= face; num++)
                {
                    if (target - num >= 0)
                    {
                        ways = (ways + dp[n - 1][target - num]) % int(MOD);
                    }
                }
                dp[n][target] = ways;
            }
        }
        return dp[noOfDice][targetSum];
    }
    int spaceOptimized(int noOfDice, int targetSum)
    {
        vector<int> prev(targetSum + 1, 0);
        vector<int> curr(targetSum + 1, 0);
        prev[0] = 1;
        for (int n = 1; n <= noOfDice; n++)
        {
            for (int target = 1; target <= targetSum; target++)
            {
                int ways = 0;
                for (int num = 1; num <= face; num++)
                {
                    if (target - num >= 0)
                    {
                        ways = (ways + prev[target - num]) % int(MOD);
                    }
                }
                curr[target] = ways;
            }
            prev = curr;
        }
        return curr[targetSum];
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        face = k;
        // return recursive(n, target);
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return topDown(n, target, dp);
        // return bottomUp(n, target);
        return spaceOptimized(n, target);
    }
};