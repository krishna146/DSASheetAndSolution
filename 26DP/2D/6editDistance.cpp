// Problem Link - https://leetcode.com/problems/edit-distance/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int recursive(string &word1, int id1, string &word2, int id2)
    {
        if (id1 == word1.size())
        {
            return word2.size() - id2;
        }
        if (id2 == word2.size())
        {
            return word1.size() - id1;
        }
        if (word1[id1] == word2[id2])
        {
            return recursive(word1, id1 + 1, word2, id2 + 1);
        }
        // insert
        int ans1 = recursive(word1, id1, word2, id2 + 1);
        // delete
        int ans2 = recursive(word1, id1 + 1, word2, id2);
        // replace
        int ans3 = recursive(word1, id1 + 1, word2, id2 + 1);
        return 1 + min(ans1, min(ans2, ans3));
    }
    int topDown(string &word1, int id1, string &word2, int id2, vector<vector<int>> &dp)
    {
        if (id1 == word1.size())
        {
            return word2.size() - id2;
        }
        if (id2 == word2.size())
        {
            return word1.size() - id1;
        }
        if (dp[id1][id2] != -1)
            return dp[id1][id2];
        if (word1[id1] == word2[id2])
        {
            return topDown(word1, id1 + 1, word2, id2 + 1, dp);
        }
        // insert
        int ans1 = topDown(word1, id1, word2, id2 + 1, dp);
        // delete
        int ans2 = topDown(word1, id1 + 1, word2, id2, dp);
        // replace
        int ans3 = topDown(word1, id1 + 1, word2, id2 + 1, dp);
        return dp[id1][id2] = 1 + min(ans1, min(ans2, ans3));
    }
    int bottomUp(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word2.size(); i++)
        {
            dp[word1.size()][i] = word2.size() - i;
        }
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][word2.size()] = word1.size() - i;
        }
        for (int id1 = word1.size() - 1; id1 >= 0; id1--)
        {
            for (int id2 = word2.size() - 1; id2 >= 0; id2--)
            {
                if (word1[id1] == word2[id2])
                {
                    dp[id1][id2] = dp[id1 + 1][id2 + 1];
                }
                else
                {
                    // insert
                    int ans1 = dp[id1][id2 + 1];
                    // delete
                    int ans2 = dp[id1 + 1][id2];
                    // replace
                    int ans3 = dp[id1 + 1][id2 + 1];
                    dp[id1][id2] = 1 + min(ans1, min(ans2, ans3));
                }
            }
        }
        return dp[0][0];
    }
    int spaceOptimization(string word1, string word2)
    {
        vector<int> dp(word2.size() + 1, 0);
        for (int i = 0; i <= word2.length(); i++)
        {
            dp[i] = word2.length() - i;
        }
        for (int id1 = word1.size() - 1; id1 >= 0; id1--)
        {
            int diagonalAns = dp[word2.length()];
            dp[word2.length()] = word1.length() - id1;
            for (int id2 = word2.size() - 1; id2 >= 0; id2--)
            {
                int ans;
                if (word1[id1] == word2[id2])
                {
                    ans = diagonalAns;
                }
                else
                {
                    // insert
                    int ans1 = dp[id2 + 1];
                    // delete
                    int ans2 = dp[id2];
                    // replace
                    int ans3 = diagonalAns;
                    ans = 1 + min(ans1, min(ans2, ans3));
                }
                diagonalAns = dp[id2];
                dp[id2] = ans;
            }
        }
        return dp[0];
    }

public:
    int minDistance(string word1, string word2)
    {
        // return recursive(word1, 0, word2, 0);
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // return topDown(word1, 0, word2, 0, dp);
        // return bottomUp(word1, word2);
        return spaceOptimization(word1, word2);
    }
};