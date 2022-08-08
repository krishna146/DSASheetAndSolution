// Problem Link - https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        if (s.length() < 3)
            return 0;
        int count = 0;
        for (int i = 2; i < s.length(); i++)
        {
            if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i] != s[i - 2])
            {
                count++;
            }
        }
        return count;
    }
};