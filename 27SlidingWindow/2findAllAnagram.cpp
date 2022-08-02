// Problem Link - https://leetcode.com/problems/find-all-anagrams-in-a-string/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool isAnagram(int *pCharFreq, int *sWindowCharFreq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (pCharFreq[i] != sWindowCharFreq[i])
                return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        int pSize = p.length();
        int sSize = s.length();
        vector<int> ans;
        if (sSize < pSize)
            return ans;
        int pCharFreq[26] = {};
        int sWindowCharFreq[26] = {};
        for (int i = 0; i < pSize; i++)
        {
            pCharFreq[p[i] - 'a']++;
        }
        for (int i = 0; i < pSize; i++)
        {
            sWindowCharFreq[s[i] - 'a']++;
        }
        if (isAnagram(pCharFreq, sWindowCharFreq))
            ans.push_back(0);
        for (int i = pSize; i < s.length(); i++)
        {
            sWindowCharFreq[s[i - pSize] - 'a']--;
            sWindowCharFreq[s[i] - 'a']++;
            if (isAnagram(pCharFreq, sWindowCharFreq))
                ans.push_back(i - pSize + 1);
        }
        return ans;
    }
};