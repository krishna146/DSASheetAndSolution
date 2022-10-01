// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] > b[0];
        if (a[1] != b[1])
            return a[1] > b[1];
        return a[2] > b[2];
    }

    int recursive(vector<vector<int>> &cuboids, int prevIdx, int currIdx)
    {
        if (currIdx == cuboids.size())
            return 0;
        int incl = 0;
        if (prevIdx == -1 || cuboids[currIdx][1] <= cuboids[prevIdx][1] && cuboids[currIdx][2] <= cuboids[prevIdx][2])
        {
            incl = cuboids[currIdx][0] + recursive(cuboids, currIdx, currIdx + 1);
        }
        int excl = recursive(cuboids, prevIdx, currIdx + 1);
        return max(incl, excl);
    }
    int topDown(vector<vector<int>> &cuboids, int currIdx, int prevIdx, vector<vector<int>> &dp)
    {
        if (currIdx == cuboids.size())
            return 0;
        if (dp[currIdx][prevIdx + 1] != -1)
            return dp[currIdx][prevIdx + 1];
        int incl = 0;
        if (prevIdx == -1 || cuboids[currIdx][1] <= cuboids[prevIdx][1] && cuboids[currIdx][2] <= cuboids[prevIdx][2])
        {
            incl = cuboids[currIdx][0] + topDown(cuboids, currIdx + 1, currIdx, dp);
        }
        int excl = topDown(cuboids, currIdx + 1, prevIdx, dp);
        return dp[currIdx][prevIdx + 1] = max(incl, excl);
    }
    int bottomUp(vector<vector<int>> &cuboids)
    {
        vector<vector<int>> dp(cuboids.size() + 1, vector<int>(cuboids.size() + 1, 0));
        for (int currIdx = cuboids.size() - 1; currIdx >= 0; currIdx--)
        {
            for (int prevIdx = currIdx - 1; prevIdx >= -1; prevIdx--)
            {
                int incl = 0;
                if (prevIdx == -1 || cuboids[currIdx][1] <= cuboids[prevIdx][1] && cuboids[currIdx][2] <= cuboids[prevIdx][2])
                {
                    incl = cuboids[currIdx][0] + dp[currIdx + 1][currIdx + 1];
                }
                int excl = dp[currIdx + 1][prevIdx + 1];
                dp[currIdx][prevIdx + 1] = max(incl, excl);
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<vector<int>> &cuboids)
    {
        vector<int> next(cuboids.size() + 1, 0);
        vector<int> curr(cuboids.size() + 1);
        for (int currIdx = cuboids.size() - 1; currIdx >= 0; currIdx--)
        {
            for (int prevIdx = currIdx - 1; prevIdx >= -1; prevIdx--)
            {
                int incl = 0;
                if (prevIdx == -1 || cuboids[currIdx][1] <= cuboids[prevIdx][1] && cuboids[currIdx][2] <= cuboids[prevIdx][2])
                {
                    incl = cuboids[currIdx][0] + next[currIdx + 1];
                }
                int excl = next[prevIdx + 1];
                curr[prevIdx + 1] = max(incl, excl);
            }
            next = curr;
        }
        return curr[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (int i = 0; i < cuboids.size(); i++)
        {
            sort(cuboids[i].begin(), cuboids[i].end(), greater<int>());
        }
        sort(cuboids.begin(), cuboids.end(), cmp);

        // return recursive(cuboids, -1, 0);
        // vector<vector<int>> dp(cuboids.size() , vector<int>(cuboids.size() + 1, -1));
        // return topDown(cuboids, 0, -1, dp);
        // return bottomUp(cuboids);
        return spaceOptimized(cuboids);
    }
};