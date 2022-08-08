// Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        bool charExists[256] = {};
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size())
        {
            char ch = s[right];
            if (!charExists[ch - '\0'])
            {
                charExists[ch - '\0'] = true;
                ans = max(right - left + 1, ans);
            }
            else
            {
                while (s[left] != ch)
                {
                    charExists[s[left] - '\0'] = false;
                    left++;
                }
                left = left + 1;
            }
            right++;
        }
        return ans;
    }
};