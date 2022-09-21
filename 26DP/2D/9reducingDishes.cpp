// Problem Link - https://leetcode.com/problems/reducing-dishes/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(vector<int> &satisfaction, int idx, int currDishPrepTime)
    {
        if (idx == satisfaction.size())
            return 0;
        int includeCurrentDish = satisfaction[idx] * currDishPrepTime + recursive(satisfaction, idx + 1, currDishPrepTime + 1);
        int excludeCurrentDish = recursive(satisfaction, idx + 1, currDishPrepTime);
        return max(includeCurrentDish, excludeCurrentDish);
    }
    int topDown(vector<int> &satisfaction, int idx, int currDishPrepTime, vector<vector<int>> &dp)
    {
        if (idx == satisfaction.size())
            return 0;
        if (dp[idx][currDishPrepTime] != INT_MIN)
            return dp[idx][currDishPrepTime];
        int includeCurrentDish = satisfaction[idx] * currDishPrepTime + topDown(satisfaction, idx + 1, currDishPrepTime + 1, dp);
        int excludeCurrentDish = topDown(satisfaction, idx + 1, currDishPrepTime, dp);
        return dp[idx][currDishPrepTime] = max(includeCurrentDish, excludeCurrentDish);
    }
    int bottomUp(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int currDishPrepTime = n; currDishPrepTime >= 1; currDishPrepTime--)
            {
                int includeCurrentDish = satisfaction[idx] * currDishPrepTime + dp[idx + 1][currDishPrepTime + 1];
                int excludeCurrentDish = dp[idx + 1][currDishPrepTime];
                dp[idx][currDishPrepTime] = max(includeCurrentDish, excludeCurrentDish);
            }
        }
        return dp[0][1];
    }
    int spaceOptimized(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<int> next(n + 2, 0);
        vector<int> curr(n + 2, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int currDishPrepTime = n; currDishPrepTime >= 1; currDishPrepTime--)
            {
                int includeCurrentDish = satisfaction[idx] * currDishPrepTime + next[currDishPrepTime + 1];
                int excludeCurrentDish = next[currDishPrepTime];
                curr[currDishPrepTime] = max(includeCurrentDish, excludeCurrentDish);
            }
            next = curr;
        }
        return next[1];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        // return recursive(satisfaction, 0, 1);

        // vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size() + 1, INT_MIN));
        // return topDown(satisfaction, 0, 1, dp);
        // return bottomUp(satisfaction);
        // return spaceOptimized(satisfaction);

        // Most Optimized Approach
        int currSum = 0;
        int prevSum = 0;
        int ans = 0;
        for (int idx = satisfaction.size() - 1; idx >= 0; idx--)
        {
            currSum += prevSum + satisfaction[idx];
            prevSum += satisfaction[idx];
            if (currSum < ans)
                break;
            ans = max(currSum, ans);
        }
        return ans;
    }
};