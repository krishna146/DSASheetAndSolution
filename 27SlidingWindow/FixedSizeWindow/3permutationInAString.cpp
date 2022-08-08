// Problem Link - https://leetcode.com/problems/permutation-in-string/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool isPermutation(int *s1CharFreq, int *s2WindowCharFreq)
    {
        for (int i = 0; i < 25; i++)
        {
            if (s1CharFreq[i] != s2WindowCharFreq[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return false;
        int s1CharFreq[26] = {};
        int s2WindowCharFreq[26] = {};
        for (int i = 0; i < s1.length(); i++)
        {
            s1CharFreq[s1[i] - 'a']++;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            s2WindowCharFreq[s2[i] - 'a']++;
        }
        if (isPermutation(s1CharFreq, s2WindowCharFreq))
            return true;
        for (int i = s1.length(); i < s2.length(); i++)
        {
            s2WindowCharFreq[s2[i - s1.length()] - 'a']--;
            s2WindowCharFreq[s2[i] - 'a']++;
            if (isPermutation(s1CharFreq, s2WindowCharFreq))
                return true;
        }
        return false;
    }
};