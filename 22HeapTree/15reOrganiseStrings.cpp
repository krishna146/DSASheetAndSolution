// Problem Link - https://leetcode.com/problems/reorganize-string/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        int arr[27] = {};
        int max = INT_MIN;
        int maxCharIndex;
        for (auto el : s)
        {
            arr[el - 96]++;
            if (arr[el - 96] > max)
            {
                max = arr[el - 96];
                maxCharIndex = el - 96;
            }
        }
        int index = 0;
        while (arr[maxCharIndex] > 0)
        {
            if (index >= s.size())
                return "";
            s[index] = maxCharIndex + 96;
            index += 2;
            arr[maxCharIndex]--;
        }
        for (int i = 1; i <= 26; i++)
        {
            char ch = i + 96;
            while (arr[i] > 0)
            {
                if (index >= s.size())
                    index = 1;
                s[index] = ch;
                index += 2;
                arr[i]--;
            }
        }
        return s;
    }
};