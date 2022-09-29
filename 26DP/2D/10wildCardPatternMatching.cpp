// Problem Link - https://leetcode.com/problems/wildcard-matching/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool recursive(string &s, string &p, int sIdx, int pIdx)
    {
        if (sIdx >= s.length() && pIdx == p.length())
            return true;
        else if (pIdx == p.length())
            return false;
        bool ans;
        if (sIdx < s.length() && p[pIdx] == '?' || p[pIdx] == s[sIdx])
        {
            ans = recursive(s, p, sIdx + 1, pIdx + 1);
        }
        else if (p[pIdx] == '*')
        {
            for (int temp = sIdx; temp <= s.length(); temp++)
            {
                ans = recursive(s, p, temp, pIdx + 1);
                if (ans)
                    break;
            }
        }
        else
            ans = false;

        return ans;
    }
    bool topDown(string &s, string &p, int sIdx, int pIdx, vector<vector<int>> &dp)
    {
        if (sIdx == s.length() && pIdx == p.length())
            return true;
        else if (pIdx == p.length())
            return false;
        if (dp[sIdx][pIdx] != -1)
            return dp[sIdx][pIdx];
        bool ans;
        if (sIdx < s.length() && p[pIdx] == '?' || p[pIdx] == s[sIdx])
        {
            ans = topDown(s, p, sIdx + 1, pIdx + 1, dp);
        }
        else if (p[pIdx] == '*')
        {
            for (int temp = sIdx; temp <= s.length(); temp++)
            {
                ans = topDown(s, p, temp, pIdx + 1, dp);
                if (ans)
                    break;
            }
        }
        else
            ans = false;

        return dp[sIdx][pIdx] = ans;
    }
    bool bottomUp(string &s, string &p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[s.length()][p.length()] = true;
        for (int sIdx = s.length(); sIdx >= 0; sIdx--)
        {
            for (int pIdx = p.length() - 1; pIdx >= 0; pIdx--)
            {
                bool ans;
                if (sIdx < s.length() && p[pIdx] == '?' || p[pIdx] == s[sIdx])
                {
                    ans = dp[sIdx + 1][pIdx + 1];
                }
                else if (p[pIdx] == '*')
                {
                    for (int temp = sIdx; temp <= s.length(); temp++)
                    {
                        ans = dp[temp][pIdx + 1];
                        if (ans)
                            break;
                    }
                }
                else
                    ans = false;

                dp[sIdx][pIdx] = ans;
            }
        }
        return dp[0][0];
    }

public:
    bool isMatch(string s, string p)
    {
        // return recursive(s, p, 0, 0);
        // vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        // return topDown(s, p, 0, 0, dp);
        return bottomUp(s, p);
    }
};